#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <string.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main() {
    fd_set readfds;           // Set of file descriptors to monitor for reading
    int max_fd;               // Maximum file descriptor value
    char buffer[BUFFER_SIZE]; // Buffer for reading input
    struct timeval timeout;   // Timeout for select

    // Create a pipe for simulating a socket or file descriptor
    int pipefds[2];
    if (pipe(pipefds) == -1) {
        perror("Pipe creation failed");
        exit(1);
    }

    // Set up the timeout (1 second)
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    // Main loop to monitor input
    while (1) {
        // Clear the file descriptor set
        FD_ZERO(&readfds);

        // Add standard input (stdin) and the pipe file descriptors to the set
        FD_SET(STDIN_FILENO, &readfds);
        FD_SET(pipefds[0], &readfds);

        // Set the maximum file descriptor number
        max_fd = (STDIN_FILENO > pipefds[0]) ? STDIN_FILENO : pipefds[0];

        // Wait for one of the file descriptors to be ready
        int ret = select(max_fd + 1, &readfds, NULL, NULL, &timeout);

        if (ret == -1) {
            perror("Select failed");
            exit(1);
        } else if (ret == 0) {
            printf("No data within 1 second.\n");
        } else {
            // Check if standard input is ready
            if (FD_ISSET(STDIN_FILENO, &readfds)) {
                printf("Standard input is ready. Enter something: ");
                fgets(buffer, sizeof(buffer), stdin);
                printf("You entered: %s", buffer);
            }

            // Check if pipe is ready to read
            if (FD_ISSET(pipefds[0], &readfds)) {
                int bytes_read = read(pipefds[0], buffer, sizeof(buffer));
                if (bytes_read > 0) {
                    buffer[bytes_read] = '\0';  // Null-terminate the string
                    printf("Received from pipe: %s\n", buffer);
                }
            }
        }
    }

    // Close the pipe file descriptors
    close(pipefds[0]);
    close(pipefds[1]);

    return 0;
}




// The <sys/select.h> header provides the system calls and definitions needed to use the select() function, which is commonly used for monitoring multiple file descriptors to see if they are ready for reading, writing, or if an exceptional condition has occurred. It is often used in network programming to handle multiple clients, or in any program that needs to monitor multiple inputs simultaneously.
// Key Concepts in <sys/select.h>:

//     File Descriptors: A file descriptor is an integer representing an open file, socket, or other I/O resource.
//     select() Function: Used to monitor multiple file descriptors for events (e.g., data ready to be read, space available for writing, etc.).
//     fd_set: A data structure used to store the set of file descriptors being monitored.
//     Timeout: A timeout value that determines how long select() will block while waiting for events.

// Key Functions and Macros:

//     FD_ZERO(): Clears an fd_set.
//     FD_SET(): Adds a file descriptor to an fd_set.
//     FD_CLR(): Removes a file descriptor from an fd_set.
//     FD_ISSET(): Tests if a file descriptor is in an fd_set.
//     select(): Monitors file descriptors for specific events.



// Explanation of the Code:

//     File Descriptors (fd_set):
//         The fd_set type is used to store the set of file descriptors that we want to monitor for read events.
//         In this case, we will monitor stdin (standard input, represented by STDIN_FILENO) and a pipe (pipefds[0]).

//     File Descriptor Set Macros:
//         FD_ZERO(&readfds): Clears the set of file descriptors. This is done before adding new file descriptors to the set.
//         FD_SET(STDIN_FILENO, &readfds): Adds the file descriptor for standard input to the set.
//         FD_SET(pipefds[0], &readfds): Adds the pipe's read file descriptor to the set.

//     Select Function:
//         The select() function monitors the specified file descriptors for any events. The parameters are:
//             The highest file descriptor value + 1 (i.e., max_fd + 1).
//             The fd_set for file descriptors to monitor for reading (&readfds).
//             The fd_set for file descriptors to monitor for writing (set to NULL because we aren't writing in this example).
//             The fd_set for file descriptors to monitor for exceptional conditions (also NULL).
//             The timeout value (&timeout), which specifies how long select() should block before returning. Here, we set it to 1 second.

//     Handling Events:
//         After select() returns, we check the fd_set to see which file descriptors are ready:
//             FD_ISSET(STDIN_FILENO, &readfds): Checks if standard input is ready for reading.
//             FD_ISSET(pipefds[0], &readfds): Checks if the pipe is ready to be read.

//     Timeout:
//         If no file descriptors are ready within the specified timeout, the program prints "No data within 1 second."

//     Pipe:
//         We create a pipe using pipe(pipefds) to simulate another file descriptor that we can monitor for data.
//         The program reads data from the pipe if it becomes available.

//     Handling Input:
//         If stdin is ready, the program reads input from the user.
//         If data is available in the pipe, the program reads and prints it.

//     Exit Condition:
//         The program runs indefinitely until manually interrupted, simulating a server that can handle multiple inputs.

// Compilation:

// To compile the program, use the following command:

// gcc -o select_example select_example.c

// Execution:

// Run the program with:

// ./select_example

// Sample Output:
// Scenario 1: No Input (Timeout)

// No data within 1 second.
// No data within 1 second.

// Scenario 2: Input from Standard Input

// Standard input is ready. Enter something: Hello
// You entered: Hello
// No data within 1 second.

// Scenario 3: Input from Pipe

// Received from pipe: Hello from the pipe!
// No data within 1 second.

// Explanation of Key Functions and Concepts:

//     select():
//         The select() system call monitors multiple file descriptors and blocks until one or more of them become ready for the requested operation (e.g., read, write).
//         It allows handling multiple input sources in a single-threaded program, avoiding the need for multiple threads or processes.

//     fd_set:
//         The fd_set data structure is a set of file descriptors. You can use the macros FD_ZERO(), FD_SET(), FD_CLR(), and FD_ISSET() to manipulate and check file descriptors within the set.

//     Timeout:
//         The struct timeval used for the timeout parameter to select() allows specifying a timeout period for blocking operations.
//         If no events occur within the timeout period, select() returns 0, indicating that no file descriptors were ready.

//     Handling Multiple File Descriptors:
//         select() is useful for handling multiple file descriptors (e.g., sockets, files, pipes) in an efficient manner.
//         It allows programs to handle multiple I/O operations concurrently without resorting to multi-threading.

// Notes:

//     Error Handling:
//         It’s important to check the return value of select(). If it’s -1, it indicates an error, and errno will be set appropriately.

//     Scalability:
//         select() works well for handling a small number of file descriptors, but its performance degrades as the number of file descriptors increases. For larger applications, alternatives like poll() or epoll() might be more efficient.

//     Blocking:
//         By using a timeout, select() can block until an event occurs, or it can return immediately if the timeout expires, allowing for periodic checks or handling other tasks while waiting.

// This program demonstrates how to use select() for multiplexing I/O operations, allowing you to efficiently handle multiple input sources in a single thread.