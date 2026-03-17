#pragma once

#include "Base.hpp"
#include <iostream>
#include <vector>
#include <sstream>

class DerivedList : public Base {
public:
    DerivedList() : Base { "List" } {}

    bool is_null() const override { return _list.empty(); }

    const std::vector<std::unique_ptr<Base>>& data() const { return _list; }

    std::string type() const { return "List"; }

    std::unique_ptr<Base> clone() const override
    {
        auto res = std::make_unique<DerivedList>();
        for (const auto& e : _list)
        {
            res->_list.push_back(e->clone());
        }
        return res;
    }

    bool equals(const Base& base) const override {
        if (this->type() != base.type())
            return false;

        const auto* other = dynamic_cast<const DerivedList*>(&base);

        if (_list.size() != other->_list.size())
            return false;

        for (size_t i = 0; i < _list.size(); ++i)
        {
            if (!(*_list[i] == *other->_list[i]))
                return false;
        }

        return true;
    }

    std::string to_string() const override {
        if(_list.empty()) {
            return "[]";
        }
        std::stringstream ss;
        size_t i = 0;
        ss << "[" << *_list[i++];
        for(;i < _list.size();i++){
            ss << "," << *_list[i];
        }
        ss << "]";
        return ss.str();
    }

    void add(const Base& base) {
        _list.emplace_back(base.clone());
    }

    void add(Base&& base) {
        auto* list = dynamic_cast<DerivedList*>(&base);

        if (list != nullptr)
        {
            _list.push_back(std::make_unique<DerivedList>(std::move(*list)));
        }
        else
        {
            _list.push_back(base.clone());
        }
    }

private:
    std::vector<std::unique_ptr<Base>> _list;


};