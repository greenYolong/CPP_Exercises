#pragma once 

#define JAI_LU_LE_WARNING_09 true
#define JAI_LU_LE_WARNING_13 true
#include <ostream>
#include <memory>

class Base {
public:


    virtual bool is_null() const = 0;



    std::string type() const { return _type; };

    virtual std::unique_ptr<Base> clone() const = 0;

    bool operator==(const Base& base) const {
        return this->equals(base);
    }

    friend std::ostream& operator<<(std::ostream& os, const Base& base) {
        return os << base.to_string();
    }

protected:
    Base(const std::string& type) : _type { type } {}

    virtual std::string to_string() const = 0;
    virtual bool equals(const Base& base) const = 0;

private:
    std::string _type;
};