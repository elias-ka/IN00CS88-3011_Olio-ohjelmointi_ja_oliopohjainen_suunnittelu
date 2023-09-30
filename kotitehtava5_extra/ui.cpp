#include <cstdint>
#include <iostream>

#include "ui.hpp"

auto Ui::show_menu() -> void {
  std::cout << "DEVICE MENU\n"
            << "===========\n"
            << "1) Set Mouse Information\n"
            << "2) Set Touchpad Information\n"
            << "3) Set Display Information\n"
            << "4) Show Devices Information\n"
            << "5) Finish\n\n"
            << "Choose: ";
}

auto Ui::loop() -> void {
  while (true) {
    show_menu();
    int choice = 0;
    std::cin >> choice;

    switch (choice) {
      case 1:
        set_mouse_info();
        break;
      case 2:
        set_touchpad_info();
        break;
      case 3:
        set_display_info();
        break;
      case 4:
        show_device_info();
        break;
      case 5:
        return;
      default:
        std::cout << "Invalid choice!\n";
        break;
    }
  }
}

auto Ui::set_mouse_info() -> void {
  std::cout << "\nSET MOUSE INFORMATION\n"
            << "====================\n"
            << "Set Mouse Device ID: ";

  mouse_->set_device_id();

  std::cout << "Set Mouse Primary Button: ";
  mouse_->set_primary_button();
}

auto Ui::set_touchpad_info() -> void {
  std::cout << "\nSET TOUCHPAD INFORMATION\n"
            << "=======================\n"
            << "Set Touchpad Device ID: ";

  touchpad_->set_device_id();

  std::cout << "Set Touchpad Sensitivity: ";
  touchpad_->set_sensitivity();
}

auto Ui::set_display_info() -> void {
  std::cout << "\nSET DISPLAY INFORMATION\n"
            << "======================\n"
            << "Set Display Device ID: ";

  display_->set_device_id();

  std::cout << "Set Display Resolution: ";
  display_->set_resolution();
}

auto Ui::show_device_info() -> void {
  std::cout << "\nDEVICE INFORMATION\n"
            << "====================\n"
            << "Mouse Device ID: " << mouse_->get_device_id()
            << "\nMouse Primary Button: " << mouse_->get_primary_button()
            << "\nTouchpad Device ID: " << touchpad_->get_device_id()
            << "\nTouchpad Sensitivity: " << touchpad_->get_sensitivity()
            << "\nDisplay Device ID: " << display_->get_device_id()
            << "\nDisplay Resolution: " << display_->get_resolution() << '\n';
}
