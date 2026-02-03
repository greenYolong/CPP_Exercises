#pragma once

#include <list>
#include <ostream>
#include <string>

class Employee
{
public:
  Employee(const std::string& name, unsigned int salary)
      : _name{name}, _salary{salary}
  {}

  void add_subordinate(Employee& subordinate)
  {
    _subordinates.emplace_back(&subordinate);
  }

  void remove_employee(const Employee& employee) {
    std::erase_if(_subordinates, [](Employee e){return e == employee;});
  }

  void print_subordinates() const {
    if(_subordinates.empty()){
      std::cout << _name << " has no subordinates !" << std::endl;
      return;
    }
    std::cout << "Subordinates of " << _name << ":" << std::endl;
    for(auto employee: _subordinates){
      std::cout << employee->_name << " ";
    }
    std::cout << std::endl;
  }

  friend std::ostream& operator<<(std::ostream&, const Employee&);

private:
  std::string _name;
  unsigned int _salary = 0;
  std::list<Employee*> _subordinates;
};

inline std::ostream& operator<<(std::ostream& stream, const Employee& employee)
{
  const auto is_manager = !employee._subordinates.empty();
  return stream << employee._name << " (salary: " << employee._salary
                << "| manager: " << (is_manager ? "yes" : "no") << ")";
}
