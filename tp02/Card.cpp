#include <iostream>

#include "Card.hpp"
#include "Color.hpp"
#include "Value.hpp"

Card::Card(Value value, Color color) 
    : _value { value }
    , _color { color }
{}

int Card::operator==(const Card& c) const {
    return (unsigned) _value == (unsigned) c._value;
}

int Card::operator<(const Card& c) const {
    return (unsigned) _value < (unsigned) c._value;
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card._value << " de " <<  card._color;
    return os;
}