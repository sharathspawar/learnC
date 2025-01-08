#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>   // Include sys/time.h for time manipulation
#include <unistd.h>      // For sleep()

// Function to print the current time using gettimeofday
void print_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);  // Get the current time

    // Print the time in seconds and microseconds
    printf("Current time: %ld seconds and %ld microseconds\n", tv.tv_sec, tv.tv_usec);
}

// Function to calculate the difference between two times
void calculate_time_difference(struct timeval *start, struct timeval *end) {
    struct timeval diff;
    timersub(end, start, &diff);  // Subtract start time from end time

    // Print the difference in seconds and microseconds
    printf("Time difference: %ld seconds and %ld microseconds\n", diff.tv_sec, diff.tv_usec);
}

int main() {
    struct timeval start, end;

    // Record the start time
    gettimeofday(&start, NULL);
    print_current_time();

    // Simulate some work (sleep for 2 seconds)
    sleep(2);

    // Record the end time
    gettimeofday(&end, NULL);
    print_current_time();

    // Calculate the time difference
    calculate_time_difference(&start, &end);

    // Example of using select() for timeout
    struct timeval timeout;
    timeout.tv_sec = 1;  // 1 second
    timeout.tv_usec = 0; // 0 microseconds

    // Simulate waiting for events (in this case, we just call select with a timeout)
    printf("Waiting for 1 second...\n");
    int ret = select(0, NULL, NULL, NULL, &timeout);
    if (ret == 0) {
        printf("Timeout occurred after 1 second.\n");
    } else if (ret == -1) {
        perror("select");
    } else {
        printf("Select returned with an event.\n");
    }

    return 0;
}




// The <sys/time.h> header file provides functions and types for dealing with time-related operations. It is used for managing time intervals, timestamps, and performing various time-related calculations in C programs.
// Key Features of <sys/time.h>:

//     struct timeval: Represents a time value with seconds and microseconds.
//     struct timespec: Represents a time value with seconds and nanoseconds (used in some systems for higher precision).
//     gettimeofday(): Gets the current time.
//     settimeofday(): Sets the system time (requires superuser privileges).
//     select(): Waits for events on file descriptors with timeouts.
//     timercmp() / timersub(): Used for comparing and subtracting struct timeval values.

// Overview of Functions and Types:

//     struct timeval: Holds the time in seconds and microseconds.
//         tv_sec: The number of seconds.
//         tv_usec: The number of microseconds (from 0 to 999999).

//     struct timespec: Holds the time in seconds and nanoseconds.
//         tv_sec: The number of seconds.
//         tv_nsec: The number of nanoseconds (from 0 to 999999999).

//     gettimeofday(): Used to get the current time in struct timeval format.

//     settimeofday(): Used to set the system time (requires root privileges).

//     select(): Can be used to wait for events on file descriptors with a timeout.

//     timercmp() and timersub(): Functions for comparing and subtracting time intervals.




// Explanation of the Code:

//     gettimeofday():
//         gettimeofday(&tv, NULL) gets the current time and stores it in the tv structure.
//         The tv.tv_sec field stores the number of seconds since the Unix epoch (January 1, 1970), and tv.tv_usec stores the microseconds part.

//     Printing the Current Time:
//         The print_current_time() function retrieves and prints the current time in seconds and microseconds.

//     timersub():
//         The timersub() function takes two struct timeval values (start and end) and stores their difference in a third struct timeval (diff).
//         It subtracts start from end and stores the result in diff.
//         We then print the difference in seconds and microseconds.

//     select():
//         The select() function is used to monitor file descriptors for events. In this example, we're using it with a timeout to simulate waiting for an event.
//         The timeout is set to 1 second (timeout.tv_sec = 1; timeout.tv_usec = 0;).
//         select() will block until either an event occurs or the timeout expires. Since we pass NULL for file descriptors, it just waits for the timeout to expire.
//         If select() returns 0, it means the timeout occurred. If it returns -1, an error occurred.

//     Sleep Simulation:
//         We use sleep(2) to simulate some work (2 seconds in this case). This allows us to test the time difference calculation.

// Key Constants and Types:

//     struct timeval:
//         tv_sec: The number of seconds.
//         tv_usec: The number of microseconds (from 0 to 999999).

//     struct timespec:
//         tv_sec: The number of seconds.
//         tv_nsec: The number of nanoseconds (from 0 to 999999999).

//     gettimeofday():
//         The function used to retrieve the current time.
//         gettimeofday(&tv, NULL) returns the time in struct timeval format.

//     timersub():
//         Subtracts one struct timeval from another and stores the result in a third struct timeval.

//     select():
//         Waits for events on file descriptors or times out after a given period.
//         In the code above, it’s used to simulate waiting with a timeout.

// Compilation:

// To compile the program, use the following command:

// gcc -o sys_time_example sys_time_example.c

// Execution:

// Run the program with:

// ./sys_time_example

// Sample Output:

// Current time: 1673191234 seconds and 123456 microseconds
// Current time: 1673191236 seconds and 123456 microseconds
// Time difference: 2 seconds and 0 microseconds
// Waiting for 1 second...
// Timeout occurred after 1 second.

// Explanation of Sample Output:

//     Current Time:
//         The program prints the current time at two different points: before and after simulating some work (sleeping for 2 seconds).

//     Time Difference:
//         The program calculates the difference between the two times and prints it as "2 seconds and 0 microseconds".

//     Select Timeout:
//         The program simulates waiting for 1 second using select(). It times out and prints "Timeout occurred after 1 second.".

// Summary:

//     gettimeofday() is used to get the current system time in struct timeval format.
//     timersub() is used to calculate the difference between two struct timeval values.
//     select() is used to wait for events with a timeout (or indefinitely) on file descriptors. It can be used to implement timeouts in socket programming.
//     sys/time.h provides various utilities to manage time in C, making it essential for implementing time-based logic or handling timeouts.

// This example demonstrates how to use the features provided by <sys/time.h> to handle time in C, making it useful for tasks such as benchmarking, timeout handling, and manipulating time intervals.
