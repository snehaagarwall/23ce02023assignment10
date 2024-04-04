#include <stdio.h>

// Enumeration for pay type
enum PayType {
    HOURLY,
    SALARY
};

// Union containing employee details based on pay type
union EmpDetails {
    struct {
        float hourly_wage;
    } hourly_details;
    struct {
        double fixed_salary;
    } salary_details;
};

// Structure representing an employee
struct Employee {
    int emp_id;
    char name[100]; // Assuming a maximum name length of 100 characters
    enum PayType pay_type;
    union EmpDetails emp_details;
};

// Function to print employee details
void printEmployee(struct Employee emp) {
    printf("Employee ID: %d\n", emp.emp_id);
    printf("Name: %s\n", emp.name);
    printf("Pay Type: %s\n", emp.pay_type == HOURLY ? "Hourly" : "Salary");

    // Accessing and printing employee details based on pay type
    if (emp.pay_type == HOURLY) {
        printf("Hourly Wage: %.2f\n", emp.emp_details.hourly_details.hourly_wage);
    } else {
        printf("Fixed Salary: %.2f\n", emp.emp_details.salary_details.fixed_salary);
    }
    printf("\n");
}

int main() {
    // Declare an employee
    struct Employee emp;

    // Assign values for an hourly employee
    emp.emp_id = 101;
    emp.pay_type = HOURLY;
    strcpy(emp.name, "Aman");
    emp.emp_details.hourly_details.hourly_wage = 15.75;

    // Print employee details
    printf("Employee Details:\n");
    printEmployee(emp);

    // Assign values for a salaried employee
    emp.emp_id = 102;
    emp.pay_type = SALARY;
    strcpy(emp.name, "Karan");
    emp.emp_details.salary_details.fixed_salary = 60000.00;

    // Print employee details
    printf("Employee Details:\n");
    printEmployee(emp);

    return 0;
}
