#include "Value.hpp"

std::ostream& operator<<(std::ostream& os, const Value value){
    switch(value)
    {
        case Value::Jack  : os << "Valet"; break;
        case Value::Queen : os << "Reine"; break;
        case Value::King  : os << "Roi";   break;
        case Value::Ace   : os << "Ace";   break;
        default           : os << (unsigned) value; break;
    }
    return os;
}

std::vector<Value> all_value = { (Value) 7u , Value::Eight, Value::Nine, Value::Ten, Value::Jack, Value::Queen, Value::King, Value::Ace };