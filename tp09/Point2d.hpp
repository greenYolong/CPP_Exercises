#pragma once

#include <unordered_map>

enum class Content {
    Empty, Red, Yellow
};




class Point2d {
public:

    bool operator==(Point2d other) const {
        return _x == other._x && _y == other._y;
    }

    int _x;
    int _y;
};

namespace std {   // il faut se placer dans le bon namespace

template <>
struct hash<Point2d>
{
   std::size_t operator()(Point2d p) const {
        size_t hash = (size_t(p._x)<<32) + size_t(p._y);
        hash*= 1231231557ull;
        hash^=(hash>>32);
        return hash;
    }
};

}