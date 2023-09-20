#include "kerrostalo.hpp"

auto main() -> int {
  Kerrostalo kerrostalo{};
  double kulutus = kerrostalo.laske_kulutus(1);
  std::cout << "Kerrostalon kulutus = " << kulutus << '\n';
}
