#ifndef KOTITEHTAVA4_ASUNTO_HPP
#define KOTITEHTAVA4_ASUNTO_HPP

struct Asunto {
  int asukas_maara;
  int neliot;

  Asunto();

  auto maarita(int asukas_maara, int neliot) -> void;
  auto laske_kulutus(double hinta) const -> double;
};

#endif  // KOTITEHTAVA4_ASUNTO_HPP
