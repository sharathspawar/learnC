#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int sig) {
    printf("\nCaught signal SIGINT (Ctrl+C)\n");
    printf("Signal number: %d\n", sig);
    // Exit the program after handling the signal
    exit(0);
}

// Signal handler for SIGTERM (kill command)
void sigterm_handler(int sig) {
    printf("\nCaught signal SIGTERM (kill)\n");
    printf("Signal number: %d\n", sig);
    // Exit the program after handling the signal
    exit(0);
}

int main() {
    // Setting up signal handler for SIGINT (Ctrl+C)
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Unable to catch SIGINT");
        exit(1);
    }

    // Setting up signal handler for SIGTERM (kill command)
    if (signal(SIGTERM, sigterm_handler) == SIG_ERR) {
        perror("Unable to catch SIGTERM");
        exit(1);
    }

    // Send a signal to the current process
    printf("Sending SIGTERM signal to the current process...\n");
    raise(SIGTERM);  // Sending the SIGTERM signal to the current process

    // Block SIGINT signal (Ctrl+C)
    sigset_t new_set, old_set;
    sigemptyset(&new_set);
    sigaddset(&new_set, SIGINT); // Add SIGINT to the set of signals to block
    if (sigprocmask(SIG_BLOCK, &new_set, &old_set) == -1) {
        perror("Failed to block signal");
        exit(1);
    }

    printf("SIGINT signal is now blocked. Press Ctrl+C and observe...\n");

    // Wait for a signal
    while (1) {
        sleep(1);
    }

    // Unblock SIGINT signal
    sigprocmask(SIG_SETMASK, &old_set, NULL);
    printf("SIGINT signal is unblocked now.\n");

    return 0;
}




// The <signal.h> header file in C provides functions for signal handling. Signals are used in Unix-like operating systems for communication between processes or to notify a process of events like interrupts, exceptions, or other system-level events. The <signal.h> header defines signal-related functions and constants for managing asynchronous events in a program.
// Key Concepts in <signal.h>:

//     Signals: These are notifications sent to a process to indicate that an event has occurred (e.g., SIGINT for interrupt, SIGTERM for termination).
//     Signal Handlers: Functions that define how a process should respond to a signal.
//     signal() and sigaction(): Functions for setting up signal handlers.
//     Signal Masking: The process of blocking or unblocking signals to control the flow of the program.
//     kill(): A system call used to send signals to processes.
//     raise(): A function that sends a signal to the calling process.

// Key Structures and Constants:

//     struct sigaction: This structure is used with sigaction() to define a custom signal handler.
//     Signal Constants: These are the predefined signal names, such as SIGINT, SIGKILL, SIGTERM, SIGSEGV.

// Functions in Detail:
// 1. signal():

// This function allows you to set up a signal handler for a specific signal. It is a simpler, older interface.

// void (*signal(int sig, void (*handler)(int)))(int);

//     sig: The signal number (e.g., SIGINT).
//     handler: The signal handler function. This function will be called when the signal is received.

// 2. sigaction():

// This function is a more robust, modern interface for handling signals. It provides more control over how signals are handled, including the ability to set signal masks and flags.

// int sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);

//     sig: The signal number.
//     act: A pointer to a struct sigaction that defines the new signal handler.
//     oldact: A pointer to a struct sigaction where the previous signal handler will be stored.

// 3. raise():

// This function sends a signal to the calling process.

// int raise(int sig);

//     sig: The signal to send (e.g., SIGINT).

// 4. kill():

// This system call sends a signal to a process or a group of processes.

// int kill(pid_t pid, int sig);

//     pid: The process ID to which the signal is sent. It can also be a special value:
//         0 to send the signal to all processes in the current process group.
//         -1 to send the signal to all processes except for the sending process and processes that can't receive the signal.
//     sig: The signal to send (e.g., SIGKILL).

// 5. sigprocmask():

// This function is used to set or retrieve the signal mask of the current process. It can be used to block or unblock signals.

// int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

//     how: The action to take (SIG_BLOCK, SIG_UNBLOCK, SIG_SETMASK).
//     set: A pointer to a sigset_t that defines which signals to block or unblock.
//     oldset: A pointer to a sigset_t that will store the previous signal mask.

// 6. sigemptyset() and sigfillset():

// These functions initialize a signal set to empty or full, respectively.

// int sigemptyset(sigset_t *set);
// int sigfillset(sigset_t *set);

//     set: A pointer to the signal set to initialize.