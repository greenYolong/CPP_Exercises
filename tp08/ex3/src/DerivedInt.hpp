#pragma once

#include "Base.hpp"




class DerivedInt : public Base {
public :
    DerivedInt(int i) : Base { "Int" }, _int { i } {}

    bool is_null() const override { return _int == 0; }

    int data() const { return _int; }

    std::string type() const { return "Int"; }

    std::unique_ptr<Base> clone() const {
        return std::make_unique<DerivedInt>(*this);
    }

    bool equals(const Base& base) const override {
        if(this->type() == base.type()){
            return this->data() == dynamic_cast<const DerivedInt*>(&base)->data();
        }
        return false;
    }

    std::string to_string() const override {
        return std::to_string(_int);
    }

private:
    int _int;
};