#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int main() {
    // Using bool from <stdbool.h>
    bool is_valid = true;       // Boolean variable
    bool is_greater = false;

    // Fixed-width integers from <stdint.h>
    int32_t a = 42;             // 32-bit signed integer
    int32_t b = -10;

    // Perform boolean checks
    if (a > b) {
        is_greater = true;
    }

    // Print results
    printf("is_valid: %s\n", is_valid ? "true" : "false");
    printf("is_greater: %s\n", is_greater ? "true" : "false");

    // Demonstrating a logical operation
    bool result = is_valid && is_greater;
    printf("result (is_valid && is_greater): %s\n", result ? "true" : "false");

    // Using bool in an array
    bool flags[5] = {true, false, true, false, true};
    printf("Boolean array values:\n");
    for (size_t i = 0; i < 5; ++i) {
        printf("flags[%zu]: %s\n", i, flags[i] ? "true" : "false");
    }

    // Boolean conditions in loops
    size_t counter = 0;
    while (is_valid) {
        printf("Counter: %zu\n", counter);
        counter++;
        if (counter == 3) {
            is_valid = false; // Set is_valid to false to exit loop
        }
    }

    return 0;
}




// Features Covered:

//     Basic boolean usage:
//         Declaring and initializing bool variables.
//         Using true and false values.
//     Combining boolean logic:
//         Logical operations such as &&, ||, and !.
//     Integration with fixed-width integers:
//         Comparing integers and assigning results to bool variables.
//     Boolean arrays:
//         Using bool in arrays to represent states or flags.
//     Boolean conditions in loops:
//         Controlling loops with bool values.

// Output Example:

// When you compile and run the program (gcc -std=c99 -o bool_demo bool_demo.c && ./bool_demo), you might see output like this:

// is_valid: true
// is_greater: true
// result (is_valid && is_greater): true
// Boolean array values:
// flags[0]: true
// flags[1]: false
// flags[2]: true
// flags[3]: false
// flags[4]: true
// Counter: 0
// Counter: 1
// Counter: 2







// The C code demonstrates the usage of the stdbool.h header file, which provides a standardized way to work with boolean values in C99 and later. Prior to this header, C didn't have a built-in boolean type, and integers were often used to represent true/false values.

// Here's a breakdown:

// #include <stdbool.h>: This line includes the header file that defines the bool data type, as well as the macros true and false.

// bool variables: The code declares boolean variables like is_valid and is_greater using the bool type. These variables can store either true (representing 1) or false (representing 0).

// Boolean checks and conditions: The code uses boolean variables in if statements and while loops to control the flow of execution, much like you would in languages with built-in boolean types.

// Logical operations: The code shows how standard logical operations like && (AND) and || (OR) can be used with bool variables.

// Boolean arrays: bool can be used to create arrays of boolean values, as shown with the flags array. This can be useful for storing a series of on/off or true/false states.

// Printing boolean values: When printing bool variables using printf, the code uses the ternary operator (condition ? true_case : false_case) to output "true" or "false" strings, making the output more readable.

// In essence, stdbool.h adds a dedicated boolean type to C, improving code clarity and making it more consistent with other languages that have explicit boolean types.