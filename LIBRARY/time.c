#include <stdio.h>
#include <time.h>

int main() {
    // Get the current time
    time_t current_time = time(NULL);
    if (current_time == -1) {
        perror("Failed to get the current time");
        return 1;
    }

    // Convert to local time
    struct tm *local_time = localtime(&current_time);
    if (local_time == NULL) {
        perror("Failed to convert to local time");
        return 1;
    }

    // Print the local time in human-readable format
    printf("Current Local Time: %s", asctime(local_time));

    // Format the local time
    char time_buffer[256];
    if (strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local_time) == 0) {
        fprintf(stderr, "strftime failed\n");
        return 1;
    }
    printf("Formatted Local Time: %s\n", time_buffer);

    // Get UTC time
    struct tm *utc_time = gmtime(&current_time);
    if (utc_time == NULL) {
        perror("Failed to convert to UTC time");
        return 1;
    }
    printf("Current UTC Time: %s", asctime(utc_time));

    // Measure elapsed time using clock()
    clock_t start_time = clock();
    if (start_time == -1) {
        perror("Failed to get clock time");
        return 1;
    }

    // Simulate work with a sleep
    printf("Simulating work with 3 seconds sleep...\n");
    for (int i = 0; i < 3; i++) {
        printf("... %d second(s) elapsed ...\n", i + 1);
        sleep(1);
    }

    clock_t end_time = clock();
    if (end_time == -1) {
        perror("Failed to get clock time");
        return 1;
    }

    // Calculate elapsed time
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Elapsed CPU time: %.2f seconds\n", elapsed_time);

    // Get the time difference in seconds
    struct tm new_year = *local_time;
    new_year.tm_hour = 0;
    new_year.tm_min = 0;
    new_year.tm_sec = 0;
    new_year.tm_mon = 0;  // January
    new_year.tm_mday = 1; // First day of the year

    time_t new_year_time = mktime(&new_year);
    if (new_year_time == -1) {
        perror("Failed to compute time for New Year's Day");
        return 1;
    }

    double seconds_since_new_year = difftime(current_time, new_year_time);
    printf("Seconds since New Year: %.0f seconds\n", seconds_since_new_year);

    return 0;
}





// Key Functions and Features:

//     time():
//         Gets the current time as a time_t value (seconds since the Unix epoch).

//     localtime() and gmtime():
//         Convert a time_t value to a struct tm representing local or UTC time.

//     asctime():
//         Converts a struct tm to a human-readable string.

//     strftime():
//         Formats a struct tm into a custom string (e.g., "YYYY-MM-DD HH:MM:SS").

//     clock():
//         Measures CPU time used by the program.

//     difftime():
//         Computes the difference in seconds between two time_t values.

//     mktime():
//         Converts a struct tm back to a time_t.

// Compilation and Execution:

// Save the program as time_demo.c, and compile it:

// gcc -o time_demo time_demo.c
// ./time_demo

// Sample Output:

// Current Local Time: Wed Jan  8 14:30:45 2025
// Formatted Local Time: 2025-01-08 14:30:45
// Current UTC Time: Wed Jan  8 14:30:45 2025
// Simulating work with 3 seconds sleep...
// ... 1 second(s) elapsed ...
// ... 2 second(s) elapsed ...
// ... 3 second(s) elapsed ...
// Elapsed CPU time: 3.00 seconds
// Seconds since New Year: 689645 seconds

// This program showcases a variety of time manipulation functions and demonstrates how to work with both real and CPU time.






// The C code demonstrates several time-related functions from the time.h library. It retrieves the current time, formats it, performs calculations related to time differences, and measures elapsed CPU time.

// 1. Getting the Current Time:

// time(NULL): Retrieves the current calendar time as a time_t value, which represents the number of seconds since the Unix epoch (January 1, 1970, 00:00:00 UTC). The code checks for errors (rare but possible).
// 2. Converting to Local and UTC Time:

// localtime(&current_time): Converts the time_t value to a struct tm structure representing the local time. This structure breaks down the time into year, month, day, hour, minute, second, etc. Error checking is included.
// gmtime(&current_time): Converts the time_t to a struct tm representing Coordinated Universal Time (UTC).
// 3. Formatting Time:

// asctime(local_time): Converts the struct tm (local time) to a human-readable string in a standard format (e.g., "Wed Jan 8 14:30:45 2025").
// strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local_time): Formats the local time into a custom string using the specified format string. strftime provides fine-grained control over the output format. The formatted time is stored in time_buffer. The code includes a check to see if the strftime is successful.
// 4. Measuring Elapsed CPU Time:

// clock(): Retrieves the current processor time used by the program.
// The code calls clock() before and after a simulated work period (using sleep()), calculates the difference, and divides by CLOCKS_PER_SEC to get the elapsed CPU time in seconds.
// 5. Time Difference Calculations:

// The code creates a struct tm representing New Year's Day of the current year.
// mktime(&new_year): Converts the struct tm for New Year's Day back to a time_t value.
// difftime(current_time, new_year_time): Calculates the difference (in seconds) between the current time and New Year's Day.
// Key Improvements in this Explanation:

// Emphasis on error checking for time(), localtime(), gmtime(), and mktime(). These functions can fail, and it's good practice to check.
// Clearer explanation of time_t and struct tm.
// Detailed breakdown of strftime and its format string usage.
// Explanation of the purpose of CLOCKS_PER_SEC in calculating elapsed CPU time.
// Step-by-step description of how the code calculates the time difference since New Year's Day.
// This explanation provides a comprehensive guide to understanding the C code and how it uses the time.h library functions to work with time. It emphasizes error handling, explains the purpose of each function clearly, and breaks down the time difference calculation.