#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("File Type: Regular File\n");
    } else if (S_ISDIR(mode)) {
        printf("File Type: Directory\n");
    } else if (S_ISLNK(mode)) {
        printf("File Type: Symbolic Link\n");
    } else if (S_ISCHR(mode)) {
        printf("File Type: Character Device\n");
    } else if (S_ISBLK(mode)) {
        printf("File Type: Block Device\n");
    } else if (S_ISFIFO(mode)) {
        printf("File Type: FIFO (Named Pipe)\n");
    } else if (S_ISSOCK(mode)) {
        printf("File Type: Socket\n");
    } else {
        printf("File Type: Unknown\n");
    }
}

void print_permissions(mode_t mode) {
    printf("Permissions: ");
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char *file_path = argv[1];
    struct stat file_stat;

    // Get file status
    if (stat(file_path, &file_stat) == -1) {
        perror("stat failed");
        return 1;
    }

    // Print file size
    printf("File: %s\n", file_path);
    printf("Size: %ld bytes\n", file_stat.st_size);

    // Print file type
    print_file_type(file_stat.st_mode);

    // Print file permissions
    print_permissions(file_stat.st_mode);

    // Print last modification time
    char time_buf[256];
    struct tm *tm_info = localtime(&file_stat.st_mtime);
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S", tm_info);
    printf("Last Modified: %s\n", time_buf);

    return 0;
}




// Key Functions and Macros Demonstrated:

//     stat():
//         Retrieves the status of a file and stores it in a struct stat.

//     S_ISREG(), S_ISDIR(), etc.:
//         Macros to determine the type of a file based on st_mode.

//     File permissions:
//         Accessed through the st_mode field using bitwise operations with macros like S_IRUSR, S_IWUSR, S_IXUSR, etc.

//     File timestamps:
//         st_mtime gives the last modification time, converted to a human-readable format using localtime() and strftime().

// Compilation and Execution:

// Save the program as sys_stat_demo.c and compile it:

// gcc -o sys_stat_demo sys_stat_demo.c

// Run the program with the path to a file or directory:

// ./sys_stat_demo example.txt

// Sample Output:

// For a file named example.txt:

// File: example.txt
// Size: 123 bytes
// File Type: Regular File
// Permissions: rw-r--r--
// Last Modified: 2025-01-08 14:23:45

// Notes:

//     Ensure the program has the necessary permissions to access the file or directory.
//     If the file does not exist or the path is invalid, the program will output an error using perror().





// The C code uses the sys/stat.h library to retrieve and display file information. It takes a file path as a command-line argument and prints details like file size, type, permissions, and last modification time. Here's a breakdown:

// Includes:

// stdio.h: For standard input/output functions like printf, fprintf, perror.
// sys/stat.h: For file status information (the core of this example).
// stdlib.h: Not directly used in the provided code.
// time.h: For time-related functions (localtime, strftime).
// print_file_type Function:

// This function takes a mode_t argument (from file_stat.st_mode) and uses a series of S_IS* macros (e.g., S_ISREG, S_ISDIR, S_ISLNK) to determine the file type and print it to the console.

// print_permissions Function:

// This function takes a mode_t argument and uses bitwise AND operations (&) with permission macros ( S_IRUSR, S_IWUSR, S_IXUSR, etc.) to determine read, write, and execute permissions for the owner, group, and others. It then prints the permissions in the standard rwx format.

// main Function:

// Argument Check: Checks if a file path is provided as a command-line argument. If not, it prints usage instructions and exits.

// stat System Call: The stat(file_path, &file_stat) function is the central part of the code. It takes the file path and a pointer to a struct stat variable. If successful, stat fills the file_stat structure with information about the file. The return value is checked for errors; perror("stat failed"); is used to print a more user-friendly error message if the stat call fails.

// Printing Information: The code then prints the following:

// File path.
// File size (using file_stat.st_size).
// File type (using the print_file_type function).
// File permissions (using the print_permissions function).
// Last modification time (using file_stat.st_mtime, converting it to a human-readable format with localtime() and formatting it with strftime()).
// How to Compile and Run:

// Save the code as sys_stat_demo.c.
// Compile: gcc -o sys_stat_demo sys_stat_demo.c
// Run: ./sys_stat_demo <file_path> (replace <file_path> with the actual path).
// Key Improvements in this Explanation:

// Clearer explanation of the print_file_type and print_permissions functions.
// Emphasis on error handling with the stat function and the use of perror.
// Simplified explanation of time conversion and formatting.
// Step-by-step compilation and execution instructions.
// Removed unnecessary details about unused headers like stdlib.h.
// This explanation provides a complete guide to understanding the code's purpose and functionality, focusing on the sys/stat.h library's usage. It also clarifies how to compile and run the program and highlights error handling.