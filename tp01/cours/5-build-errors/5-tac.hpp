#pragma once

#include "5-tic.hpp"

struct Tic;

struct Tac
{
    // Invert value with tic.
    void swap(Tic& tic);

    int value = 0;
};
