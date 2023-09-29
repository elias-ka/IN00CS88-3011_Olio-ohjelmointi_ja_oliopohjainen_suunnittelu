#ifndef KOTITEHTAVA5_KERROSTALO_HPP
#define KOTITEHTAVA5_KERROSTALO_HPP

#include <memory>

#include "katutaso.hpp"
#include "kerros.hpp"

class Kerrostalo {
public:
  Kerrostalo();

  auto laske_kulutus(double hinta) const -> double;

private:
  std::unique_ptr<Katutaso> eka_{};
  std::unique_ptr<Kerros> toka_{};
  std::unique_ptr<Kerros> kolmas_{};
};

#endif  // KOTITEHTAVA5_KERROSTALO_HPP
