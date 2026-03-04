#include "ProgramData.hpp"
#include <iostream>
#include <utility>
#include <algorithm>


void ProgramData::register_material(std::string name)
{
  auto ptr = std::make_unique<Material>(name);
  _registered_materials.emplace_back(ptr);
  _material_from_name[name] = ptr.get();
}

void ProgramData::get_registered_materials(std::vector<const Material*>& materials) const
{
  for(const auto& ptr: _registered_materials){
    materials.push_back(ptr.get());
  }
}

void ProgramData::add_material_to_inventory(const Material& mat, int quantity)
{
  auto pair = std::make_pair<const Material*, size_t>(&mat, quantity);
  _inventory.emplace_back(pair);
}

void ProgramData::get_inventory(MaterialBag& materials) const
{
  for(const auto& pair: _inventory){
    materials.push_back(pair);
  }
}

const Material* ProgramData::get_material_by_name(const std::string& name) const
{
  // for(const auto& ptr: _registered_materials){
  //   auto mat = ptr.get();
  //   if(mat->get_name() == name){
  //     return mat;
  //   }
  // }
  // return nullptr;

  auto search = _material_from_name.find(name);
  if(search != _material_from_name.end()) {
    return search->second;
  }
  return nullptr;
}


// ============================================================================
// = Partie Recette ===========================================================
// ============================================================================

void ProgramData::register_recipe(std::vector<const Material*> materials,
                                  const Material& product)
{
  MaterialBag bag;
  for(const auto* mat: materials){
    auto it = std::find_if(
      bag.begin(),
      bag.end(),
      [mat](const auto& entry) {
          return entry.first == mat;
      }
    );
    if(it == bag.end()){
      bag.emplace_back(mat, 1);
    } else {
      it->second++;
    }
  }
  size_t id = _registered_recipes.size() + 1;
  _registered_recipes.emplace(bag, product, id);
}

void ProgramData::get_all_recipes(std::vector<const Recipe*>& recipes) const 
{
  for(const auto& recipe: _registered_recipes){  // Même ordre is vector, ordre random si unordered_set
    recipes.push_back(&recipe);
  }
}

const Recipe* ProgramData::get_recipe_by_id(size_t id) const
{
  auto search = _registered_recipes.find(id);
  if(search != _registered_recipes.end()){
    return search;
  }
  return nullptr;
}

void ProgramData::unregister_recipe(const Recipe& recipe)
{
  auto search = get_recipe_by_id(recipe.get_id());
  if(search){
    delete search;
  } else {
    std::cout << "Unknown Recipe" << std::endl;
  }
}


// ============================================================================
// = Partie Production ========================================================
// ============================================================================


void ProgramData::get_doable_recipes(std::vector<const Recipe*>& recipes) const
{
  std::cout << "Feature is not yet implemented (get_doable_recipes)" << std::endl;
}

Outcome ProgramData::produce(const Recipe& recipe, MaterialBag& materials)
{
  std::cout << "Feature is not yet implemented (produce)" << std::endl;
  return Outcome::FAILURE;
}
