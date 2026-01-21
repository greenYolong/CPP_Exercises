#pragma once

#include <vector>
#include <utility>
#include <ostream>

using Vertex = std::pair<int,int>;

class Polygon{
public:
    void add_vertex(int i, int j);
    Vertex operator[](int index) const;
    friend std::ostream& operator<<(std::ostream& stream, const Polygon& polygon);
private:
    std::vector<Vertex> _vertices;
};
