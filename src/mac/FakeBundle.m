#import "FakeBundle.h"

@implementation NSBundle(swizle)

-(NSString*) __bundleIdentifier {
    if (self == [NSBundle mainBundle]) {
        return @"com.apple.terminal";
    } else {
        return [self __bundleIdentifier];
    }
}

@end

@implementation FakeBundle

+(BOOL) installNSBundleHook {
    Class clazz = objc_getClass("NSBundle");
    if (clazz) {
        method_exchangeImplementations(class_getInstanceMethod(clazz, @selector(bundleIdentifier)),
                                       class_getInstanceMethod(clazz, @selector(__bundleIdentifier)));
        return YES;
    }
	return NO;
}

@end