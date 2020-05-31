//
//  AppDelegate.h
//  Rubick's Cube 1.0 by nazzrrg
//
//  Created by Егор Назаров on 24.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#import <Cocoa/Cocoa.h>
//#import <memory>
//#import "Application.hpp"

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
//    std::shared_ptr<Application> appInstance;
}
- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)theApplication;

@end

