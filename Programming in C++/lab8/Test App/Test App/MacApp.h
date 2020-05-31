//
//  MacApp.h
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#ifndef MacApp_h
#define MacApp_h

#import <Cocoa/Cocoa.h>
#import "CubeAPI.hpp"
#import <memory>

@interface MacApp : NSWindow<NSApplicationDelegate> {
    std::shared_ptr<cubeAPI> appInstance;
}
@property (nonatomic, retain) NSOpenGLView* glView;
-(void) drawLoop:(NSTimer*) timer;
@end

#endif /* MacApp_h */
