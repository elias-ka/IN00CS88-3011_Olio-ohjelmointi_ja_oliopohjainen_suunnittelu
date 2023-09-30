#ifndef KOTITEHTAVA5_EXTRA_UI_HPP
#define KOTITEHTAVA5_EXTRA_UI_HPP

#include <memory>

#include "display.hpp"
#include "mouse.hpp"
#include "touchpad.hpp"

class Ui {
public:
  Ui()
      : mouse_{std::make_unique<Mouse>()}
      , touchpad_{std::make_unique<TouchPad>()}
      , display_{std::make_unique<Display>()} {};

  auto loop() -> void;
  auto show_menu() const -> void;
  auto show_device_info() const -> void;

  auto set_mouse_info() -> void;
  auto set_touchpad_info() -> void;
  auto set_display_info() -> void;

private:
  std::unique_ptr<Mouse> mouse_;
  std::unique_ptr<TouchPad> touchpad_;
  std::unique_ptr<Display> display_;
};

#endif  // KOTITEHTAVA5_EXTRA_UI_HPP
