////////////////////////////////////////////////////////////////////////////////
// PackageStatus.cpp
//
// class PackageStatus
////////////////////////////////////////////////////////////////////////////////

// TODO: You may add additional #includes here if you wish.
// Before submitting your assignment, delete all TODO comments
// including this one.

#include "PackageStatus.h"
#include <exception>
#include <list>

namespace PackageTracking {

  PackageStatus::PackageStatus() noexcept { }

  PackageStatus::PackageStatus(const std::string& tracking_number) noexcept
  : tracking_number_(tracking_number){ }

  const std::string& PackageStatus::TrackingNumber() const noexcept {
    return tracking_number_;
  }

  int PackageStatus::Size() const noexcept {
    return updates_.size();
  }

  bool PackageStatus::Empty() const noexcept {
    return updates_.empty();
  }

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
  void PackageStatus::AddUpdate(const std::string& description,
				const std::string& location,
				std::time_t timestamp) {
    ShippingUpdate new_element(description, location, timestamp);
    if (updates_.empty()) {
      updates_.push_front(new_element);
      cursor_ = updates_.begin();
    } else {
      std::list<ShippingUpdate>::iterator it4 = updates_.end();
      if (new_element.Timestamp() >= it4->Timestamp()) {
//      if (difftime(new_element.Timestamp(), it4->Timestamp()) >= 0) {
//      if (timestamp - it4->Timestamp() >= 0) {
        updates_.push_back(new_element);
      } else { throw std::invalid_argument("Given timestamp is invalid."); }
//      if (new_element.Timestamp() < it4->Timestamp()) {  throw std::invalid_argument("Given timestamp is invalid."); }
    }
    // if (!updates_.empty()) {
    //   std::list<ShippingUpdate>::iterator it4 = updates_.end();
    //   if (timestamp >= it4->Timestamp()) {
    //     updates_.push_back(new_element);
    //   } else { throw std::invalid_argument("Given timestamp is invalid."); }
    // } else {
    //   updates_.push_back(new_element);
    //   cursor_ = updates_.begin();
    // }
  }

      // Attempt to move the cursor backward one step.
      //
      // If the PackageStatus is empty, or the cursor is already
      // pointing to the first update, this has no effect and returns
      // false. Otherwise, this moves the cursor one step backwards and
      // returns true.
  bool PackageStatus::MoveCursorBackward() noexcept {
    if(updates_.empty()) {
      return false;
    }
    if (cursor_ == updates_.begin()) {
      return false;
    } else {
      cursor_--;
      return true;
    }
  }

      // Attempt to move the cursor forward one step.
      //
      // If the PackageStatus is empty, or the cursor is already
      // pointing to the last update, this has no effect and returns
      // false. Otherwise, this moves the cursor one step forward and
      // returns true.
  bool PackageStatus::MoveCursorForward() noexcept {
    if (updates_.empty()) {
      return false;
    }

    if (cursor_ == --updates_.end()) {
      return false;
    } else{
      cursor_++;
      return true;
    }
  }

      // Return a reference to the ShippingUpdate object that the cursor
      // is pointing at. The PackageStatus must not be empty.
      //
      // If the PackageStatus is empty, throws std::logic_error.
  const ShippingUpdate& PackageStatus::GetCursor() const {
    if (updates_.empty()) {
      throw std::logic_error("PackageStatus is empty.");
    } else {
      return *cursor_;
    }
  }

      // Return a description of the ShippingUpdate object that the
      // cursor is pointing at, following the same format as
      // ShippingUpdate::Describe. The PackageStatus must not be empty.
      //
      // If the PackageStatus is empty, throws std::logic_error.
  std::string PackageStatus::DescribeCursorUpdate() {
    return cursor_->Describe();
  }

      // Return a description of all ShippingUpdates prior to the cursor
      // (so not including the cursor update). Each update's description
      // follows the format of ShippingUpdate::Describe. The description
      // strings are concatenated together in chronological order. The
      // PackageStatus must not be empty.
      //
      // If the PackageStatus is empty, throws std::logic_error.
  std::string PackageStatus::DescribePreviousUpdates() {
    std::string previous_updates;
    if (updates_.empty()) {
      throw std::logic_error("PackageStatus is empty.");
    } else {
      for (std::list<ShippingUpdate>::iterator it = updates_.begin(); it != cursor_; it++ ) {
        previous_updates += it->Describe();
      }
    }
    return previous_updates;
  }

      // Return a description of all ShippingUpdates, starting at the
      // cursor, and including all later updates. Each update's
      // description follows the format of ShippingUpdate::Describe. The
      // description strings are concatenated together in chronological
      // order. The PackageStatus must not be empty.
      //
      // If the PackageStatus is empty, throws std::logic_error.
  std::string PackageStatus::DescribeFollowingUpdates() {
    std::string following_updates;
    if (updates_.empty()) {
      throw std::logic_error("PackageStatus is empty.");
    } else {
      for (std::list<ShippingUpdate>::iterator it2 = cursor_; it2 != updates_.end(); it2++ ) {
        following_updates += it2->Describe();
      }
    }
    return following_updates;
  }

      // Return a description of all ShippingUpdates. Each update's
      // description follows the format of ShippingUpdate::Describe. The
      // description strings are concatenated together in chronological
      // order.
      //
      // The PackageStatus *may* be empty. If so, this function returns
      // an empty string.
  std::string PackageStatus::DescribeAllUpdates() {
    std::string all_updates;
    for (std::list<ShippingUpdate>::iterator it3 = updates_.begin(); it3 != updates_.end(); it3++ ) {
      all_updates += it3->Describe();
    }
    return all_updates;
  }

}
