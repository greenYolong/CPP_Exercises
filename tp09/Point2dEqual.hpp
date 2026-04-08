#pragma once

#include "Point2d.hpp"

class Point2dEqual {
public:
    bool operator()(Point2d p1, Point2d p2) const {
        return p1._x == p2._x && p1._y == p2._y;
    }
};