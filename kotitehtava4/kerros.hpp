#ifndef KOTITEHTAVA4_KERROS_HPP
#define KOTITEHTAVA4_KERROS_HPP

#include <cstddef>
#include <iostream>

#include "asunto.hpp"

struct Kerros {
  Asunto as1{};
  Asunto as2{};
  Asunto as3{};
  Asunto as4{};

  Kerros() { std::cout << "Kerros luotu\n"; }
  virtual ~Kerros() = default;

  virtual auto maarita_asunnot() -> void;

  virtual auto laske_kulutus(double hinta) const -> double;
};

#endif  // KOTITEHTAVA4_KERROS_HPP
