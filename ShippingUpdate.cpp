////////////////////////////////////////////////////////////////////////////////
// ShippingUpdate.cpp
//
// class ShippingUpdate
////////////////////////////////////////////////////////////////////////////////

#include "ShippingUpdate.h"

namespace PackageTracking {

  ShippingUpdate::ShippingUpdate() noexcept
  : timestamp_(0) { }

  ShippingUpdate::ShippingUpdate(const std::string& description,
				 const std::string& location,
				 std::time_t timestamp) noexcept
         : description_(description), location_(location), timestamp_(timestamp) {
    // TODO: Implement this function.
    // Before submitting your assignment, delete all TODO comments
    // including this one.
  }

  const std::string& ShippingUpdate::Description() const noexcept {
    return description_;
  }

  const std::string& ShippingUpdate::Location() const noexcept {
    return location_;
  }

  time_t ShippingUpdate::Timestamp() const noexcept {
    return timestamp_;
  }
  std::string ShippingUpdate::Describe() const noexcept {
    // TODO: Implement this function, including the return statement.
    // Before submitting your assignment, delete all TODO comments
    // including this one.

    //i made this you have to put timestamp_ in the describe
    std::string describe = " " + description_ + " " + location_ + "\n";
    return describe;

  }

}
