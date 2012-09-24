
/*==============================================================================
            Copyright (c) 2012 QUALCOMM Austria Research Center GmbH.
            All Rights Reserved.
            Qualcomm Confidential and Proprietary
			
@file 
    TrackerManager.h

@brief
    Header file for TrackerManager class.

==============================================================================*/
#ifndef _QCAR_TRACKER_MANAGER_H_
#define _QCAR_TRACKER_MANAGER_H_

// Include files
#include <QCAR/Tracker.h>

namespace QCAR
{

/// TrackerManager class.
/**
 *  The TrackerManager singleton provides methods for accessing the trackers
 *  available in QCAR as well as initializing specific trackers required by the
 *  application. See the Tracker base class for a list of available tracker
 *  types.
 */
class QCAR_API TrackerManager
{
public:
    /// Returns the TrackerManager singleton instance.
    static TrackerManager& getInstance();

    /// Initializes the tracker of the given type
    /**
     *  Initializing a tracker must not be done when the CameraDevice
     *  is initialized or started. This function will return NULL if the
     *  tracker of the given type has already been initialized or if the
     *  CameraDevice is currently initialized.
     */
    virtual Tracker* initTracker(Tracker::TYPE type) = 0;

    /// Returns the instance of the given tracker type
    /**
     *  See the Tracker base class for a list of available tracker classes.
     *  This function will return NULL if the tracker of the given type has
     *  not been initialized.
     */
    virtual Tracker* getTracker(Tracker::TYPE type) = 0;

    /// Deinitializes the tracker of the given type
    /**
     *  Deinitializes the tracker of the given type and frees any resources
     *  used by the tracker.
     *  Deinitializing a tracker must not be done when the CameraDevice
     *  is initialized or started. This function will return false if the
     *  tracker of the given type has not been initialized or if the
     *  CameraDevice is currently initialized.
     */
    virtual bool deinitTracker(Tracker::TYPE type) = 0;
};

} // namespace QCAR

#endif //_QCAR_TRACKER_MANAGER_H_
