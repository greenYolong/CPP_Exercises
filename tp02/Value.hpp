#pragma once

#include <ostream>
#include <vector>

enum class Value : unsigned int {
    Seven = 7u,
    Eight = 8u,
    Nine  = 9u,
    Ten   = 10u,
    Jack  = 11u,
    Queen = 12u,
    King  = 13u,
    Ace   = 14u
};

std::ostream& operator<<(std::ostream& os, const Value v);

extern std::vector<Value> all_value;