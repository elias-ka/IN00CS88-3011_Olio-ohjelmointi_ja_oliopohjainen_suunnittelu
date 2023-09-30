#ifndef KOTITEHTAVA5_EXTRA_DISPLAY_HPP
#define KOTITEHTAVA5_EXTRA_DISPLAY_HPP

#include "device.hpp"

class Display : public Device {
public:
  auto set_resolution() -> void { std::cin >> resolution_; }

  [[nodiscard]] auto get_resolution() const -> std::int16_t {
    return resolution_;
  }

private:
  std::int16_t resolution_{};
};

#endif  // KOTITEHTAVA5_EXTRA_DISPLAY_HPP
