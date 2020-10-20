////////////////////////////////////////////////////////////////////////////////
// ShippingUpdate.cpp
//
// class ShippingUpdate
////////////////////////////////////////////////////////////////////////////////

#include "ShippingUpdate.h"
#include <string>

namespace PackageTracking {

  ShippingUpdate::ShippingUpdate() noexcept
  : timestamp_(0) { }

  ShippingUpdate::ShippingUpdate(const std::string& description,
				 const std::string& location,
				 std::time_t timestamp) noexcept
         : description_(description), location_(location), timestamp_(timestamp)
          { }

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
    std::string describe = std::to_string(timestamp_) + " " + description_ + " " + location_ + "\n";
    return describe;

  }

}
