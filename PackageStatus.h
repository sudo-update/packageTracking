////////////////////////////////////////////////////////////////////////////////
// PackageStatus.h
//
// class PackageStatus
////////////////////////////////////////////////////////////////////////////////

#ifndef PACKAGE_STATUS_H
#define PACKAGE_STATUS_H

#include <stdexcept> // std::invalid_argument, std::logic_error
#include <string> // std::string

// TODO: You may add additional #includes here if you wish.
// Before submitting your assignment, delete all TODO comments
// including this one.

#include "ShippingUpdate.h"

namespace PackageTracking {

  // PackageStatus represents the entire sequence of events of
  // shipping one parcel.
  //
  // It has the tracking number like "1Z4310X3YW25357495", and a list
  // of ShippingUpdate objects, in chronological order
  // (oldest-to-newest).
  //
  // PackageStatus also has a concept of a *cursor* that points to one
  // particular update. When there are no updates, the cursor location
  // is undefined. When the first update is added, the cursor points
  // to that first update. When there are multiple updates, the cursor
  // can move forward and backward through the update list.
  class PackageStatus {
  public:

    // Default constructor: initialize with an empty-string tracking
    // number, and an empty list of updates.
    PackageStatus() noexcept;

    // Initialization constructor: initialize with the given tracking
    // number, and an empty list of updates.
    PackageStatus(const std::string& tracking_number) noexcept;

    // Accessors
    const std::string& TrackingNumber() const noexcept;

    // Size and emptiness. These refer to the number of updates.
    int Size() const noexcept;
    bool Empty() const noexcept;

    // Add an update with the given description, location, and
    // timestamp.
    //
    // Updates must follow chronological order. So if this
    // PackageStatus is not empty, the given timestamp must be greater
    // than or equal to the timestamp of the last update. (Equal
    // timestamps are allowed because mail-handling equipment sometimes
    // generates two events in the same second.)
    //
    // When the first update is added, the cursor is moved to point at
    // that new update.
    //
    // Throws std::invalid_argument if the given timestamp is invalid.
    void AddUpdate(const std::string& description,
		   const std::string& location,
		   std::time_t timestamp);

    // Attempt to move the cursor backward one step.
    //
    // If the PackageStatus is empty, or the cursor is already
    // pointing to the first update, this has no effect and returns
    // false. Otherwise, this moves the cursor one step backwards and
    // returns true.
    bool MoveCursorBackward() noexcept;

    // Attempt to move the cursor forward one step.
    //
    // If the PackageStatus is empty, or the cursor is already
    // pointing to the last update, this has no effect and returns
    // false. Otherwise, this moves the cursor one step forward and
    // returns true.
    bool MoveCursorForward() noexcept;

    // Return a reference to the ShippingUpdate object that the cursor
    // is pointing at. The PackageStatus must not be empty.
    //
    // If the PackageStatus is empty, throws std::logic_error.
    const ShippingUpdate& GetCursor() const;

    // Return a description of the ShippingUpdate object that the
    // cursor is pointing at, following the same format as
    // ShippingUpdate::Describe. The PackageStatus must not be empty.
    //
    // If the PackageStatus is empty, throws std::logic_error.
    std::string DescribeCursorUpdate();
    
    // Return a description of all ShippingUpdates prior to the cursor
    // (so not including the cursor update). Each update's description
    // follows the format of ShippingUpdate::Describe. The description
    // strings are concatenated together in chronological order. The
    // PackageStatus must not be empty.
    //
    // If the PackageStatus is empty, throws std::logic_error.
    std::string DescribePreviousUpdates();

    // Return a description of all ShippingUpdates, starting at the
    // cursor, and including all later updates. Each update's
    // description follows the format of ShippingUpdate::Describe. The
    // description strings are concatenated together in chronological
    // order. The PackageStatus must not be empty.
    //
    // If the PackageStatus is empty, throws std::logic_error.
    std::string DescribeFollowingUpdates();

    // Return a description of all ShippingUpdates. Each update's
    // description follows the format of ShippingUpdate::Describe. The
    // description strings are concatenated together in chronological
    // order.
    //
    // The PackageStatus *may* be empty. If so, this function returns
    // an empty string.
    std::string DescribeAllUpdates();
    
  private:
    // TODO: Add data members here.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    std::string tracking_number_;
  };
  
}

#endif
