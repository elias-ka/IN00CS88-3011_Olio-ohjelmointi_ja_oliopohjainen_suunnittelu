#ifndef KOTITEHTAVA5_KATUTASO_HPP
#define KOTITEHTAVA5_KATUTASO_HPP

#include <iostream>
#include <memory>

#include "kerros.hpp"

struct Katutaso : public Kerros {
  std::unique_ptr<Asunto> as1{};
  std::unique_ptr<Asunto> as2{};

  Katutaso() { std::cout << "Katutaso luotu\n"; }

  auto maarita_asunnot() -> void override;
  auto laske_kulutus(double hinta) const -> double override;
};

#endif  // KOTITEHTAVA5_KATUTASO_HPP
