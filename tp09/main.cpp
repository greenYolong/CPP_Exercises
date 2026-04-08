#include "Point2d.hpp"
#include "Point2dHash.hpp"
#include "Point2dEqual.hpp"

#include "Point3d.hpp"
#include "Point3dCompare.hpp"

#include <iostream>
#include <set>


int main() {
    std::unordered_map<Point2d, Content> grid {};
    Point2d point {1,2};
    grid.emplace(point, Content::Red);
    std::cout << grid.size() << std::endl;
    grid.clear();
    std::cout << grid.size() << std::endl;

    std::set<Point3d> coords {};
    Point3d troisd { 1, 2, 3 };
    coords.insert(troisd);
    std::cout << coords.size() << std::endl;
    coords.clear();
    std::cout << coords.size() << std::endl;
}