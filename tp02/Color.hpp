#pragma once

#include <ostream>
#include <vector>

enum class Color {
    Heart,
    Diamond,
    Spade,
    Club
};

std::ostream& operator<<(std::ostream& os, const Color c);

extern std::vector<Color> all_color;