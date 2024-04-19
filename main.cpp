#include <iostream>

class Employee {
public:
  std::string name;
  int emp_id;
  double salary;

  Employee(std::string name, int emp_id, double salary) {
    this->name = name;
    this->emp_id = emp_id;
    this->salary = salary;
  }

  virtual double get_total_salary() = 0;

  void print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Employee ID: " << emp_id << std::endl;
    std::cout << "Salary: " << salary << std::endl;
  }
};

class Sales : public Employee {
public:
  float gross_sales;
  float commission_rate;

  Sales(std::string name, int emp_id, double salary, float gross_sales,
        float commission_rate)
      : Employee(name, emp_id, salary), gross_sales(gross_sales),
        commission_rate(commission_rate) {}

  double get_total_salary() override {
    return salary + (gross_sales * commission_rate);
  }

  void set_gross_sales(float gross_sales) { this->gross_sales = gross_sales; }

  void set_commission_rate(float commission_rate) {
    this->commission_rate = commission_rate;
  }
};

class Engineer : public Employee {
public:
  int experience;
  std::string specialty;
  int overtime_hours;
  float overtime_hour_rate;

  Engineer(std::string name, int emp_id, double salary, int experience,
           std::string specialty, int overtime_hours, float overtime_hour_rate)
      : Employee(name, emp_id, salary), experience(experience),
        specialty(specialty), overtime_hours(overtime_hours),
        overtime_hour_rate(overtime_hour_rate) {}

  double get_total_salary() override {
    return salary + (overtime_hours * overtime_hour_rate);
  }

  void set_overtime_hours(int overtime_hours) {
    this->overtime_hours = overtime_hours;
  }

  void set_overtime_hour_rate(float overtime_hour_rate) {
    this->overtime_hour_rate = overtime_hour_rate;
  }
};

int main() {
  Sales employee1("John Doe", 12345, 50000, 100000, 0.1);
  Engineer employee2("Jane Smith", 54321, 70000, 10, "Software Engineering", 20,
                     50);

  employee1.print();
  std::cout << "Total Salary: " << employee1.get_total_salary() << std::endl;

  employee2.print();
  std::cout << "Total Salary: " << employee2.get_total_salary() << std::endl;

  return 0;
}
