#include "Polygon.hpp"

void Polygon::add_vertex(int i, int j){
    _vertices.emplace_back(i, j);
}

Vertex Polygon::operator[](int index) const {
    return _vertices[index];
}

std::ostream& operator<<(std::ostream& stream, const Polygon& polygon){
    for(auto v: polygon._vertices){
        stream << "(" << v.first << "," << v.second << ") ";
    }
    return stream;
} 