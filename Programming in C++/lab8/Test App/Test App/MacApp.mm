//
//  MacApp.m
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#import "MacApp.h"

@implementation MacApp

@synthesize glView;

BOOL shouldStop = NO;

-(id)initWithContentRect:(NSRect)contentRect styleMask:(NSUInteger)aStyle backing:(NSBackingStoreType)bufferingType defer:(BOOL)flag{
    if(self = [super initWithContentRect:contentRect styleMask:aStyle backing:bufferingType defer:flag]){
        //sets the title of the window (Declared in Plist)
        [self setTitle:[[NSProcessInfo processInfo] processName]];
 
        //This is pretty important.. OS X starts always with a context that only supports openGL 2.1
        //This will ditch the classic OpenGL and initialises openGL 4.1
        NSOpenGLPixelFormatAttribute attrs[] =
            {
                NSOpenGLPFADoubleBuffer,
                NSOpenGLPFADepthSize, 24,
                NSOpenGLPFAColorSize, 24,
                NSOpenGLPFAAlphaSize, 8,
                NSOpenGLPFAOpenGLProfile,
                NSOpenGLProfileVersion3_2Core,
                0
            };
        
        //Initialize the view
        NSOpenGLPixelFormat *pf = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
        
        if (!pf)
        {
            NSLog(@"No OpenGL pixel format");
        }
        
        glView = [[NSOpenGLView alloc]initWithFrame:contentRect pixelFormat:pf];
    
        //Set context and attach it to the window
        [[glView openGLContext]makeCurrentContext];
  
        //finishing off
        [self setContentView:glView];
        [glView prepareOpenGL];
        [self makeKeyAndOrderFront:self];
        [self setAcceptsMouseMovedEvents:YES];
        [self makeKeyWindow];
        [self setOpaque:YES];

        //Start the c++ code
        appInstance = std::shared_ptr<cubeAPI>(new cubeAPI());
    }
    return self;
}



-(void) drawLoop:(NSTimer*) timer{

    if(shouldStop){
        [self close];
        return;
    }
    if([self isVisible]){
        appInstance->update();
        [glView update];
        [[glView openGLContext] flushBuffer];
    }
}

//-(void) 

-(void)applicationDidFinishLaunching:(NSNotification *)notification {
    [NSTimer scheduledTimerWithTimeInterval:0.000001 target:self selector:@selector(drawLoop:) userInfo:nil repeats:YES];
}

-(BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication{
    return YES;
}

-(void)applicationWillTerminate:(NSNotification *)aNotification{
    shouldStop = YES;
}

@end
