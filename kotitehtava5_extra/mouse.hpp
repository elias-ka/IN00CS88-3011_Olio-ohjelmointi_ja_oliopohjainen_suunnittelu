#ifndef KOTITEHTAVA5_EXTRA_MOUSE_HPP
#define KOTITEHTAVA5_EXTRA_MOUSE_HPP

#include <iostream>

#include "device.hpp"

class Mouse : public Device {
public:
  auto set_primary_button() -> void { std::cin >> primary_button_; }

  [[nodiscard]] auto get_primary_button() const -> std::int16_t {
    return primary_button_;
  }

private:
  std::int16_t primary_button_{};
};

#endif  // KOTITEHTAVA5_EXTRA_MOUSE_HPP
