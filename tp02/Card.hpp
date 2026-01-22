#pragma once

#include <ostream>

#include "Color.hpp"
#include "Value.hpp"

class Card {
public:
    Card(Value value, Color color);

    int operator==(const Card& c) const;
    int operator<(const Card& c) const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
    Value _value;
    Color _color;
};