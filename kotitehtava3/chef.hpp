#ifndef KOTITEHTAVA3_CHEF_HPP
#define KOTITEHTAVA3_CHEF_HPP

#include <string>

class Chef {
public:
  explicit Chef(std::string name);
  // Since the destructor is user-defined, technically I should adhere to the
  // rule of five/three but I can't be bothered.
  ~Chef();

  auto make_salad() const -> void;
  auto make_soup() const -> void;

protected:
  std::string name_;
};

class ItalianChef : public Chef {
public:
  explicit ItalianChef(std::string name, int water, int flour);
  auto get_name() const -> const std::string&;
  auto make_pasta() const -> void;

private:
  int water_;
  int flour_;
};

#endif  // KOTITEHTAVA3_CHEF_HPP
