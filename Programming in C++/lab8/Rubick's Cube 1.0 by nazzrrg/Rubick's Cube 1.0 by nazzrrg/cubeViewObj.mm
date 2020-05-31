//
//  cubeView.m
//  Rubick's Cube 1.0 by nazzrrg
//
//  Created by Егор Назаров on 24.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#import "cubeViewObj.h"
#import <QuartzCore/CVDisplayLink.h>
#import "CubeAPI.hpp"
#include <chrono>
#include <thread>
#include <stack>

@implementation cubeViewObj

-(CVReturn) getFrameForTime:(const CVTimeStamp*)outputTime
{
    // There is no autorelease pool when this method is called
    // because it will be called from a background thread.
    // It's important to create one or app can leak objects.
    @autoreleasepool {
        [self drawView];
    }
    return kCVReturnSuccess;
}

// This is the renderer output callback function
static CVReturn MyDisplayLinkCallback(CVDisplayLinkRef displayLink,
                                      const CVTimeStamp* now,
                                      const CVTimeStamp* outputTime,
                                      CVOptionFlags flagsIn,
                                      CVOptionFlags* flagsOut,
                                      void* displayLinkContext)
{
    CVReturn result = [(__bridge cubeViewObj*)displayLinkContext getFrameForTime:outputTime];
    return result;
}


-(id)initWithFrame:(NSRect)frameRect {
    self = [super initWithFrame:frameRect];
    if (self) {
        shouldTurn = false;
        selectedSide = 0;
        selectedDirection = 0;
        needsUpdate = YES;
        iter = 0;
        delayValue = 100;
        shouldSolve = 0;
        canShuffle = true;
    }
    return self;
}


- (void)awakeFromNib
{
    NSOpenGLPixelFormatAttribute attrs[] =
        {
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFADepthSize, 24,
            NSOpenGLPFAOpenGLProfile,
            NSOpenGLProfileVersion3_2Core,
            0
        };
    
    NSOpenGLPixelFormat *pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
    
    if (!pf)
    {
        NSLog(@"No OpenGL pixel format");
    }
       
    NSOpenGLContext* context = [[NSOpenGLContext alloc] initWithFormat:pf shareContext:nil];
    
//#if ESSENTIAL_GL_PRACTICES_SUPPORT_GL3 && defined(DEBUG)
//    // When we're using a CoreProfile context, crash if we call a legacy OpenGL function
//    // This will make it much more obvious where and when such a function call is made so
//    // that we can remove such calls.
//    // Without this we'd simply get GL_INVALID_OPERATION error for calling legacy functions
//    // but it would be more difficult to see where that function was called.
//    CGLEnable([context CGLContextObj], kCGLCECrashOnRemovedFunctions);
//#endif
    
    [self setPixelFormat:pf];
    
    [self setOpenGLContext:context];
    
//#if SUPPORT_RETINA_RESOLUTION
    // Opt-In to Retina resolution
    [self setWantsBestResolutionOpenGLSurface:YES];
//#endif // SUPPORT_RETINA_RESOLUTION
}

- (void) prepareOpenGL {
    [super prepareOpenGL];
    
    // Make all the OpenGL calls to setup rendering
    //  and build the necessary rendering objects
    [self initGL];
    
    // Create a display link capable of being used with all active displays
    CVDisplayLinkCreateWithActiveCGDisplays(&displayLink);
    
    // Set the renderer output callback function
    CVDisplayLinkSetOutputCallback(displayLink, &MyDisplayLinkCallback, (__bridge void*)self);
    
    // Set the display link for the current renderer
    CGLContextObj cglContext = [[self openGLContext] CGLContextObj];
    CGLPixelFormatObj cglPixelFormat = [[self pixelFormat] CGLPixelFormatObj];
    CVDisplayLinkSetCurrentCGDisplayFromOpenGLContext(displayLink, cglContext, cglPixelFormat);
    
    // Activate the display link
    CVDisplayLinkStart(displayLink);
    
    // Register to be notified when the window closes so we can stop the displaylink
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(windowWillClose:)
                                                 name:NSWindowWillCloseNotification
                                               object:[self window]];
}

- (void) windowWillClose:(NSNotification*)notification
{
    // Stop the display link when the window is closing because default
    // OpenGL render buffers will be destroyed.  If display link continues to
    // fire without renderbuffers, OpenGL draw calls will set errors.
    
    CVDisplayLinkStop(displayLink);
}

-(void) initGL
{
    // The reshape function may have changed the thread to which our OpenGL
    // context is attached before prepareOpenGL and initGL are called.  So call
    // makeCurrentContext to ensure that our OpenGL context current to this
    // thread (i.e. makeCurrentContext directs all OpenGL calls on this thread
    // to [self openGLContext])
    [[self openGLContext] makeCurrentContext];
    
    // Synchronize buffer swaps with vertical refresh rate
    GLint swapInt = 1;
    [[self openGLContext] setValues:&swapInt forParameter:NSOpenGLCPSwapInterval];

    appInstance = new cubeAPI(800, 600);
//    appInstance->shuffle();
//    appInstance->saveFile("file.txt");
//    appInstance->solve();
//    iter = 0;
//    iter = appInstance->controllerInstance.moooves.size();
}

-(BOOL)acceptsFirstResponder {
    return YES;
}

-(void) keyDown:(NSEvent *)event {
    NSString* input = [[NSString alloc]initWithString:[event characters]];
//    NSLog([event characters], input);
    if ([input isEqualToString:@"1"]) {
//        std::cout << "Event cought 1" << std::endl;
        selectedSide = 1;
    } else if ([input isEqualToString:@"2"]) {
//        std::cout << "Event cought 2" << std::endl;
        selectedSide = 2;
    } else if ([input isEqualToString:@"3"]) {
//        std::cout << "Event cought 3" << std::endl;
        selectedSide = 3;
    } else if ([input isEqualToString:@"4"]) {
//        std::cout << "Event cought 4" << std::endl;
        selectedSide = 4;
    } else if ([input isEqualToString:@"5"]) {
//        std::cout << "Event cought 5" << std::endl;
        selectedSide = 5;
    } else if ([input isEqualToString:@"0"]) {
    //        std::cout << "Event cought 5" << std::endl;
        appInstance->shuffle();
        selectedSide=0;
    } else if ([input isEqualToString:@"6"]) {
//        std::cout << "Event cought 6" << std::endl;
        selectedSide = 6;
    } else if ([input isEqualToString:@"q"]||[input isEqualToString:@"Q"]) { //CCw
//        std::cout << "Event cought q" << std::endl;
        selectedDirection = 2;
    } else if ([input isEqualToString:@"e"]||[input isEqualToString:@"E"]) {//Cw
//        std::cout << "Event cought e" << std::endl;
        selectedDirection = 1;
    } else if ([input isEqualToString:@"r"]||[input isEqualToString:@"R"]) {//Cw
    //        std::cout << "Event cought e" << std::endl;
        appInstance->reset();
    } else if ([input isEqualToString:@"k"]||[input isEqualToString:@"K"]) {//Save
        std::cout << "Please enter file path to SAVE: " << std::endl;
        std::string inputFilePath;
        std::getline(std::cin, inputFilePath);
        appInstance->saveFile(inputFilePath);
    }  else if ([input isEqualToString:@"l"]||[input isEqualToString:@"L"]) {//Load
        std::cout << "Please enter file path to LOAD: " << std::endl;
        std::string loadFilePath;
        std::getline(std::cin, loadFilePath);
        appInstance->loadFile(loadFilePath);
//        shouldSolve = 2;
        
    } else if ([input isEqualToString:@"s"]||[input isEqualToString:@"S"]) { // Solve
//        if (shouldSolve == 0) {
//            appInstance->solve();
//            shouldSolve = 1;
//            iter = 0;
//        } else if (shouldSolve == 2) {
        appInstance->controllerInstance.moooves.clear();
        shouldSolve = 1;
//        }
    } else if ([input isEqualToString:@"f"]||[input isEqualToString:@"F"]) { // Check

        appInstance->check();
    } else if ([input isEqualToString:@"a"]||[input isEqualToString:@"A"]) { // Solve
        shouldSolve = 2;
    }else if ([input isEqualToString:@"d"]||[input isEqualToString:@"D"]) { // Shuffle
        appInstance->shuffle();
        shouldSolve = 0;
    } else if ([input isEqualToString:@" "]) {
        if (selectedSide > 0 && selectedSide < 7) {
            shouldTurn = true;
        }
//        shouldSolve=1;
    } else {
        selectedSide = 0;
        selectedDirection = 0;
        shouldTurn = false;
    }
    needsUpdate = YES;
}

-(void)mouseDown:(NSEvent *)event {
    startPoint = [event locationInWindow];
//    std::cout << startPoint.x << ' ' << startPoint.y << std::endl;
}

-(void)mouseDragged:(NSEvent *)event {
    endPoint = [event locationInWindow];
    appInstance->moveCamera(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    needsUpdate = YES;
//    std::cout << endPoint.x << ' ' << endPoint.y << std::endl;
}
-(void)scrollWheel:(NSEvent *)event {
    GLfloat delta = [event deltaY];
    appInstance->zoomCamera(delta);
    needsUpdate = YES;
//    std::cout << "scrolll " << delta << std::endl;
}

-(void)reshape
{
    [super reshape];
    
    // We draw on a secondary thread through the display link. However, when
    // resizing the view, -drawRect is called on the main thread.
    // Add a mutex around to avoid the threads accessing the context
    // simultaneously when resizing.
    CGLLockContext([[self openGLContext] CGLContextObj]);

    // Get the view size in Points
    NSRect viewRectPoints = [self bounds];

    NSRect viewRectPixels = [self convertRectToBacking:viewRectPoints];
    
    appInstance->resizeViewWindow(viewRectPixels.size.width, viewRectPixels.size.height);
    CGLUnlockContext([[self openGLContext] CGLContextObj]);
}

-(void)renewGState {

    [[self window] disableScreenUpdatesUntilFlush];

    [super renewGState];
}

-(void) drawRect:(NSRect) theRect
{
    [self drawView];
}

- (void) drawView
{
    [[self openGLContext] makeCurrentContext];

    // We draw on a secondary thread through the display link
    // When resizing the view, -reshape is called automatically on the main
    // thread. Add a mutex around to avoid the threads accessing the context
    // simultaneously when resizing
    
    if (shouldTurn) {
        appInstance->rotateSide(selectedSide, selectedDirection);
        shouldTurn=false;
    }
    CGLLockContext([[self openGLContext] CGLContextObj]);
    if (shouldSolve==1) {
        if (!appInstance->controllerInstance.solved && iter<appInstance->controllerInstance.moooves.size()) {
            switch (appInstance->controllerInstance.moooves[iter]) {
                case 'R':
                    appInstance->rotateSide(5, 1);
                    break;
                case 'r':
                    appInstance->rotateSide(5, 2);
                    break;
                case 'W':
                    appInstance->rotateSide(1, 1);
                    break;
                case 'w':
                    appInstance->rotateSide(1, 2);
                    break;
                case 'G':
                    appInstance->rotateSide(4, 1);
                    break;
                case 'g':
                    appInstance->rotateSide(4, 2);
                    break;
                case 'B':
                    appInstance->rotateSide(2, 1);
                    break;
                case 'b':
                    appInstance->rotateSide(2, 2);
                    break;
                case 'O':
                    appInstance->rotateSide(3, 1);
                    break;
                case 'o':
                    appInstance->rotateSide(3, 2);
                    break;
                case 'Y':
                    appInstance->rotateSide(6, 1);
                    break;
                case 'y':
                    appInstance->rotateSide(6, 2);
                    break;
                default:
                    break;
            }
            iter++;
        } else if (iter>=appInstance->controllerInstance.moooves.size()) {
            appInstance->solve();
            iter = 0;
        } else if (appInstance->controllerInstance.solved) {
            appInstance->controllerInstance.solverReset();
            appInstance->rotateSide(6, 1);
            shouldSolve=0;
        }
    }
    
    appInstance->update();
    needsUpdate = NO;
    std::this_thread::sleep_for(std::chrono::milliseconds(delayValue));
    CGLFlushDrawable([[self openGLContext] CGLContextObj]);
    CGLUnlockContext([[self openGLContext] CGLContextObj]);
}

- (void)dealloc
{
    // Stop the display link BEFORE releasing anything in the view
    // otherwise the display link thread may call into the view and crash
    // when it encounters something that has been release
    CVDisplayLinkStop(displayLink);
    CVDisplayLinkRelease(displayLink);
}


@end
