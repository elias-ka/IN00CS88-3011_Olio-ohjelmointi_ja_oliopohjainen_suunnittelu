#include <iostream>

#include "kerros.hpp"

auto Kerros::maarita_asunnot() -> void {
  std::cout << "Määritellään 4 kpl kerroksen asuntoja\n";
  as1.maarita(2, 100);
  as2.maarita(2, 100);
  as3.maarita(2, 100);
  as4.maarita(2, 100);
};

auto Kerros::laske_kulutus(double hinta) const -> double {
  double kulutus = 0;
  kulutus += as1.laske_kulutus(hinta);
  kulutus += as2.laske_kulutus(hinta);
  kulutus += as3.laske_kulutus(hinta);
  kulutus += as4.laske_kulutus(hinta);
  return kulutus;
}
