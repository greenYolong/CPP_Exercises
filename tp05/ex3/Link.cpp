#include "Link.hpp"
#include <iostream>

Link::~Link(){
    
}

Link::Link(const Person& person) 
    : _value { person }
{}

Link::Link(Person&& person)
    : _value(std::move(person))
{}

Link::Link(Link* prev, const Person& person)
    : _prev { prev }
    , _value { person }
{
    if(prev){
        prev->_next = this;
    }
}

Link::Link(Link* prev, Person&& person)
    : _prev { prev }
    , _value(std::move(person))
{
    if(prev){
        prev->_next = this;
    }
}


Link::Link(const Link& other)
    : _prev(other._prev)
    , _next(other._next)
    , _value { other._value }
{}



Person& Link::value() {
    return _value;
}

const Person& Link::value() const {
    return _value;
}

Link* Link::prev() const {
    return _prev;
}

Link* Link::next() const {
    return _next;
}