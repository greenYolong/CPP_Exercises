#pragma once 

#include "Point3d.hpp"

#include <tuple>


struct Point3dCompare {
    bool operator()(Point3d p1, Point3d p2) const {
        return std::tie(p1._x, p1._y, p1._z) < std::tie(p2._x, p2._y, p2._z);
    }
};