#import <Cocoa/Cocoa.h>
#import <notification.h>

#import "FakeBundle.h"

@interface NotificationCenterDelegate : NSObject<NSUserNotificationCenterDelegate> @end

@implementation NotificationCenterDelegate

-(void) userNotificationCenter:(NSUserNotificationCenter*) center didActivateNotification:(NSUserNotification*) notification {
    [center removeDeliveredNotification:notification];
}

@end

bool Notification::show(string msg) {
    NSString* text = [[NSString alloc] initWithUTF8String:msg.c_str()];

    @autoreleasepool {
        if (![FakeBundle installNSBundleHook]) return NO;
        NSUserNotificationCenter* nc = [NSUserNotificationCenter defaultUserNotificationCenter];
        NotificationCenterDelegate* ncDelegate = [[NotificationCenterDelegate alloc] init];
        nc.delegate = ncDelegate;
        NSUserNotification *note = [[NSUserNotification alloc] init];
        note.hasActionButton = NO;
        note.title = @"Notification";
        note.informativeText = text;
        [nc deliverNotification: note];
        [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow: 1]];
    }

    return YES;
}