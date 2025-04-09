#include <stdio.h>

// Function that takes pointer as argument and modifies the value
void square(int *num) {
    *num = (*num) * (*num); // Dereferencing pointer to modify actual value
}

int main() {
    // 1. Basic Pointer Declaration and Initialization
    int a = 10;
    int *p; // Declare pointer to int
    p = &a; // Assign address of 'a' to pointer 'p'

    printf("Value of a = %d\n", a);
    printf("Address of a = %p\n", &a);
    printf("Pointer p stores address = %p\n", p);
    printf("Value pointed to by p = %d\n\n", *p); // Dereferencing

    // 2. Modifying value using pointer
    *p = 20; // Change value of 'a' using pointer
    printf("New value of a after modifying via pointer = %d\n\n", a);

    // 3. Pointer Arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Points to first element of array

    printf("Array elements using pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i)); // Equivalent to arr[i]
    }
    printf("\n");

    // 4. Pointers and Arrays
    printf("Accessing array using pointer indexing:\n");
    for (int i = 0; i < 5; i++) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    printf("\n");

    // 5. Passing Pointers to Functions
    int number = 5;
    printf("Original number = %d\n", number);
    square(&number); // Pass address of number
    printf("Number after square function = %d\n", number);

    // 6. NULL Pointer
    int *nullPtr = NULL;
    if (nullPtr == NULL) {
        printf("\nnullPtr is NULL, cannot be dereferenced.\n");
    }

    return 0;
}
