#pragma once

#include "Person.hpp"

class LinkedList;

class Link
{
public:
    // Il faut réflechir aux prototypes des fonctions-membres ci-dessous, certains ne sont pas corrects.
    ~Link();
    Link(const Person&);
    Link(Person&&);
    Link(Link*,const Person&);
    Link(Link*, Person&&);
    // Link(Link*, Person, Link*);
    Link(const Link&);
    
    Person& value();
    const Person& value() const;
    Link* prev() const;
    Link* next() const;

private:
    Link*  _prev;
    Link*  _next;
    Person _value;
};