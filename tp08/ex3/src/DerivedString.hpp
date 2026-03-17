#pragma once

#include "Base.hpp"

#include <string>


class DerivedString : public Base {
public :
    DerivedString(const std::string& str) : Base { "String" }, _str { str } {}

    bool is_null() const override { return _str == ""; }

    const std::string& data() const { return _str; }

    std::string type() const { return "String"; }

    std::unique_ptr<Base> clone() const {
        return std::make_unique<DerivedString>(*this);
    }

    bool equals(const Base& base) const override {
        if(this->type() == base.type()){
            return this->data() == dynamic_cast<const DerivedString*>(&base)->data();
        }
        return false;
    }

    std::string to_string() const override {
        return _str;
    }

private:
    std::string _str;
};