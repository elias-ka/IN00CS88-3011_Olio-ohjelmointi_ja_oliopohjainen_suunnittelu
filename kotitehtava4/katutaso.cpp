#include <iostream>

#include "katutaso.hpp"

auto Katutaso::maarita_asunnot() -> void {
  std::cout << "Määritellään 2 kpl katutason asuntoja\n";
  as1.maarita(2, 100);
  as2.maarita(2, 100);
}

auto Katutaso::laske_kulutus(double hinta) const -> double {
  double kulutus = 0;
  kulutus += as1.laske_kulutus(hinta);
  kulutus += as2.laske_kulutus(hinta);
  return kulutus;
}
