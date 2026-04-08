#pragma once

#include <tuple>


struct Point3d {
    int _x;
    int _y;
    int _z;

    bool operator<(Point3d other) const {
        return std::tie(_x, _y, _z) < std::tie(other._x, other._y, other._z);
    }
};