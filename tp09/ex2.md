# Algo avec remove_if

```c++
#include <iostream>
#include <string>
#include <vector>

struct Animal
{
    std::string name;
    std::string species;
};

std::ostream& operator<<(std::ostream& str, const Animal& animal)
{
    return str << animal.name << " (" << animal.species<< ")";
}

std::ostream& operator<<(std::ostream& str, const std::vector<Animal>& animals)
{
    str << "[-";
    for (const auto& a: animals)
    {
        str << " " <<  a << " -";
    }
    str << "]";
    return str;
}

#include <algorithm>

void remove_cats(std::vector<Animal>& animals)
{
    animals.erase(std::remove_if(animals.begin(), animals.end(), [](Animal a){ return a.species == "cat"; }), animals.end());
}

int main()
{
    std::vector<Animal> animals;
    animals.push_back({ "felix", "cat" });
    animals.push_back({ "medor", "dog" });
    animals.push_back({ "guss", "mouse" });
    animals.push_back({ "gipsy", "dog" });
    animals.push_back({ "chaussette", "cat" });
    animals.push_back({ "pelotte", "cat" });

    std::cout << animals << std::endl;

    remove_cats(animals);
    std::cout << animals << std::endl;

    return 0;
}
```

# Algo avec find_if

```cpp
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>

struct Animal
{
    std::string name;
    std::string species;
};

std::ostream& operator<<(std::ostream& str, const Animal& animal)
{
    return str << animal.name << " (" << animal.species<< ")";
}

std::ostream& operator<<(std::ostream& str, const std::deque<Animal>& animals)
{
    str << "[";
    for (size_t idx = 0, end = animals.size(); idx < end; ++idx)
    {
        str << idx << ": "<< animals[idx];
        if (idx + 1 < end)
        {
            str << ", ";
        }
    }
    str << "]";
    return str;
}

std::ptrdiff_t get_position_of_first_with_species(const std::deque<Animal>& animals, const std::string& species)
{
    auto it = std::find_if(animals.begin(), animals.end(), [species](Animal a){ return a.species == species; });
    return it != animals.end()
    ? std::distance(animals.begin(), it)
    : -1;
}

int main()
{
    std::deque<Animal> animals;
    animals.push_back({ "felix", "cat" });
    animals.push_back({ "medor", "dog" });
    animals.push_back({ "guss", "mouse" });
    animals.push_back({ "gipsy", "dog" });
    animals.push_back({ "chaussette", "cat" });
    animals.push_back({ "pelotte", "cat" });

    std::cout << animals << std::endl;

    std::cout << "First dog is at: " << get_position_of_first_with_species(animals, "dog") << std::endl;
    std::cout << "First poney is at: " << get_position_of_first_with_species(animals, "poney") << std::endl;
    std::cout << "First mouse is at: " << get_position_of_first_with_species(animals, "mouse") << std::endl;

    return 0;
}
```


# Algo avec for_each

```cpp
#include <iostream>
#include <string>
#include <list>
#include <algorithm>

struct Character
{
    std::string name;
    int hp;
};

std::ostream& operator<<(std::ostream& o, const Character& c) {
    return o << c.name << " (" << c.hp << " hp)";
}

std::ostream& operator<<(std::ostream& o, const std::list<Character> characters) {
    for (const Character& c : characters )
        o << c << std::endl;
    return o;
}

void remove_hp_to_everyone(std::list<Character>& characters, int hp_to_remove)
{
    std::for_each(characters.begin(), characters.end(), [hp_to_remove](Character& c){ c.hp = c.hp - hp_to_remove; });
}

int main()
{
    std::list<Character> characters { { "Celine",  1 },
                                      { "Victor",  2 },
                                      { "Anthony", 3 },
                                      { "Henri",  14 } };
    std::cout << characters << std::endl;

    remove_hp_to_everyone(characters, 2);
    std::cout << characters << std::endl;

    return 0;
}
```

# Algo avec transform et back_inverter

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Person
{
    std::string first_name;
    std::string last_name;
};

std::vector<std::string> compute_full_names(const std::vector<Person>& persons)
{
    std::vector<std::string> full_names;
    std::transform(persons.begin(), persons.end(), std::back_inserter(full_names), [](Person p) { return p.first_name + " " + p.last_name;} );
    return full_names;
}

int main()
{
    std::vector<Person> persons { { "Celine", "Noel" },
                                  { "Victor", "Marsault" },
                                  { "Anthony", "Labarre" },
                                  { "Henri", "Derycke" } };

    const auto full_names = compute_full_names(persons);
    for (const auto& f: full_names)
    {
        std::cout << f << std::endl;
    }

    return 0;
}
```

# Algo avec transform et accumulate
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void to_upper(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::toupper(c); });
}

std::string concat_in_caps(const std::vector<std::string>& words)
{
    auto r = std::accumulate(
        words.begin(), 
        words.end(), 
        std::string{}, 
        [](const std::string& s1, const std::string& s2) { 
            return s1.empty() ? s2 : s1 + " " + s2;
            }
    );
    to_upper(r);
    return r;
}

int main()
{
    const std::vector<std::string> words { "ARRETE", "De", "criEr", "steuplAIt" };
    std::cout << concat_in_caps(words) << std::endl;
    return 0;
}
```

# Libre service
```cpp
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <string>

struct Entity
{
    Entity(std::string name, int life)
    : name { std::move(name) }
    , life { life }
    {}

    std::string name;
    int life = 100;
};

using Entities = std::list<std::unique_ptr<Entity>>;

void apply_on_entities_with_type(std::map<std::string, Entities>& all_entities,
                                 const std::string& type,
                                 const std::function<void(Entities&)>& fcn)
{
    auto it = all_entities.find(type);
    if (it != all_entities.end())
    {
        fcn(it->second);
    }
}

void print_entities(std::map<std::string, Entities>& all_entities, const std::string& type)
{
    apply_on_entities_with_type(all_entities, type,
        [type](Entities& entities)
        {
            std::cout << "== " << type << " ==\n";
            for (const auto& e : entities)
            {
                std::cout << e->name << " (" << e->life << ")\n";
            }
        });
}

void hit_monsters(std::map<std::string, Entities>& all_entities, int life_decrease)
{
    apply_on_entities_with_type(
        all_entities, 
        "Monster", 
        [life_decrease](Entities& e){ 
            std::for_each(e.begin(), e.end(),
                [life_decrease](std::unique_ptr<Entity>& ptr){
                    ptr->life -= life_decrease;
                });
        });
}

void remove_dead_entities(std::map<std::string, Entities>& all_entities)
{
    auto remove_if_dead = [](Entities& entities)
    {
        entities.remove_if([](const std::unique_ptr<Entity>& e)
        {
            return e->life <= 0;
        });
    };

    apply_on_entities_with_type(all_entities, "Monster", remove_if_dead);
    apply_on_entities_with_type(all_entities, "Human", remove_if_dead);
}

void add_entity(std::map<std::string, Entities>& all_entities, const std::string& type, std::unique_ptr<Entity> entity)
{
    apply_on_entities_with_type(all_entities, type,
        [&entity](Entities& entities)
        {
            entities.push_back(std::move(entity));
        });
}

int main()
{
    std::map<std::string, Entities> entities;

    {
        auto monsters = Entities {};
        monsters.push_back(std::make_unique<Entity>("Troll", 1000));
        monsters.push_back(std::make_unique<Entity>("Blob", 30));
        
        entities.emplace("Monster", std::move(monsters));
    }

    {
        auto humans = Entities {};
        humans.push_back(std::make_unique<Entity>("Bob", 60));
 
        entities.emplace("Human", std::move(humans));
    }

    print_entities(entities, "Human");
    print_entities(entities, "Monster");
    print_entities(entities, "Items");  // Nothing should happen if the type doesn't exist

    hit_monsters(entities, 200);
    remove_dead_entities(entities); // Blob should die
    add_entity(entities, "Monster", std::make_unique<Entity>("Wolf", 400));

    print_entities(entities, "Monster");
    
    hit_monsters(entities, 2000);
    remove_dead_entities(entities);

    print_entities(entities, "Monster"); // All monsters should be dead

    return 0;
}
```