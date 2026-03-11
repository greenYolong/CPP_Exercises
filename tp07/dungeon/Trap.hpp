#pragma once 

#include "Entity.hpp"
#include "Item.hpp"
#include "Random.hpp"



class Trap : public Entity, public Item {
public :
    Trap(int width, int height) : Entity { random_value(0, width), random_value(0, height) } {}

    char get_representation() const override { return '#'; }

    void update() override { Item::update(); }
private :

};