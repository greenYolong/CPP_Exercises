#pragma once

#include <array>
#include <functional>

#include "pixels.hpp"

template <typename P, size_t W, size_t H>
class Image {
public:
    Image() = default;
    Image(const P& pixel) {
        fill(pixel);
    }
    Image(const std::function<P(size_t i, size_t j)>& fun){
        for(size_t i = 0; i < H; i++) {
            for(size_t j = 0; j < W; j++) {
                _img[i][j] = fun(i, j);
            }
        }
    }

    P& operator()(size_t i, size_t j){
        return _img[i][j];
    }

    const P& operator()(size_t i, size_t j) const {
        return _img[i][j];
    }

    template <typename OtherP>
    Image<CombinedPixel<P, OtherP>, W, H> operator+(const Image<OtherP, W, H>& other) const
    {
        using ResultPixel = CombinedPixel<P, OtherP>;

        Image<ResultPixel, W, H> newImg; 

        for (size_t i = 0; i < H; i++)
        {
            for (size_t j = 0; j < W; j++)
            {
                newImg(i, j) = (*this)(i, j) + other(i, j);
            }
        }

        return newImg;
    }

private:
    std::array<std::array<P, W>, H> _img {};

    void fill(const P& pixel) {
        for(auto& arr: _img) {
            std::fill_n(arr.begin(), W, pixel);
        }
    }
};