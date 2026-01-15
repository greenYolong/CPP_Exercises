#pragma once

#include "5-tac.hpp"

struct Tac;

struct Tic
{
    // Invert value with tac.
    void swap(Tac& tac);

    int value = 0;
};
