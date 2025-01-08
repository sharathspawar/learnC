#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    const char *invalid_file = "/nonexistent/file.txt";

    // Try to open a non-existent file
    int fd = open(invalid_file, O_RDONLY);
    if (fd == -1) {
        // Print the error number
        printf("Error number: %d\n", errno);

        // Print a human-readable error message
        perror("Failed to open file using perror");

        // Alternative: Use strerror to print the error message
        printf("Error message using strerror: %s\n", strerror(errno));
    }

    // Reset errno and try another invalid operation
    errno = 0;

    // Attempt to close an invalid file descriptor
    if (close(fd) == -1) {
        printf("\nAttempted to close an invalid file descriptor.\n");
        printf("Error number: %d\n", errno);
        perror("Error closing file using perror");
        printf("Error message using strerror: %s\n", strerror(errno));
    }

    return 0;
}



// Key Functions and Features:

//     errno:
//         A global variable that stores the last error number set by a library function or system call.
//         errno is set to 0 when no error occurs.

//     perror():
//         Outputs a human-readable error message based on errno to stderr.
//         Prepends a custom message (e.g., "Failed to open file using perror").

//     strerror():
//         Returns a string describing the error corresponding to the error code stored in errno.

//     Error Codes:
//         Defined as macros in <errno.h> (e.g., ENOENT for "No such file or directory").

// Compilation and Execution:

// Save the program as errno_demo.c and compile it:

// gcc -o errno_demo errno_demo.c
// ./errno_demo

// Sample Output:

// Error number: 2
// Failed to open file using perror: No such file or directory
// Error message using strerror: No such file or directory

// Attempted to close an invalid file descriptor.
// Error number: 9
// Error closing file using perror: Bad file descriptor
// Error message using strerror: Bad file descriptor

// Notes:

//     Common Error Codes:
//         EACCES: Permission denied.
//         ENOENT: No such file or directory.
//         EBADF: Bad file descriptor.
//         EEXIST: File exists.

//     Thread Safety:
//         errno is thread-local in POSIX systems, meaning each thread has its own errno.

//     Best Practices:
//         Always check errno immediately after a function fails, as subsequent function calls might overwrite its value.

//     Use Cases:
//         Debugging system calls or library functions that return error codes.





// The C code demonstrates how to use errno and related functions to handle and report errors from system calls or library functions. It focuses on errno, perror(), and strerror().

// 1. Include Headers:

// stdio.h: For standard input/output functions like printf and perror.
// errno.h: Defines the errno macro and error code constants.
// string.h: For the strerror() function.
// fcntl.h: For file control options (used in the open() call).
// unistd.h: For POSIX operating system calls (like open() and close()).
// 2. Simulate an Error:

// The code attempts to open a non-existent file using open() with the O_RDONLY flag. This will cause open() to fail.
// 3. Check for Errors:

// if (fd == -1): The return value of open() is checked. A return value of -1 indicates an error.
// 4. Handling the Error:

// printf("Error number: %d\n", errno): Prints the value of errno, which contains the error code corresponding to the last failed operation.
// perror("Failed to open file using perror"): Prints a descriptive error message to stderr (standard error stream). perror() automatically prepends the provided string to the error message obtained from strerror(errno). This is helpful for providing context about where the error occurred.
// printf("Error message using strerror: %s\n", strerror(errno)): Uses strerror(errno) to convert the error code in errno into a human-readable string, then prints the string to the console.
// 5. Resetting errno and Another Example:

// errno = 0;: It's crucial to reset errno to 0 before calling another function that might set it. This ensures you're catching the correct error from the subsequent call.
// The code then demonstrates a similar error-handling process for an invalid close() call. It tries to close a file descriptor that is not valid (from the previous failed open() attempt), causing close() to fail, and demonstrating that errno will be updated.
// Key Concepts and Best Practices:

// errno: A global variable (actually a macro that expands to a thread-local variable in modern systems) that stores the error code of the last failed system call or library function.
// perror(): Simplifies error reporting by combining a custom message with the system's error description.
// strerror(): Converts an error code to a human-readable string.
// Resetting errno: Always reset errno to 0 before a function call where you want to check its value afterward.
// Check Return Values: System calls and many library functions signal errors through their return values (often -1). Always check these return values.
// Thread Safety: errno is now typically thread-local, so you don't need to worry about race conditions when using it in multithreaded programs.
// This explanation clarifies how errno is used, the importance of resetting it, and the correct way to use perror() and strerror() for effective error handling in C.
