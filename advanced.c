#include <stdio.h>

// Function to demonstrate a simple recursive function
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case: factorial of 0 is 1
    } else {
        return n * factorial(n - 1); // Recursive case
    }
}

// Function to demonstrate multi-dimensional array (matrix multiplication)
void matrixMultiplication(int A[2][2], int B[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to display an array (used for demonstrating user input)
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // 1. Array Application: Simple array manipulation
    int array[5] = {1, 2, 3, 4, 5};
    printf("Array before manipulation:\n");
    displayArray(array, 5);
    
    // Manipulating array elements (e.g., incrementing each element)
    for (int i = 0; i < 5; i++) {
        array[i] += 2; // Incrementing each element by 2
    }
    
    printf("Array after manipulation:\n");
    displayArray(array, 5);

    // 2. User Input: Taking input from the user
    int userInput[5];
    printf("Enter 5 integers: ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &userInput[i]); // Reading integers from user input
    }
    
    printf("You entered: ");
    displayArray(userInput, 5);

    // 3. Multi-dimensional Array: Matrix multiplication (2x2 matrices)
    int matrixA[2][2] = {{1, 2}, {3, 4}};
    int matrixB[2][2] = {{5, 6}, {7, 8}};
    int resultMatrix[2][2];
    
    matrixMultiplication(matrixA, matrixB, resultMatrix);
    
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    // 4. Memory Address and Pointers: Demonstrating pointers and memory addresses
    int number = 10;
    int *pointer = &number; // Pointer to the memory address of 'number'
    
    printf("\nMemory Address and Pointers:\n");
    printf("Value of 'number': %d\n", number);
    printf("Memory address of 'number': %p\n", (void*)&number);
    printf("Value stored at the pointer (value of 'number'): %d\n", *pointer);
    printf("Pointer's memory address: %p\n", (void*)&pointer);

    // 5. Functions: Calling a function with a return value
    printf("\nFunction Example (Factorial):\n");
    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));

    // 6. Scope: Demonstrating variable scope (local and global)
    int globalVar = 100; // Global variable

    printf("\nScope Example:\n");
    printf("Global variable value: %d\n", globalVar);

    // Local variable inside main() function
    int localVar = 50;
    printf("Local variable value: %d\n", localVar);

    // 7. Recursion: Factorial function (already demonstrated)
    printf("\nRecursion Example (Factorial of 5): %d\n", factorial(5));

    return 0;
}


// Explanation:

//     Array Application:
//         The program first defines a simple array of integers (array[5]) and performs a manipulation on it by incrementing each element by 2. The array is then displayed before and after the manipulation.

//     User Input:
//         The program prompts the user to enter 5 integers, which are stored in an array (userInput[5]). It then displays the user input back to them.

//     Multi-dimensional Array:
//         The program demonstrates matrix multiplication of two 2x2 matrices (matrixA and matrixB). It calls a function matrixMultiplication() that performs the matrix multiplication and stores the result in a third matrix (resultMatrix).

//     Memory Address and Pointers:
//         The program demonstrates how pointers work in C. A pointer (pointer) is created that stores the memory address of the variable number. It also shows how to access the value stored at a pointer (*pointer) and print the memory address.

//     Functions:
//         The program defines a simple factorial() function that calculates the factorial of a number using recursion. This function is called from the main() function to calculate and display the factorial of 5.

//     Scope:
//         The program illustrates the concept of variable scope with both a global variable (globalVar) and a local variable (localVar). It shows how the local variable is only accessible within the main() function, whereas the global variable can be accessed throughout the entire program.

//     Recursion:
//         The program calls the factorial() function recursively. It uses recursion to calculate the factorial of a number, which is a common application of recursion in programming.

// Outputs:

//     The program will display the results of array manipulation, matrix multiplication, memory addresses, factorial calculations, and variable scope.
//     It will prompt the user to enter 5 integers and display them back.




// This C code demonstrates several fundamental programming concepts including arrays, user input, multi-dimensional arrays (matrices), pointers, functions, scope, and recursion. Let's break down each part:

// 1. Functions:

// factorial(int n): This function calculates the factorial of a given integer n using recursion.

// Base Case: If n is 0, it returns 1 (factorial of 0 is 1).
// Recursive Case: Otherwise, it returns n multiplied by the factorial of n-1. This continues until the base case is reached.
// matrixMultiplication(int A[2][2], int B[2][2], int result[2][2]): This function performs matrix multiplication of two 2x2 matrices (A and B) and stores the result in the result matrix. It uses nested loops to iterate through the rows and columns of the matrices and apply the standard matrix multiplication algorithm.

// displayArray(int arr[], int size): This utility function takes an integer array (arr) and its size (size) as input and prints the elements of the array to the console.

// 2. main() Function:

// Array Manipulation:

// An integer array array is initialized with values {1, 2, 3, 4, 5}.
// The displayArray function prints the original array.
// A for loop iterates through the array, adding 2 to each element.
// displayArray is called again to show the modified array.
// User Input:

// An integer array userInput of size 5 is declared.
// The program prompts the user to enter 5 integers.
// A for loop uses scanf to read the integers entered by the user and store them in the userInput array.
// displayArray prints the array containing the user's input.
// Matrix Multiplication:

// Two 2x2 integer matrices, matrixA and matrixB, are initialized.
// matrixMultiplication is called to multiply these matrices, and the result is stored in resultMatrix.
// Nested loops print the resultMatrix to the console.
// Pointers and Memory Addresses:

// An integer variable number is initialized to 10.
// An integer pointer pointer is declared and assigned the address of number using the address-of operator &.
// The program prints the value of number, its memory address, the value pointed to by pointer (which is the same as the value of number), and the memory address of the pointer itself. The (void*) casts are used to ensure correct printing of pointer addresses.
// Function Call (Factorial):

// An integer num is initialized to 5.
// The factorial function is called with num as an argument, and the returned value (factorial of 5) is printed.
// Scope:

// globalVar is declared outside any function, making it a global variable accessible throughout the program.
// localVar is declared inside main(), making it a local variable accessible only within main().
// The program prints the values of both variables to demonstrate scope.
// Recursion (Factorial - already demonstrated):

// The factorial function is called again (as it was in the earlier function demonstration) with 5 as input, and the result is printed. This reinforces the concept of recursion.
// This code provides a practical demonstration of various C programming concepts. It's a good example for learning how arrays, pointers, functions, and recursion work in C. The comments and clear structure make the code relatively easy to follow.