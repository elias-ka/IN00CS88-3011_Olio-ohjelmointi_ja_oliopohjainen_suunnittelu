#ifndef KOTITEHTAVA5_EXTRA_TOUCHPAD_HPP
#define KOTITEHTAVA5_EXTRA_TOUCHPAD_HPP

#include <iostream>

#include "device.hpp"

class TouchPad : public Device {
public:
  auto set_sensitivity() -> void { std::cin >> sensitivity_; }

  [[nodiscard]] auto get_sensitivity() const -> std::int16_t {
    return sensitivity_;
  }

private:
  std::int16_t sensitivity_{};
};

#endif  // KOTITEHTAVA5_EXTRA_TOUCHPAD_HPP
