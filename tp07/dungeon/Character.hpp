#pragma once

#include "Entity.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include "Logger.hpp"

#include <string>       // _name
#include <iostream>     // std::endl


class Character : public Entity {
public:
    Character(int x, int y) 
        : Entity { x, y }
        , _name { 'A' + (_count % 26) } 
    { 
        _count++;  
        logger << "Character " << _name << " was created in (" << x << "," << y <<")" << std::endl;
    }

    char get_representation() const override { return _name; }

    void interact_with(Entity& entity){
        if (auto* trap = dynamic_cast<Trap*>(&entity))
        {
            _hp--;

            if (_hp == 1){
                _name = std::tolower(_name);
            }
            else if (_hp <= 0) {
                _name = ' ';
                kill();
            }
            trap->kill();
        } 
        if (auto* potion = dynamic_cast<Potion*>(&entity))
        {
            if (_hp == 1) {
                _name = std::toupper(_name);
                _hp++;
                potion->kill();
            }
        }
    }

private:
    char _name;
    int _hp = 2;
    inline static int _count = 0;
};

