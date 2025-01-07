#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int size = 5;
    
    // Using malloc to allocate memory
    arr = (int*) malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initializing values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    // Printing the array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Using realloc to resize the array
    size = 10;
    arr = (int*) realloc(arr, size * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    // Initializing new values
    for (int i = 5; i < size; i++) {
        arr[i] = i * 10;
    }

    // Printing the resized array
    printf("\nResized array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Freeing the memory
    free(arr);

    return 0;
}


// Explanation:

//     malloc: Allocates memory for a specified number of elements of a given size.
//     calloc: Similar to malloc, but it also initializes the allocated memory to zero.
//     realloc: Resizes previously allocated memory.
//     free: Frees the dynamically allocated memory to avoid memory leaks.