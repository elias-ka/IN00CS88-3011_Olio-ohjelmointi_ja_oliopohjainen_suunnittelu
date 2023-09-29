#include <memory>

#include "kerrostalo.hpp"

auto main() -> int {
  auto kerrostalo = std::make_unique<Kerrostalo>();
  double kulutus = kerrostalo->laske_kulutus(1);
  std::cout << "Kerrostalon kulutus = " << kulutus << '\n';
}
