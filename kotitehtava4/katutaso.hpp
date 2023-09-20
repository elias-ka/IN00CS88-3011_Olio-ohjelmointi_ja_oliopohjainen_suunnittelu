#ifndef KOTITEHTAVA4_KATUTASO_HPP
#define KOTITEHTAVA4_KATUTASO_HPP

#include <iostream>

#include "kerros.hpp"

struct Katutaso : public Kerros {
  Asunto as1;
  Asunto as2;

  Katutaso() { std::cout << "Katutaso luotu\n"; }

  auto maarita_asunnot() -> void override;
  auto laske_kulutus(double hinta) const -> double override;
};

#endif  // KOTITEHTAVA4_KATUTASO_HPP
