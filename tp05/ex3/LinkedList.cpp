#include "LinkedList.hpp"

std::ostream& operator<<(std::ostream& o, const LinkedList& list){
    o << "{ ";
    auto* current = list._front;
    while(current != nullptr){
        o << current->value();
        current = current->next();
        if(current != nullptr){
            o << ", ";
        }
    }

    return o << " }";
}

LinkedList::LinkedList(){}

LinkedList::~LinkedList(){
    auto* current = _front;
    while (current != nullptr) {
        auto* next = current->next();
        delete current;
        current = next;
    }
}

LinkedList::LinkedList(const LinkedList& list)
    : _front(list._front)
    , _back(list._back)
    , _size { list._size }
{}


LinkedList& LinkedList::operator=(const LinkedList& other){
    if (this != &other){
        _front = other._front;
        _back = other._back;
        _size = other._size;
    }
    return *this;
}

size_t LinkedList::size() const {
    return (size_t) _size;
}

bool LinkedList::empty() const {
    return _size == 0;
}

const Person& LinkedList::front() const {
    return _front->value();
}
Person& LinkedList::front() {
    return _front->value();
}
const Person& LinkedList::back() const {
    return _back->value();
}
Person& LinkedList::back() {
    return _back->value();
}


void LinkedList::push_back(const Person& person){   
    if (!_back) {                // liste vide
        _back = new Link{nullptr, person};
        _front = _back;
    } else {
        _back = new Link{_back, person};
    }
    _size++;
}

void LinkedList::push_back(Person&& person){
    if (!_back) {
        _back = new Link{nullptr, std::move(person)};
        _front = _back;
    } else {
        _back = new Link{_back, std::move(person)};
    }
    _size++;
}