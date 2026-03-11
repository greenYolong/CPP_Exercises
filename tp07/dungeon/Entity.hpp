#pragma once

#include "Random.hpp"
#include "Logger.hpp"
class Entity
{
public:
    Entity() = default;

    Entity(int x, int y)
        : _x { x }
        , _y { y }
    {logger << "Hello world" << std::endl;}

    int get_x() const { return _x; }
    int get_y() const { return _y; }

    virtual char get_representation() const = 0;

    virtual void update() { 
        random_move(_x, _y); 
        logger << "Updated " << this << std::endl;
    }

    virtual void interact_with(Entity& e) {}

    virtual bool should_destroy() const { return !_live; }

    virtual void kill() { _live = false; }

private:
    int _x = 0;
    int _y = 0;
protected:
    bool _live = true;
};
