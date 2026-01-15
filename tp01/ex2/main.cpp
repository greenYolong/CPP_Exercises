#include <iostream>
#include <vector>
#include <string>

void ajoute_double(std::vector<int>& v)
{
    auto tmp = std::vector<int>(v);
    for (auto n : v)
    {
        tmp.emplace_back(n * 2);
    }
    v = tmp;
}

void print_vector(std::vector<int>& v){
    std::cout << "Le tableau contient les valeurs :";
    for (auto i: v)
    {
        std::cout << " " << i;
    }
    std::cout << std::endl;
}

int main()
{
    auto entiers = std::vector<int>{};

    auto number = -1;
    std::string entry;

    while(number != 0){
        std::cin >> entry;
        try {
            number = std::stoi(entry);
            if(number < 0){
                entiers.pop_back();
            } else {
                entiers.emplace_back(number);
            }
        } catch (std::invalid_argument){
            std::cerr << "Ceci n'est pas un entiers!" << std::endl;
        }
    }

    print_vector(entiers);

    std::cout << "Premier élément : " << entiers.front() << std::endl;
    std::cout << "Dernier élément : " << entiers.back() << std::endl;

    ajoute_double(entiers);

    print_vector(entiers);

    return 0;
}