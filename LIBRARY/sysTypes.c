#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Using pid_t to get process IDs
    pid_t pid = getpid(); // Current process ID
    pid_t ppid = getppid(); // Parent process ID

    printf("Current Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);

    // Using size_t and ssize_t for buffer operations
    size_t buffer_size = 128;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));
    if (buffer == NULL) {
        perror("malloc failed");
        return 1;
    }

    // Using ssize_t for read operations
    printf("Reading from stdin (type something and press Enter):\n");
    ssize_t bytes_read = read(STDIN_FILENO, buffer, buffer_size - 1);
    if (bytes_read >= 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("You typed: %s", buffer);
    } else {
        perror("read failed");
        free(buffer);
        return 1;
    }

    // Using off_t to represent file offsets
    printf("\nDemonstrating file offset using off_t...\n");
    FILE *file = fopen("example.txt", "w+");
    if (file == NULL) {
        perror("fopen failed");
        free(buffer);
        return 1;
    }

    off_t offset = ftell(file); // Get the current file offset
    printf("Initial file offset: %ld\n", (long)offset);

    fprintf(file, "Hello, world!\n");
    fflush(file);

    offset = ftell(file); // Get the new file offset
    printf("File offset after writing: %ld\n", (long)offset);

    fclose(file);
    free(buffer);

    return 0;
}



// Key Types Demonstrated:

//     pid_t:
//         Used for process IDs, as seen in getpid() and getppid().

//     size_t:
//         Represents sizes of objects or memory allocations. Used for buffer sizes in this example.

//     ssize_t:
//         Represents signed sizes for functions like read() or write(). It indicates success (bytes read/written) or failure (-1).

//     off_t:
//         Represents file offsets, as seen in ftell().

// Compilation and Execution:

// Save the program as sys_types_demo.c, and compile it with a POSIX-compliant compiler:

// gcc -o sys_types_demo sys_types_demo.c
// ./sys_types_demo

// Notes:

//     The program interacts with the file system. It creates a file example.txt in the current directory and writes a line into it.
//     Ensure the program has the necessary permissions to read/write in the current directory.
//     The read() function expects input from stdin, so type something and press Enter when prompted







// The C code demonstrates the use of several system-related data types defined in sys/types.h. These types are important for portability and ensuring correct interaction with POSIX-compliant operating systems. Here's a breakdown:

// Process IDs (pid_t):

// pid_t getpid(void): Retrieves the process ID of the currently running process.
// pid_t getppid(void): Retrieves the process ID of the parent process.
// The code uses pid_t to store these IDs and prints them to the console.
// Sizes and Signed Sizes (size_t, ssize_t):

// size_t: An unsigned integer type used to represent the size of objects in memory. It's commonly used for buffer sizes, array indices, and memory allocation. The code uses size_t to define the size of a dynamically allocated buffer.
// ssize_t: A signed integer type used for functions that can return a byte count or an error indication. read() uses ssize_t for the number of bytes read. A negative value indicates an error. The code checks the return value of read() for errors.
// File Offsets (off_t):

// off_t: Used to represent file offsets and sizes, which can be larger than what a regular long can store. It is essential for 64-bit systems or when dealing with very large files.
// off_t ftell(FILE *stream): Returns the current file position indicator for the given stream.
// The code opens a file, gets the initial offset using ftell(), writes to the file, and then checks the offset again to show how it has changed.
// Key Considerations:

// Portability: Using types like size_t, ssize_t, off_t and pid_t enhances portability because their sizes are defined appropriate to the system (e.g., 32-bit or 64-bit), unlike int or long, which might have different sizes on different architectures.
// Error Handling: The code checks the return value of malloc() and read() for potential errors. This is essential for robust code.
// File Operations: The fopen(), fprintf(), ftell(), and fclose() functions are used for basic file operations. The fflush() function ensures that any buffered output data is written to the file.
// Memory Management: malloc() is used for dynamic memory allocation. It is crucial to free() the allocated memory after you are finished with it to prevent memory leaks. The code does this before exiting.
// This improved explanation clarifies the significance of sys/types.h, how the demonstrated types improve code portability, and points out best practices in error handling, file operations, and memory management.