#include "utils.hpp"

int main()
{
    print_hello();  // Si on exclu le utils.cpp dans la commande, on a une référence indéfinie vers la fonction
    print_bye();
    return 0;
}
