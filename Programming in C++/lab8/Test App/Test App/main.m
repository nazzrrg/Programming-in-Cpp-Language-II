//
//  main.m
//  Test App
//
//  Created by Егор Назаров on 23.05.2020.
//  Copyright © 2020 Егор Назаров. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MacApp.h"

NSApplication* ns_app;

int main(int argc, const char * argv[]) {
    MacApp* app;
    ns_app = [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular]; 
    //create a window with the size of 800 by 600
    app = [[MacApp alloc] initWithContentRect:NSMakeRect(0, 0, 800, 600)              styleMask:NSTitledWindowMask | NSClosableWindowMask |  NSMiniaturizableWindowMask   backing:NSBackingStoreBuffered defer:YES];
    [ns_app setDelegate:app];
    [ns_app run];
}
