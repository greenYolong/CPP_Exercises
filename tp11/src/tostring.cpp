#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// Définition du type général
template <unsigned N>
struct priority_tag : priority_tag<N - 1>
{};
// Spécialisation de priority_tag pour N=0
template <>
struct priority_tag<0>
{};

priority_tag<4> priority_highest_value;


template <typename T>
auto to_string(T&& data)
{
    return to_string(data, priority_highest_value);
}

template <typename T>
auto to_string(T&& data, priority_tag<0>)
{
  std::stringstream ss;
  ss << "<" << typeid(data).name() << " @" << &data << ">  :(";
  return ss.str();
}

// Ecrire les spécialisations ici
template<>
auto to_string(std::string& s){
  return s;
}
template<>
auto to_string(std::string&& s){
  return s;
}

template<typename T, size_t N>
auto to_string(std::array<T, N>&& array) {
  std::stringstream ss;
  ss << "[";

  auto first = true;
  for(const auto& e: array){
    if(!first) {
      ss << ", ";
    }
    first = false;

    ss << to_string(e);
  }

  ss << "]";
  return ss.str();
}

template <std::size_t I = 0, typename... Ts>
void tuple_print(const std::tuple<Ts...>& t, std::stringstream& ss)
{
    if constexpr (I < sizeof...(Ts))
    {
        if constexpr (I > 0){
          ss << ", ";
        }

        ss << to_string(std::get<I>(t));
        tuple_print<I + 1>(t, ss);
    }
}

template<typename... Ts>
auto to_string(std::tuple<Ts...>&& tuple){
  std::stringstream ss;
  ss << "(";
  tuple_print(tuple,ss);
  ss << ")";
  return ss.str();
}

auto to_string(const char* chars){
  std::string str(chars);
  return str;
}

template <typename T>
auto to_string(T&& value, priority_tag<1>) -> decltype(std::declval<std::ostream&>() << value, std::string())
{
  std::stringstream ss;
  ss << value;
  return ss.str();
}

template<typename T>
auto to_string(T&& ctn, priority_tag<2>) -> decltype(std::begin(ctn), std::string())
{
  std::stringstream ss;
  ss << "{";

  auto first = true;
  for(const auto& e: ctn){
    if(!first) {
      ss << ", ";
    }
    first = false;

    ss << to_string(e);
  }

  ss << "}";
  return ss.str();
}

template <typename T>
auto to_string(T&& value, priority_tag<3>) -> decltype(std::to_string(value))
{
  return std::to_string(value);
}

template <typename T>
auto to_string(T&& value, priority_tag<4>) -> decltype(value.to_string())
{
  return value.to_string();
}




// Vous n'avez rien à modifier en dessous de cette ligne !
class Empty
{};

class Streamable
{
public:
  friend std::ostream& operator<<(std::ostream& out, const Streamable& s)
  {
    return out << "Fonction operator<<(..) appelée :)";
  }
};

class Convertible
{
public:
  std::string to_string() const
  {
    std::stringstream ss;
    ss << "Fonction-membre Convertible::to_string() appelée :)";
    return ss.str();
  }
};

class Both : public Streamable, public Convertible
{};

template <typename T>
void print_test(std::string type, T&& value)
{
  std::cout << type << std::endl;
  std::cout << "** Error: value is not a std::string" << std::endl << std::endl;
}

void print_test(std::string type, std::string value)
{
  std::cout << type << std::endl;
  std::cout << " -> " << value << std::endl << std::endl;
}

int main()
{
  // De base on a l'adresse des objets
  print_test("Vide", to_string(Empty{}));

  // Q1: on veut gérer les chaines de caractères
  std::string truc{"Truc"};
  print_test("std::string (L-value)", to_string(truc));
  print_test("std::string (R-value)", to_string(std::string{"Machin"}));
  print_test("char*", to_string("Bidule"));

  // Q2: Puis les conversions simples fournies par la fonction std::to_string
  print_test("int", to_string(3));

  // Q4: Si un objet présente une fonction de conversion, on l'utilise
  print_test("Convertible", to_string(Convertible{}));

  // Q5: S'il est streamable (en implémentant l'opérateur << sur ostream), idem
  print_test("Streamable", to_string(Streamable{}));

  // Commenter cette ligne si elle bloque la compilation trop tot dans le TP
  print_test("Both", to_string(Both{}));

  // Q6: On s'attaque maintenant aux conteneurs
  print_test("std::vector<int>", to_string(std::vector<int>{1, 2, 3, 4}));
  print_test("std::vector<std::vector<int>>",
             to_string(std::vector<std::vector<int>>{std::vector<int>{0, 1, 2, 3},
                                                     std::vector<int>{4, 5, 6, 7}}));
  print_test("std::list<std::string>", to_string(std::list<std::string>{"Hello", "World", "!"}));

  // Q7: avec une spécialisation pour les std::array
  print_test("std::array<int, 4>", to_string(std::array<int, 4>{1, 2, 3, 4}));

  // Q8: tuple
  print_test("std::tuple<int, std::string, float>",
             to_string(std::tuple<int, std::string, float>{1, "2", 3.f}));


  return 0;
}
