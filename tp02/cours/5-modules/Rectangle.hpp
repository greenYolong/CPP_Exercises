#pragma once

class Rectangle
{
public:
    Rectangle(float length, float width);
    Rectangle(float length);
    Rectangle();

    static void set_default_size(float f);
    
    float get_length() const { return _length; }
    float get_width() const { return _width; }
    
    void scale(float ratio);
    
private:
    float _length;
    float _width;
    static inline float _default_size = 2.f;
};
