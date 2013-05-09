#import <Foundation/Foundation.h>
#import <objc/runtime.h>

@interface FakeBundle : NSObject

+(BOOL) installNSBundleHook;

@end
