#include <stdio.h>

// Defining a structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Defining a union
union Data {
    int intVal;
    float floatVal;
    char charVal;
};

int main() {
    // Structure example
    struct Employee emp1 = {1, "John Doe", 50000.50};
    printf("Employee ID: %d, Name: %s, Salary: %.2f\n", emp1.id, emp1.name, emp1.salary);

    // Union example
    union Data data;
    data.intVal = 10;
    printf("Union integer: %d\n", data.intVal);
    data.floatVal = 3.14;
    printf("Union float: %.2f\n", data.floatVal);

    // Only one of the union members can be used at a time

    return 0;
}

// Explanation:

//     A struct is a user-defined data type that allows combining different data types.
//     A union allows different data types to share the same memory location, but only one member can hold a value at any given time.
    
