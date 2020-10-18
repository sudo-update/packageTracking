////////////////////////////////////////////////////////////////////////////////
// PackageStatus.cpp
//
// class PackageStatus
////////////////////////////////////////////////////////////////////////////////

// TODO: You may add additional #includes here if you wish.
// Before submitting your assignment, delete all TODO comments
// including this one.

#include "PackageStatus.h"

namespace PackageTracking {

  PackageStatus::PackageStatus() noexcept {
    // TODO: Depending on the data members you choose, you may need to
    // add code to this constructor.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
  }

  PackageStatus::PackageStatus(const std::string& tracking_number) noexcept
  : tracking_number_(tracking_number) {
    // TODO: Implement this function.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
  }

  const std::string& PackageStatus::TrackingNumber() const noexcept {
    return tracking_number_;
  }

  int PackageStatus::Size() const noexcept {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.

    return 0;
  }

  bool PackageStatus::Empty() const noexcept {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    if(size_.empty()){
    return false;
  }
  }

  void PackageStatus::AddUpdate(const std::string& description,
				const std::string& location,
				std::time_t timestamp) {
    // TODO: Implement this function.
    // Before submitting your assignment, delete all TODO comments
    // including this one.

  }

  bool PackageStatus::MoveCursorBackward() noexcept {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    if(size_ <= 0){
      return false;
    }
    else{
      return true;
    }
  }

  bool PackageStatus::MoveCursorForward() noexcept {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    if(size_ <= 0 /*or if movecursorbackward was true*/ ){
    return false;
    }
    else{
      return true;
    }
  }

  const ShippingUpdate& PackageStatus::GetCursor() const {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    if(size_.empty()){
    throw std::logic_error("not implemented");
    }
    return //where the cursor is at;
  }

  std::string PackageStatus::DescribeCursorUpdate() {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    return "";
  }

  std::string PackageStatus::DescribePreviousUpdates() {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    return "";
  }

  std::string PackageStatus::DescribeFollowingUpdates() {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    return "";
  }

  std::string PackageStatus::DescribeAllUpdates() {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
    return "";
  }

}
