#pragma once

#include <utility> // pair
#include <vector>
#include <set>

class Material;
class Recipe;

using MaterialBag = std::vector<std::pair<const Material*, size_t>>;
using RecipeCollection = std::set<Recipe, std::less<>>;