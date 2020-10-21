////////////////////////////////////////////////////////////////////////////////
// PackageStatus.cpp
//
// class PackageStatus
////////////////////////////////////////////////////////////////////////////////

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

  void PackageStatus::AddUpdate(const std::string& description,
				const std::string& location,
				std::time_t timestamp) {
    ShippingUpdate new_element(description, location, timestamp);
    if (updates_.empty()) {
      updates_.push_front(new_element);
      cursor_ = updates_.begin();
    } else {
      std::list<ShippingUpdate>::iterator last_update = --updates_.end();
      if (new_element.Timestamp() >= last_update->Timestamp()) {
        updates_.push_back(new_element);
      } else { throw std::invalid_argument("Given timestamp is invalid."); }
    }
  }

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

  const ShippingUpdate& PackageStatus::GetCursor() const {
    if (updates_.empty()) {
      throw std::logic_error("PackageStatus is empty.");
    } else {
      return *cursor_;
    }
  }

  std::string PackageStatus::DescribeCursorUpdate() {
    return cursor_->Describe();
  }

  std::string PackageStatus::DescribePreviousUpdates() {
    std::string previous_updates;
    if (updates_.empty()) {
      throw std::logic_error("PackageStatus is empty.");
    } else {
      for (std::list<ShippingUpdate>::iterator prev_updates = updates_.begin();
           prev_updates != cursor_; prev_updates++ ) {
             previous_updates += prev_updates->Describe();
           }
    }
    return previous_updates;
  }

  std::string PackageStatus::DescribeFollowingUpdates() {
    std::string following_updates;
    if (updates_.empty()) {
      throw std::logic_error("PackageStatus is empty.");
    } else {
      for (std::list<ShippingUpdate>::iterator follow_updates = cursor_;
           follow_updates != updates_.end(); follow_updates++ ) {
             following_updates += follow_updates->Describe();
           }
    }
    return following_updates;
  }

  std::string PackageStatus::DescribeAllUpdates() {
    std::string all_updates;
    for (std::list<ShippingUpdate>::iterator every_update = updates_.begin();
         every_update != updates_.end(); every_update++ ) {
           all_updates += every_update->Describe();
         }
    return all_updates;
  }

}
