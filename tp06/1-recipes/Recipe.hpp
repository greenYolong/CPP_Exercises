#pragma once

#include <ostream>
#include "aliases.hpp"




class Recipe
{
public:
  Recipe(MaterialBag requirements, const Material& product, size_t id)
    : _requirements { requirements }
    , _product { product }
    , _id { id }
  {
    std::cout << "Recipe " << product << " has been registered" << std::endl;
  }

  ~Recipe(){
    std::cout << "Recipe " << _product << " is no longer registered" << std::endl;
  }

  size_t get_id() const {
    return _id;
  }


  bool operator<(const Recipe& other) const{
    return _id < other._id;
  }
  bool operator<(size_t id) const {
    return _id < id;
  }

  // Affiche l'identifiant et la formule d'une recette.
  friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe)
  {
    stream << "(" << recipe._id << ") ";
    for(const auto& pair: recipe._requirements){
      for(int i = 0; i < pair.second; i++){
        stream << *(pair.first) << " ";
      }
    }
    return stream << "=> " << recipe._product;
  }

  friend bool operator<(const Recipe& r, size_t id){
    return r._id < id;
  }

private:
  MaterialBag _requirements;
  const Material& _product;
  size_t _id;
};


