#pragma once

#include "Link.hpp"
#include "Person.hpp"

class LinkedList
{
public:
    // Il faut réflechir aux prototypes des fonctions-membres ci-dessous, certains ne sont pas corrects.
    friend std::ostream& operator<<(std::ostream& o, const LinkedList& list);

    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);

    size_t size() const;
    bool empty() const;
    const Person& front() const;
    Person& front();
    const Person& back() const;
    Person& back();

    void push_back(const Person&);
    void push_back(Person&&);

    // void concatenate_back(LinkedList);

    // bool contains(Person);

    // void push_back_if_absent(Person);

    // static void swap(LinkedList, LinkedList);

private:
    Link* _front = nullptr;
    Link* _back = nullptr;
    int   _size = 0;
};