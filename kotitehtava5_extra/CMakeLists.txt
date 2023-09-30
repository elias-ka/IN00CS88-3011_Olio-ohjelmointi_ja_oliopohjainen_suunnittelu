add_executable(
  kotitehtava5_extra
  main.cpp
  device.hpp
  mouse.hpp
  touchpad.hpp
  display.hpp
  ui.hpp
  ui.cpp)
target_compile_features(kotitehtava5_extra PRIVATE cxx_std_23)
