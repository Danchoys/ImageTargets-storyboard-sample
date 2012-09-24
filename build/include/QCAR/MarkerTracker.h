/*==============================================================================
            Copyright (c) 2012 QUALCOMM Austria Research Center GmbH.
            All Rights Reserved.
            Qualcomm Confidential and Proprietary
			
@file 
    MarkerTracker.h

@brief
    Header file for MarkerTracker class.

==============================================================================*/
#ifndef _QCAR_MARKER_TRACKER_H_
#define _QCAR_MARKER_TRACKER_H_

// Include files
#include <QCAR/Tracker.h>
#include <QCAR/Vectors.h>

namespace QCAR
{

// Forward Declaration
class Marker;

/// MarkerTracker class.
/**
 *  The MarkerTracker tracks rectangular markers and provides methods for
 *  creating and destroying these dynamically.
 *  Note that the methods for creating and destroying markers should not be
 *  called while the MarkerTracker is working at the same time. Doing so will
 *  make these methods block and wait until the MarkerTracker has finished.
 *  The suggested way of doing this is during the execution of UpdateCallback,
 *  which guarantees that the MarkerTracker is not working concurrently.
 *  Alternatively the MarkerTracker can be stopped explicitly.
 */
class QCAR_API MarkerTracker : public Tracker
{
public:

    /// Creates a new Marker
    /**
     *  Creates a new marker of the given name, size and id. Returns the new
     *  instance on success, NULL otherwise.
     */   
    virtual Marker* createFrameMarker(int markerId, const char* name,
                                    const QCAR::Vec2F& size) = 0;

    /// Destroys a Marker 
    virtual bool destroyMarker(Marker* marker) = 0;

    /// Returns the total number of Markers that have been created.
    virtual int getNumMarkers() const = 0;

    /// Returns a pointer to a Marker object
    virtual Marker* getMarker(int idx) const = 0;
};

} // namespace QCAR

#endif //_QCAR_MARKER_TRACKER_H_
