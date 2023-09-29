#ifndef KOTITEHTAVA5_KERROS_HPP
#define KOTITEHTAVA5_KERROS_HPP

#include <cstddef>
#include <iostream>
#include <memory>

#include "asunto.hpp"

struct Kerros {
  std::unique_ptr<Asunto> as1{};
  std::unique_ptr<Asunto> as2{};
  std::unique_ptr<Asunto> as3{};
  std::unique_ptr<Asunto> as4{};

  Kerros() { std::cout << "Kerros luotu\n"; }
  virtual ~Kerros() = default;

  virtual auto maarita_asunnot() -> void;

  virtual auto laske_kulutus(double hinta) const -> double;
};

#endif  // KOTITEHTAVA5_KERROS_HPP
