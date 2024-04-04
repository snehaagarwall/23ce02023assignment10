#include <stdio.h>
#include <string.h>

// Define a union named EmpDetails
union EmpDetails {
    float hourly_wage;
    double fixed_salary;
};

// Define a structure named Employee
struct Employee {
    int emp_id;
    char name[100]; 
    union EmpDetails emp_details;
};

int main() {
    // Declare a variable of type Employee
    struct Employee emp;

    // Assign values to the members of the structure
    emp.emp_id = 101;
    strcpy(emp.name, "John Doe");
    emp.emp_details.hourly_wage = 15.75; // Assigning hourly wage

    // Access and print the values
    printf("Employee ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Hourly Wage: %.2f\n", emp.emp_details.hourly_wage);
   

    return 0;
}
