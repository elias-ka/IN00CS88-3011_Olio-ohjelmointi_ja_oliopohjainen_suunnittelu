cmake_minimum_required(VERSION 3.16)
project(viikkotehtavat)

add_executable(kotitehtava1 main.cpp)
target_compile_features(kotitehtava1 PRIVATE cxx_std_23)