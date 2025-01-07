#include <stdio.h>

struct {
    unsigned int width : 5;
    unsigned int height : 7;
} rectangle;

int main() {
    rectangle.width = 31; // Maximum value for 5 bits
    rectangle.height = 100; // Maximum value for 7 bits

    printf("Width: %d, Height: %d\n", rectangle.width, rectangle.height);
    return 0;
}

// Explanation:

//     Bit fields allow you to define how many bits each member of a structure will take up, which is useful for memory-efficient data storage.


// This C code demonstrates the use of bit fields within a structure. Bit fields allow you to specify the number of bits used to store a member of a structure, providing fine-grained control over memory usage.

// Explanation:

// Structure Definition:

// struct {
//     unsigned int width : 5;
//     unsigned int height : 7;
// } rectangle;
// An unnamed structure is declared. This means you can't create other variables of this structure type directly; only this single instance rectangle exists.
// Inside the structure, two members are defined: width and height.
// The : 5 after width specifies that it should be stored using only 5 bits. The maximum value that can be stored in 5 bits is 31 (2⁵ - 1).
// Similarly, : 7 after height allocates 7 bits for storing its value. The maximum value for 7 bits is 127 (2⁷ - 1).
// main() Function:

// int main() {
//     rectangle.width = 31; // Maximum value for 5 bits
//     rectangle.height = 100; // Maximum value for 7 bits

//     printf("Width: %d, Height: %d\n", rectangle.width, rectangle.height);
//     return 0;
// }
// Inside main(), values are assigned to the structure members:
// rectangle.width = 31; assigns the maximum value that can be stored within its 5-bit allocation.
// rectangle.height = 100; assigns a value within its 7-bit range.
// The printf statement displays the values of width and height.
// Key Points about Bit Fields:

// Memory Efficiency: Bit fields are useful when you need to represent data that doesn't require the full size of a standard data type (like int or char). This can lead to significant memory savings, especially when dealing with large arrays of structures.
// Limitations:
// Bit fields are not portable across different architectures, as the order of bits within a structure can vary.
// The compiler usually has limitations on the types that can be used as bit-field members (typically just int, unsigned int, or signed/unsigned variants).
// You can't take the address of a bit-field member because they might not start at byte boundaries.
// Unsigned vs. Signed: Using unsigned int (or unsigned short, etc.) for bit fields is generally recommended, especially if you're working with flags or status registers where the sign doesn't have inherent meaning.
// This example effectively illustrates how bit fields work in C, showing how they are declared and how their values are accessed within a structure. It also highlights the importance of being mindful of the limited storage capacity when assigning values to bit-field members.