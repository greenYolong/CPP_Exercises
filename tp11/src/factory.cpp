#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <functional>
#include <map>

// Liste des entitées à construire
std::string desc = R"(Object
Person
Dog
Inexistent
Cat
Tree
House
Athanase)";

class Entity
{
public:
  virtual void print() const = 0;
  virtual ~Entity() = default;
};


class Factory
{
public:
  using Builder = std::function<std::unique_ptr<Entity>()>;

  // template <typename TDerivedEntity>
  // void register_entity(std::string index)
  // {
  //   builders[index] = []() {
  //       return std::make_unique<TDerivedEntity>();
  //   };
  // }

  template <typename TDerivedEntity, typename... Args>
  void register_entity(std::string index, Args&&... args)
  {
    builders[index] = [&args...]() {
        return std::make_unique<TDerivedEntity>(args...);
    };
  }

  std::unique_ptr<Entity> build(std::string index) const { 
    auto it = builders.find(index);

    if (it != builders.end())
    {
        return it->second(); 
    }

    return nullptr;
  }

private:
  std::map<std::string, Builder> builders;
};


class Object : public Entity
{
public:
  void print() const override { std::cout << "Object" << std::endl; }
};


class Tree : public Object
{
public:
  void print() const override { std::cout << "Arbre" << std::endl; }
};


class Person : public Entity
{
public:
  explicit Person(std::string name)
      : _name{std::move(name)}
  {}

  void print() const override { std::cout << "Person named " << _name << std::endl; }

  void set_name(std::string name) { _name = std::move(name); }
  const std::string& get_name() const { return _name; }

private:
  std::string _name;
};


class Animal : public Entity
{
public:
  explicit Animal(std::string species)
      : _species{std::move(species)}
  {}

  explicit Animal(std::string species, std::string name)
      : _species{std::move(species)}
      , _name{std::move(name)}
  {}

  void print() const override
  {
    std::cout << "Animal of species " << _species;
    if (_name != "")
      std::cout << " named " << _name;
    std::cout << std::endl;
  }

private:
  std::string _species;
  std::string _name;
};


class House : public Object
{
public:
  explicit House(Person& owner)
      : _owner{owner}
  {}

  void print() const override { std::cout << "House owned by " << _owner.get_name() << std::endl; }

private:
  Person& _owner;
};



int main()
{
  Factory factory;
  factory.register_entity<Object>("Object");
  factory.register_entity<Tree>("Tree");
  factory.register_entity<Person>("Person", "Jean");
  factory.register_entity<Animal>("Dog", "Dog", "Medor");
  factory.register_entity<Animal>("Cat", "Cat", "Pacha");
  Person p{ "Gripsou" };
  factory.register_entity<House>("House", p);
  p.set_name("Picsou");
  factory.register_entity<Animal>("Athanase", "cat", "Athanase");


  // Vous n'avez rien à modifier en dessous de cette ligne !
  std::vector<std::pair<std::string, std::unique_ptr<Entity>>> entities;

  std::stringstream s;
  s << desc;
  while (!s.eof()) {
    std::string e;
    s >> e;

    auto o = factory.build(e);
    entities.emplace_back(std::move(e), std::move(o));
  }

  for (const auto& e : entities) {
    std::cout << "In:  " << e.first << std::endl;
    std::cout << "Out: ";
    if (e.second != nullptr)
      e.second->print();
    else
      std::cout << "nullptr" << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
