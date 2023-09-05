#include <iostream>

#include "chef.hpp"

Chef::Chef(std::string name)
    : name_{std::move(name)} {
  std::cout << "Chef " << name_ << " konstruktori\n";
}

Chef::~Chef() {
  std::cout << "Chef " << name_ << " destruktori\n";
}

auto Chef::make_salad() const -> void {
  std::cout << "Chef " << name_ << " makes salad\n";
}

auto Chef::make_soup() const -> void {
  std::cout << "Chef " << name_ << " makes soup\n";
}

ItalianChef::ItalianChef(std::string name, int water, int flour)
    : Chef{std::move(name)}
    , water_{water}
    , flour_{flour} {
  std::cout << "Chef " << get_name() << " konstruktori\n";
}

auto ItalianChef::get_name() const -> const std::string& {
  return name_;
}

auto ItalianChef::make_pasta() const -> void {
  const auto& name = get_name();
  std::cout << "Chef " << name << " makes pasta with special recipe\n";
  std::cout << "Chef " << name << " users jauhot = " << flour_ << '\n';
  std::cout << "Chef " << name << " users vesi = " << water_ << '\n';
}
