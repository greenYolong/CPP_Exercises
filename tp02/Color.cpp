#include "Color.hpp"

std::ostream& operator<<(std::ostream& os, const Color color){
    switch(color)
    {
        case Color::Heart   : os << "Coeur";    break;
        case Color::Diamond : os << "Carreau";  break;
        case Color::Spade   : os << "Pique";    break;
        case Color::Club    : os << "Trèfle";   break;
    }
    return os;
}

std::vector<Color> all_color = { Color::Heart, Color::Diamond, Color::Spade, Color::Club };