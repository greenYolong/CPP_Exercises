#include "Rectangle.hpp"

// float Rectangle::_default_size = 2.f;

Rectangle::Rectangle(float length, float width)
    : _length { length }
    , _width { width }
{}

Rectangle::Rectangle(float length)
    : Rectangle { length, length}
{}

Rectangle::Rectangle()
    : Rectangle { _default_size }
{}

void Rectangle::set_default_size(float f){
    _default_size = f;
}

void Rectangle::scale(float ratio)
{
    _length *= ratio;
    _width *= ratio;
}