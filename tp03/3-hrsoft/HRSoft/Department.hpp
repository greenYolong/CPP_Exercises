#pragma once

#include "Employee.hpp"

#include <list>
#include <string>
#include <iostream>
#include <ostream>

class Department
{
public:
  Department(const std::string& name) : _name{name} {}

  Employee& add_employee(const std::string& name, unsigned int salary,
                         Employee* manager)
  {
    auto& employee = _employees.emplace_back(name, salary);

    if (manager != nullptr)
      manager->add_subordinate(employee);

    return employee;
  }

  void remove_employee(const Employee& employee){
    for(auto& slave: _employees){
      slave.remove_employee(employee);
    }
    std::erase_if(_employees, [](Employee e){return e == employee;});
  }

  void print_employees() const {
    for(auto& employee: _employees){
      std::cout << employee << " ";
    }
    std::cout << std::endl;
  }

  friend std::ostream& operator<<(std::ostream&, const Department&);

private:
  std::string _name;
  std::list<Employee> _employees;
};

inline std::ostream& operator<<(std::ostream& stream, const Department& department)
{
  stream << department._name << " : \n";
  for(auto& employee: department._employees){
    stream << employee << " ";
  }
  return stream << std::endl;
}