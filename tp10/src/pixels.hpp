#pragma once

#include "../lib/image_lib.hpp"

template <typename P1, typename P2>
using CombinedPixel = decltype(std::declval<P1>() + std::declval<P2>());

struct RGBA {
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;
    uint8_t _alpha;
};

struct RGB {
    uint8_t _red;
    uint8_t _green;
    uint8_t _blue;
};

struct Luma {
    uint8_t _grey;
};

// Convert base template
template <typename To, typename From>
To convert(const From& pixel);

// Specialized template
template <>
RGBA convert(const RGBA& pixel){
    return pixel;
}
template <>
RGB convert(const RGB& pixel){
    return pixel;
}
template <>
Luma convert(const Luma& pixel){
    return pixel;
}

template <>
RGBA convert(const RGB& pixel){
    return { pixel._red, pixel._green, pixel._blue, 255 };
}
template <>
RGB convert(const RGBA& pixel){
    return { pixel._red, pixel._green, pixel._blue };
}

template <>
RGB convert(const Luma& pixel){
    auto array = image_lib::grayscale_to_rgb(pixel._grey);
    return { array[0], array[1], array[2] };
}
template <>
Luma convert(const RGB& pixel){
    return { image_lib::rgb_to_grayscale(pixel._red, pixel._green, pixel._blue) };
}

template<>
RGBA convert(const Luma& pixel){
    return convert<RGBA>(convert<RGB>(pixel));
}
template<>
Luma convert(const RGBA& pixel){
    return convert<Luma>(convert<RGB>(pixel));
}







// Specialized template
RGBA operator+(const RGBA& lhs, const RGBA& rhs)
{
    auto array = image_lib::mix_color(lhs._red, lhs._green, lhs._blue, lhs._alpha,
                                      rhs._red, rhs._green, rhs._blue, rhs._alpha);
    return { array[0], array[1], array[2], array[3] };
}
RGB operator+(const RGB& lhs, const RGB& rhs)
{
    auto a = convert<RGBA>(lhs);
    auto b = convert<RGBA>(rhs);
    auto array = image_lib::mix_color(a._red, a._green, a._blue, a._alpha,
                                      b._red, b._green, b._blue, b._alpha);
    return { array[0], array[1], array[2] };
}

RGB operator+(const RGB& lhs, const RGBA& rhs)
{
    auto a = convert<RGBA>(lhs);
    auto array = image_lib::mix_color(a._red, a._green, a._blue, a._alpha,
                                      rhs._red, rhs._green, rhs._blue, rhs._alpha);
    return { array[0], array[1], array[2] };
}
RGBA operator+(const RGBA& lhs, const RGB& rhs)
{
    auto b = convert<RGBA>(rhs);
    auto array = image_lib::mix_color(lhs._red, lhs._green, lhs._blue, lhs._alpha,
                                      b._red, b._green, b._blue, b._alpha);
    return { array[0], array[1], array[2], array[3] };
}

RGB operator+(const Luma& lhs, const RGBA& rhs) 
{
    auto a = convert<RGBA>(lhs);
    auto array = image_lib::mix_color(a._red, a._green, a._blue, a._alpha,
                                      rhs._red, rhs._green, rhs._blue, rhs._alpha);
    return { array[0], array[1], array[2] };
}
RGB operator+(const Luma& lhs, const RGB& rhs)
{
    auto a = convert<RGBA>(lhs);
    auto b = convert<RGBA>(rhs);
    auto array = image_lib::mix_color(a._red, a._green, a._blue, a._alpha,
                                      b._red, b._green, b._blue, b._alpha);
    return { array[0], array[1], array[2] };
}

RGBA operator+(const RGBA& lhs, const Luma& rhs)
{
    auto b = convert<RGBA>(rhs);
    auto array = image_lib::mix_color(lhs._red, lhs._green, lhs._blue, lhs._alpha,
                                      b._red, b._green, b._blue, b._alpha);
    return { array[0], array[1], array[2], array[3] };
}
RGBA operator+(const RGB& lhs, const Luma& rhs)
{
    auto a = convert<RGBA>(lhs);
    auto b = convert<RGBA>(rhs);
    auto array = image_lib::mix_color(a._red, a._green, a._blue, a._alpha,
                                      b._red, b._green, b._blue, b._alpha);
    return { array[0], array[1], array[2], array[3] };
}
RGBA operator+(const Luma& lhs, const Luma& rhs)
{
    auto a = convert<RGBA>(lhs);
    auto b = convert<RGBA>(rhs);
    auto array = image_lib::mix_color(a._red, a._green, a._blue, a._alpha,
                                      b._red, b._green, b._blue, b._alpha);
    return { array[0], array[1], array[2], array[3] };
}






// Masque de transparence
template <typename P>
RGBA operator+(const P& lhs, const Luma& mask)
{
    RGBA result;

    if constexpr (std::is_same_v<P, Luma>)
    {
        result._red = result._green = result._blue = lhs._grey;
    }
    else
    {
        result._red = lhs._red;
        result._green = lhs._green;
        result._blue = lhs._blue;
    }

    uint8_t base_alpha;

    if constexpr (std::is_same_v<P, RGBA>)
        base_alpha = lhs._alpha;
    else
        base_alpha = 255;

    result._alpha = static_cast<uint8_t>((base_alpha * mask._grey) / 255);

    return result;
}