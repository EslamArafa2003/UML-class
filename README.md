The code defines a base class Employee with member variables for name, employee ID, and salary. It also has a pure virtual function get_total_salary that must be overridden by derived classes. The print function is used to display the employee's information.

The Sales and Engineer classes inherit from Employee and add their own specific member variables. The get_total_salary function is overridden in each class to calculate the total salary based on the employee's commission rate or overtime hours.

The main function creates instances of the Sales and Engineer classes and demonstrates how to call their member functions.
