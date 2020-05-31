//
//  cubeWindowController.m
//  Rubick's Cube 1.0 by nazzrrg
//
//  Created by Егор Назаров on 24.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#import "cubeWindowController.h"
#import "cubeViewObj.h"

@interface cubeWindowController () {
    // Fullscreen window
//    GLEssentialsFullscreenWindow *_fullscreenWindow;

    // Non-Fullscreen window (also the initial window)
    NSWindow* _standardWindow;
}
@end

@implementation cubeWindowController

- (instancetype)initWithWindow:(NSWindow *)window
{
    self = [super initWithWindow:window];

    return self;
}


-(void)windowDidLoad {
    [super windowDidLoad];
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

@end
