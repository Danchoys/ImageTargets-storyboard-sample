/*==============================================================================
            Copyright (c) 2012 QUALCOMM Austria Research Center GmbH.
            All Rights Reserved.
            Qualcomm Confidential and Proprietary

@file
    UIGLViewProtocol.h
 
@brief
    <b>iOS:</b> Header file for the iOS-specific UIGLViewProtocol protocol.

==============================================================================*/
#ifndef _UIGLVIEWPROTOCOL_H_
#define _UIGLVIEWPROTOCOL_H_

/**
 <b>iOS:</b> This protocol applies only to the iOS platform.<BR>
 <BR>
 UIGLViewProtocol protocol.  The apps's UIView-derived class may conform to
 UIGLViewProtocol to allow QCAR to call the renderFrameQCAR method when it
 wishes to render the current frame.  This is an informal protocol.  The
 view hierarchy is traversed asking each node whether it respondsToSelector
 renderFrameQCAR.  Note: if more than one view in the hierarchy responds to this
 selector then only one will be chosen, and it is undefined which that will be.
 If no view that responds to renderFrameQCAR is found, then the application
 is responsible for scheduling its own rendering.
 */
@protocol UIGLViewProtocol
/// <b>iOS:</b> Called by QCAR to render the current frame
- (void)renderFrameQCAR;
@end

#endif // _UIGLVIEWPROTOCOL_H_
