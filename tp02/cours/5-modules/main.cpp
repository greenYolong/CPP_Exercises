#include "Rectangle.hpp"

#include <iostream>

int main() {
  Rectangle rect(2.f, 4.f);
  std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width()
            << " }" << std::endl;

  rect.scale(3);
  std::cout << "{ L: " << rect.get_length() << ", W: " << rect.get_width()
            << " }" << std::endl;

  Rectangle defaut;
  std::cout << "{ L: " << defaut.get_length() << ", W: " << defaut.get_width()
            << " }" << std::endl;

  Rectangle::set_default_size(3.f);
  defaut = Rectangle{};
  std::cout << "{ L: " << defaut.get_length() << ", W: " << defaut.get_width()
            << " }" << std::endl;

  return 0;
}
