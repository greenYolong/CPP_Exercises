#pragma once

#include <ostream>
#include <iostream>
#include <string>

class Material
{
public :
  Material(const std::string& name)
    : _name { name }
  {
    std::cout << name << " was created" << std::endl;
  }

  ~Material(){
    std::cout << _name << " was destroyed" << std::endl;
  }


  const std::string& get_name() const {
    return _name;
  }

  // Affiche le nom d'un matériau
  friend std::ostream& operator<<(std::ostream& stream, const Material& material)
  {
    return stream << material._name;
  }

private:
  std::string _name;
};
