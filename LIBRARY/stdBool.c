#include <stdio.h>
#include <stdbool.h>  // Include the stdbool.h header to use bool, true, false

// Function to check if a number is even
bool is_even(int num) {
    return num % 2 == 0;  // Returns true if the number is even, false otherwise
}

// Function to check if a number is positive
bool is_positive(int num) {
    return num > 0;  // Returns true if the number is positive, false otherwise
}

int main() {
    int num;
    bool result;  // Variable to hold the boolean result

    // Ask the user for a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the number is even
    result = is_even(num);
    if (result) {
        printf("%d is even.\n", num);
    } else {
        printf("%d is odd.\n", num);
    }

    // Check if the number is positive
    result = is_positive(num);
    if (result) {
        printf("%d is positive.\n", num);
    } else {
        printf("%d is negative or zero.\n", num);
    }

    // Use boolean operations to combine conditions
    if (is_even(num) && is_positive(num)) {
        printf("%d is even and positive.\n", num);
    } else if (is_even(num) && !is_positive(num)) {
        printf("%d is even but not positive.\n", num);
    }

    return 0;
}



// The <stdbool.h> header file in C is part of the C99 standard and defines a boolean data type (bool) and the constants true and false. It provides a standardized way of working with boolean values, making the code more readable and expressive. Before C99, C did not have a dedicated boolean type, and int was often used with values like 0 and 1 to represent false and true, respectively.
// Key Features of <stdbool.h>:

//     bool: A type that represents boolean values (true or false).
//     true: A constant representing the boolean value true (1).
//     false: A constant representing the boolean value false (0).

// Overview:

//     The bool type can be used to store logical values (either true or false).
//     true is defined as 1.
//     false is defined as 0.


// Explanation of the Code:

//     Including <stdbool.h>:
//         #include <stdbool.h> allows us to use the bool, true, and false types and constants in our program.

//     Boolean Functions:
//         is_even(int num): This function checks whether the given number is even. It returns true if the number is divisible by 2, and false otherwise.
//         is_positive(int num): This function checks whether the given number is positive. It returns true if the number is greater than 0, and false otherwise.

//     Using bool for Logic:
//         In the main() function, we use the bool variable result to store the outcome of logical tests (e.g., checking if a number is even or positive).
//         We use if statements to print appropriate messages based on the result of these checks.

//     Boolean Operations:
//         In the last conditional block, we demonstrate using boolean operators like && (AND) and ! (NOT) to combine conditions:
//             is_even(num) && is_positive(num) checks if the number is both even and positive.
//             is_even(num) && !is_positive(num) checks if the number is even but not positive.

// Key Concepts:

//     bool Type:
//         The bool type is used to represent logical values. It can only hold true (1) or false (0), which are defined in <stdbool.h>.

//     Boolean Constants:
//         true: Represents a logical true, which is equivalent to 1.
//         false: Represents a logical false, which is equivalent to 0.

//     Logical Operators:
//         && (Logical AND): Evaluates to true if both operands are true.
//         || (Logical OR): Evaluates to true if at least one operand is true.
//         ! (Logical NOT): Negates the logical value, turning true to false and vice versa.

// Compilation:

// To compile the program, use the following command:

// gcc -o bool_example bool_example.c

// Execution:

// Run the program with:

// ./bool_example

// Sample Output:
// Example 1: Checking an Even and Positive Number

// Enter a number: 4
// 4 is even.
// 4 is positive.
// 4 is even and positive.

// Example 2: Checking an Odd and Negative Number

// Enter a number: -3
// -3 is odd.
// -3 is negative or zero.
// -3 is even but not positive.

// Summary:

//     <stdbool.h> provides the bool type and constants true and false to represent boolean values, which were previously not available in C.
//     The bool type is used for logical conditions, which makes the code more readable and expressive compared to using integers (0 and 1).
//     Boolean operators like && (AND), || (OR), and ! (NOT) are commonly used to combine or negate boolean expressions.
//     The use of bool, true, and false improves the clarity of the code, especially when dealing with logical conditions.

// This example demonstrates how to use <stdbool.h> to handle boolean logic in a simple program, making the code more intuitive and easy to maintain.
