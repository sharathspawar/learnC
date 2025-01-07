#include <stdio.h>
#include <string.h>  // For string operations (e.g., strcpy)

// Define the structure for Date (nested structure example)
struct Date {
    int day;
    int month;
    int year;
};

// Define the structure for Address
struct Address {
    char street[100];
    char city[50];
    char state[50];
    int zipCode;
};

// Define the structure for Employee, which contains other structures (nested structure)
struct Employee {
    int id;
    char name[50];
    struct Date hireDate;   // Nested structure for hire date
    struct Address address; // Nested structure for address
    float salary;
};

// Function to print Employee details (by value)
void printEmployee(struct Employee e) {
    printf("\nEmployee ID: %d\n", e.id);
    printf("Employee Name: %s\n", e.name);
    printf("Hire Date: %d/%d/%d\n", e.hireDate.day, e.hireDate.month, e.hireDate.year);
    printf("Address: %s, %s, %s, %d\n", e.address.street, e.address.city, e.address.state, e.address.zipCode);
    printf("Salary: %.2f\n", e.salary);
}

// Function to update Employee salary (passing structure by reference)
void updateSalary(struct Employee *e, float newSalary) {
    e->salary = newSalary;  // Modify salary directly using pointer
}

// Function to initialize an Employee structure
void initializeEmployee(struct Employee *e, int id, const char* name, int day, int month, int year, 
                        const char* street, const char* city, const char* state, int zip, float salary) {
    e->id = id;
    strcpy(e->name, name);  // Using strcpy to copy string into structure member
    e->hireDate.day = day;
    e->hireDate.month = month;
    e->hireDate.year = year;
    strcpy(e->address.street, street);
    strcpy(e->address.city, city);
    strcpy(e->address.state, state);
    e->address.zipCode = zip;
    e->salary = salary;
}

// Function to initialize an array of Employee structures
void initializeEmployees(struct Employee employees[], int size) {
    // Example initialization for the first employee
    initializeEmployee(&employees[0], 101, "John Doe", 15, 5, 2015, "123 Main St", "New York", "NY", 10001, 50000.00);
    // Example initialization for the second employee
    initializeEmployee(&employees[1], 102, "Jane Smith", 20, 8, 2018, "456 Elm St", "Los Angeles", "CA", 90001, 55000.00);
    // Example initialization for the third employee
    initializeEmployee(&employees[2], 103, "Alice Brown", 10, 3, 2020, "789 Oak St", "Chicago", "IL", 60007, 60000.00);
}

int main() {
    // Initialize a single Employee structure
    struct Employee e1;
    initializeEmployee(&e1, 1001, "James White", 1, 1, 2010, "101 Park Ave", "San Francisco", "CA", 94101, 75000.00);

    // Print Employee details
    printf("Employee e1 details:\n");
    printEmployee(e1);

    // Update salary of the employee by passing structure reference
    updateSalary(&e1, 80000.00);
    printf("\nUpdated salary for e1:\n");
    printEmployee(e1);

    // Create and initialize an array of Employee structures
    struct Employee employees[3];
    initializeEmployees(employees, 3);

    // Print details of employees in the array
    printf("\nDetails of all employees in the array:\n");
    for (int i = 0; i < 3; i++) {
        printEmployee(employees[i]);
    }

    // Pointer to Employee structure
    struct Employee *ptr = &employees[0];
    printf("\nAccessing employee using pointer:\n");
    printf("Employee Name: %s, Salary: %.2f\n", ptr->name, ptr->salary); // Access using pointer and arrow operator

    return 0;
}


// Detailed Breakdown:

//     Structure Definitions:
//         struct Date: Represents the hire date of an employee.
//         struct Address: Represents the address of an employee (street, city, state, zip code).
//         struct Employee: Represents the employee, which contains:
//             An integer id for the employee's ID.
//             A string name for the employee's name.
//             A hireDate of type struct Date (nested structure).
//             An address of type struct Address (nested structure).
//             A salary to store the employee's salary.

//     Function to Initialize an Employee:
//         initializeEmployee(): This function initializes an employee structure by accepting multiple parameters, including data for hireDate and address structures.
//         The function uses strcpy to copy string values into the name and address fields since you can't assign string literals directly to character arrays in C.

//     Function to Print Employee Details:
//         printEmployee(): This function takes an employee structure as a parameter (by value) and prints the details. It accesses nested structures (hireDate and address) using the dot operator.

//     Passing Structures to Functions:
//         updateSalary(): This function demonstrates passing a structure by reference (pointer). The salary of an employee can be updated directly through the pointer.

//     Array of Structures:
//         initializeEmployees(): Initializes an array of employee structures (employees[3]) and sets the values for each employee using the initializeEmployee() function.

//     Structure Pointer:
//         A pointer ptr to an employee structure is created, and the -> operator is used to access structure members.

//     Output:
//         The program first creates a single employee, prints their details, then updates the salary and prints again.
//         Then, it creates an array of employees, initializes them, and prints the details of each employee.
//         It also demonstrates how to access structure members using a pointer.






// Expected Output:

// Employee e1 details:
// Employee ID: 1001
// Employee Name: James White
// Hire Date: 1/1/2010
// Address: 101 Park Ave, San Francisco, CA, 94101
// Salary: 75000.00

// Updated salary for e1:
// Employee ID: 1001
// Employee Name: James White
// Hire Date: 1/1/2010
// Address: 101 Park Ave, San Francisco, CA, 94101
// Salary: 80000.00

// Details of all employees in the array:
// Employee ID: 101
// Employee Name: John Doe
// Hire Date: 15/5/2015
// Address: 123 Main St, New York, NY, 10001
// Salary: 50000.00

// Employee ID: 102
// Employee Name: Jane Smith
// Hire Date: 20/8/2018
// Address: 456 Elm St, Los Angeles, CA, 90001
// Salary: 55000.00

// Employee ID: 103
// Employee Name: Alice Brown
// Hire Date: 10/3/2020
// Address: 789 Oak St, Chicago, IL, 60007
// Salary: 60000.00

// Accessing employee using pointer:
// Employee Name: John Doe, Salary: 50000.00