#ifndef KOTITEHTAVA5_EXTRA_DEVICE_HPP
#define KOTITEHTAVA5_EXTRA_DEVICE_HPP

#include <cstdint>
#include <iostream>

class Device {
public:
  auto set_device_id() -> void { std::cin >> device_id_; }

  [[nodiscard]] auto get_device_id() const -> std::int16_t {
    return device_id_;
  }

protected:
  std::int16_t device_id_{};
};

#endif  // KOTITEHTAVA5_EXTRA_DEVICE_HPP
