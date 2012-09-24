/*==============================================================================
 Copyright (c) 2012 QUALCOMM Austria Research Center GmbH.
 All Rights Reserved.
 Qualcomm Confidential and Proprietary
 ==============================================================================*/
/*
 
 The QCAR sample apps are organised to work with standard iOS view
 controller life cycles.
 
 * QCARutils contains all the code that initialises and manages the QCAR
 lifecycle plus some useful functions for accessing targets etc. This is a
 singleton class that makes QCAR accessible from anywhere within the app.
 
 * AR_EAGLView is a superclass that contains the OpenGL setup for its
 sub-class, EAGLView.
 
 Other classes and view hierarchy exists to establish a robust view life
 cycle:
 
 * ARParentViewController provides a root view for inclusion in other view
 hierarchies  presentModalViewController can present this VC safely. All
 associated views are included within it; it also handles the auto-rotate
 and resizing of the sub-views.
 
 * ARViewController manages the lifecycle of the Camera and Augmentations,
 calling QCAR:createAR, QCAR:destroyAR, QCAR:pauseAR and QCAR:resumeAR
 where required. It also manages the data for the view, such as loading
 textures.
 
 This configuration has been shown to work for iOS Modal and Tabbed views.
 It provides a model for re-usability where you want to produce a
 number of applications sharing code.
 
 --------------------------------------------------------------------------------*/


#import "ImageTargetsAppDelegate.h"
#import "ARParentViewController.h"
#import "QCARutils.h"

@implementation ImageTargetsAppDelegate

//static BOOL firstTime = YES;

// test to see if the screen has hi-res mode
- (BOOL) isRetinaEnabled
{
    return ([[UIScreen mainScreen] respondsToSelector:@selector(displayLinkWithTarget:selector:)]
            &&
            ([UIScreen mainScreen].scale == 2.0));
}

// Setup a continuation of the splash screen until the camera is initialised
//- (void) setupSplashContinuation
//{
//    CGRect screenBounds = [[UIScreen mainScreen] bounds];
//    
//    // first get the splash screen continuation in place
//    NSString *splashImageName = @"Default.png";
//    if (screenBounds.size.width == 768)
//        splashImageName = @"Default-Portrait~ipad.png";
//    else if ((screenBounds.size.width == 320) && [self isRetinaEnabled])
//        splashImageName = @"Default@2x.png";
//    
//    UIImage *image = [UIImage imageNamed:splashImageName];
//    splashV = [[UIImageView alloc] initWithImage:image];
//    splashV.frame = screenBounds;
//    [window addSubview:splashV];
//
//    // poll to see if the camera video stream has started and if so remove the splash screen.
//    [NSTimer scheduledTimerWithTimeInterval:0.2 target:self selector:@selector(removeSplash:) userInfo:nil repeats:YES];
//}


// this is the application entry point
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    return YES;
}


//- (void) removeSplash:(NSTimer *)theTimer
//{
//    // poll to see if the camera video stream has started and if so remove the splash screen.
//    if ([QCARutils getInstance].videoStreamStarted == YES)
//    {
//        [splashV removeFromSuperview];
//        [theTimer invalidate];
//    }
//}


- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // don't do this straight after startup - the view controller will do it
//    if (firstTime == NO)
//    {
//        // do the same as when the view is shown
//        [arParentViewController viewDidAppear:NO];
//    }
//    
//    firstTime = NO;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // do the same as when the view has dissappeared
//    [arParentViewController viewDidDisappear:NO];
}


- (void)applicationWillTerminate:(UIApplication *)application
{
    // AR-specific actions
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Handle any background procedures not related to animation here.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Handle any foreground procedures not related to animation here.
}


@end
