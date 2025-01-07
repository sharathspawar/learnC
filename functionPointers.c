#include <stdio.h>

// A simple function
void greet() {
    printf("Hello, world!\n");
}

// Function pointer
int main() {
    void (*func_ptr)() = greet; // Storing the address of greet() in the function pointer

    func_ptr(); // Calling greet() using the function pointer
    return 0;
}


// Explanation:

//     A function pointer stores the address of a function.
//     The function is called indirectly using the pointer.