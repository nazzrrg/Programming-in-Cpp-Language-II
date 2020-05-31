//
//  cubeView.h
//  Rubick's Cube 1.0 by nazzrrg
//
//  Created by Егор Назаров on 24.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <QuartzCore/CVDisplayLink.h>
#import "CubeAPI.hpp"

@interface cubeViewObj : NSOpenGLView {
    CVDisplayLinkRef displayLink;
    cubeAPI* appInstance;
    int selectedSide;
    int selectedDirection;
    bool shouldTurn;
    NSPoint startPoint;
    NSPoint endPoint;
    BOOL needsUpdate;
    int iter;
    int delayValue;
    int shouldSolve;
    bool canShuffle;
}
@end
