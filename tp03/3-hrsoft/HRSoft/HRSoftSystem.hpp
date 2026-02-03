#pragma once

#include <list>
#include <string>
#include <iostream>

#include "Department.hpp"

class HRSoftSystem
{
public:
  Department& add_department(const std::string& name)
  {
    return _departments.emplace_back(name);
  }

  void remove_employee(const Employee& employee){
    for(auto& departement: _departments){
      department.remove_employee(employee);
    }
  }

  void print_all_departments() const {
    for(auto& department: _departments){
      std::cout << department << std::endl;
    }
  }

  void print_all_employees() const {
    for(auto& department: _departments){
      department.print_employees();
    }
  }

private:
  std::list<Department> _departments;
};
