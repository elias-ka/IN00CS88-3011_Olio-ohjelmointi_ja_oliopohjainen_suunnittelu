#include <iostream>

#include "kerrostalo.hpp"

Kerrostalo::Kerrostalo() {
  std::cout << "Kerrostalo luotu\n";
  std::cout << "Määritellään koko kerrostalon kaikki asunnot\n";
  eka_.maarita_asunnot();

  std::cout << "Määritellään katutason kerrokselta perittyjä asuntoja\n";
  toka_.maarita_asunnot();

  kolmas_.maarita_asunnot();
}

auto Kerrostalo::laske_kulutus(double hinta) const -> double {
  double kulutus = 0;
  kulutus += eka_.laske_kulutus(hinta);
  kulutus += toka_.laske_kulutus(hinta);
  kulutus += kolmas_.laske_kulutus(hinta);
  return kulutus;
}
