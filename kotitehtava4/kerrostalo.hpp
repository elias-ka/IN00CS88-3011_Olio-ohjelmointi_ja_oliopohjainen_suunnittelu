#ifndef KOTITEHTAVA4_KERROSTALO_HPP
#define KOTITEHTAVA4_KERROSTALO_HPP

#include "katutaso.hpp"
#include "kerros.hpp"

class Kerrostalo {
public:
  Kerrostalo();

  auto laske_kulutus(double hinta) const -> double;

private:
  Katutaso eka_;
  Kerros toka_;
  Kerros kolmas_;
};

#endif  // KOTITEHTAVA4_KERROSTALO_HPP
