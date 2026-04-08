#pragma once

#include "Point2d.hpp"


class Point2dHash {
public:
    std::size_t operator()(Point2d p) const {
        size_t hash = (size_t(p._x)<<32) + size_t(p._y);
        hash*= 1231231557ull;
        hash^=(hash>>32);
        return hash;
    }
};