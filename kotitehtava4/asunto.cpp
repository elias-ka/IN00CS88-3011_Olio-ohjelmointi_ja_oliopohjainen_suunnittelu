#include <iostream>

#include "asunto.hpp"

Asunto::Asunto() {
  std::cout << "Asunto luotu\n";
}

auto Asunto::maarita(int asukas_maara, int neliot) -> void {
  this->asukas_maara = asukas_maara;
  this->neliot = neliot;
  std::cout << "Asunto määritetty asukkaita = " << asukas_maara
            << " neliöitä = " << neliot << "\n";
}

auto Asunto::laske_kulutus(double hinta) const -> double {
  return neliot * asukas_maara * hinta;
}
