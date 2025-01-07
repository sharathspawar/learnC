#include <stdio.h>
#include <stdlib.h>

// Constants for buffer size and error handling
#define MAX_LIST_SIZE 100
#define MEMORY_ALLOCATION_FAILED "Memory allocation failed"

typedef struct Node {
    int data;               // Data stored in the node
    struct Node* next;      // Pointer to the next node in the list
} Node;

// Function Prototypes
Node* createNode(int data);
void insertNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);
void freeList(Node* head);

int main() {
    Node* head = NULL;  // Initialize an empty linked list

    // Insert nodes
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    printf("Linked List: ");
    printList(head);

    // Delete a node
    deleteNode(&head, 20);
    printf("\nLinked List after deleting 20: ");
    printList(head);

    // Free the memory used by the list
    freeList(head);

    return 0;
}

/**
 * Function: createNode
 * Description: Allocates memory for a new node and initializes it with the given data.
 * Input: int data - the value to store in the node
 * Output: A pointer to the newly created node
 */
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for the node
    if (newNode == NULL) {
        printf("%s\n", MEMORY_ALLOCATION_FAILED);
        exit(1);  // Exit if memory allocation fails
    }
    newNode->data = data;  // Set the node's data
    newNode->next = NULL;   // Set the next pointer to NULL
    return newNode;
}

/**
 * Function: insertNode
 * Description: Inserts a new node at the beginning of the linked list.
 * Input: Node** head - pointer to the head pointer of the list
 *        int data - the data to insert into the node
 */
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);  // Create a new node
    newNode->next = *head;  // Point the new node to the current head
    *head = newNode;        // Update the head to point to the new node
}

/**
 * Function: deleteNode
 * Description: Deletes the first occurrence of a node with the given data.
 * Input: Node** head - pointer to the head pointer of the list
 *        int data - the data of the node to delete
 */
void deleteNode(Node** head, int data) {
    if (*head == NULL) return;  // Return if the list is empty

    Node* temp = *head;

    // If the node to delete is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Change the head to the next node
        free(temp);          // Free the old head
        return;
    }

    // Search for the node to delete
    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the data was not found
    if (temp == NULL) return;

    // Unlink the node from the list
    prev->next = temp->next;
    free(temp);  // Free the memory occupied by the node
}

/**
 * Function: printList
 * Description: Prints the entire linked list.
 * Input: Node* head - pointer to the head of the list
 */
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * Function: freeList
 * Description: Frees the memory used by the linked list.
 * Input: Node* head - pointer to the head of the list
 */
void freeList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);  // Free the current node
        current = nextNode;
    }
}

// Top 10 C Coding Best Practices with Example:

//     Consistent Naming Conventions:
//         Use clear and consistent naming conventions for variables, functions, and other identifiers.
//         Camel Case for variables and functions: myVariable, calculateArea.
//         Uppercase with underscores for constants: MAX_BUFFER_SIZE.
//         Prefix struct types: struct Point, struct Employee.

//     Commenting and Documentation:
//         Write clear and concise comments to explain the purpose and logic of the code.
//         Use docstrings for functions to describe input parameters, output, and behavior.

//     Modular Code with Functions:
//         Break the code into functions, each doing one task (Single Responsibility Principle).
//         Avoid writing long functions.

//     Error Handling:
//         Always check for errors, especially in system calls, memory allocations, and I/O operations.
//         Handle errors gracefully and provide meaningful error messages.

//     Memory Management:
//         Use memory allocation (malloc, calloc, realloc) and deallocation (free) properly.
//         Avoid memory leaks by freeing allocated memory when it is no longer needed.

//     Use Constants Instead of Magic Numbers:
//         Replace magic numbers with named constants to improve code readability and maintainability.

//     Optimize for Readability and Maintainability:
//         Write code that is easy to read and maintain, not just code that works.
//         Refactor code to improve readability without sacrificing performance.

//     Minimize Global Variables:
//         Limit the use of global variables as much as possible. Use local variables or pass parameters to functions.

//     Consistent Indentation and Formatting:
//         Use consistent indentation (typically 4 spaces) and formatting to improve readability.
//         Follow a consistent style guide for braces and spaces.

//     Unit Testing:
//         Write unit tests to ensure the correctness of your functions and modules.
//         Automate tests to quickly catch bugs during development.





// Explanation of Best Practices Used:

//     Consistent Naming Conventions:
//         Function names (createNode, insertNode, deleteNode, printList, freeList) are descriptive and use CamelCase.
//         Constants (MAX_LIST_SIZE, MEMORY_ALLOCATION_FAILED) are written in uppercase with underscores.
//         Variable names (head, data, temp, prev) are simple and descriptive.

//     Commenting and Documentation:
//         Each function has a comment block explaining its purpose, inputs, and outputs.
//         Inline comments clarify complex code segments (e.g., memory allocation checks).

//     Modular Code with Functions:
//         The program is broken down into small, reusable functions: createNode, insertNode, deleteNode, printList, and freeList.

//     Error Handling:
//         The program checks if memory allocation fails and exits the program with an error message (MEMORY_ALLOCATION_FAILED).

//     Memory Management:
//         The program uses malloc to allocate memory and free to release memory. The freeList function ensures that all allocated memory is properly freed.

//     Use Constants Instead of Magic Numbers:
//         MAX_LIST_SIZE is defined, but it is not directly used in this program. It's good practice to define constants even if you don't use them immediately.

//     Optimize for Readability and Maintainability:
//         The program is clear, modular, and each function serves a single responsibility.

//     Minimize Global Variables:
//         The program uses the head pointer locally within the main function and passes it by reference to other functions. There are no global variables.

//     Consistent Indentation and Formatting:
//         The program uses 4 spaces for indentation, ensuring the code is properly aligned and easy to read.

//     Unit Testing:
//         While this program doesn't include formal unit tests, you can easily extend it by writing unit tests for the insertNode, deleteNode, and freeList functions to ensure they work as expected.

// Conclusion:

// This program follows the best coding practices to ensure the code is clean, maintainable, and easy to understand. It uses error handling, modular design, memory management, and consistent naming conventions, all of which are essential practices followed by top C programmers and industrial standards. These practices enhance collaboration, code readability, and maintainability, making the program easier to scale and modify in the future.