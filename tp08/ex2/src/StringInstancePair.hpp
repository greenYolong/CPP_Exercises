#pragma once

#include <string>
#include <memory>


class StringInstancePair {
public:
    StringInstancePair(const std::string& str)
        : _str{str}
        , _tracker{std::make_unique<Tracker>()}
    {}

    // copy constructor
    StringInstancePair(const StringInstancePair& other)
        : _str{other._str}
        , _tracker{std::make_unique<Tracker>(*other._tracker)}
    {}

    // copy assignment
    StringInstancePair& operator=(const StringInstancePair& other)
    {
        if (this != &other)
        {
            _str = other._str;
            _tracker = std::make_unique<Tracker>(*other._tracker);
        }
        return *this;
    }

    // move = default
    StringInstancePair(StringInstancePair&&) = default;
    StringInstancePair& operator=(StringInstancePair&&) = default;

    const std::string& get_str() const { return _str; }
    const Tracker& get_tracker() const { return *_tracker; }

private:
    std::string _str;
    std::unique_ptr<Tracker> _tracker;
};