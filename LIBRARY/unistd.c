#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Get the process ID
    pid_t pid = getpid();
    printf("Current Process ID: %d\n", pid);

    // Get the parent process ID
    pid_t ppid = getppid();
    printf("Parent Process ID: %d\n", ppid);

    // Get the current working directory
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current Working Directory: %s\n", cwd);
    } else {
        perror("getcwd failed");
    }

    // Change the current working directory
    if (chdir("..") == 0) {
        printf("Changed directory to parent.\n");
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("New Working Directory: %s\n", cwd);
        }
    } else {
        perror("chdir failed");
    }

    // Check for access permissions to a file
    const char *filename = "test_file.txt";
    if (access(filename, F_OK) == 0) {
        printf("File '%s' exists.\n", filename);
        if (access(filename, R_OK) == 0) {
            printf("File '%s' is readable.\n", filename);
        }
        if (access(filename, W_OK) == 0) {
            printf("File '%s' is writable.\n", filename);
        }
    } else {
        printf("File '%s' does not exist.\n", filename);
    }

    // Sleep for a few seconds
    printf("Sleeping for 3 seconds...\n");
    sleep(3);
    printf("Awake now.\n");

    // Get the system's page size
    long page_size = sysconf(_SC_PAGESIZE);
    if (page_size != -1) {
        printf("System Page Size: %ld bytes\n", page_size);
    } else {
        perror("sysconf failed");
    }

    return 0;
}


// Key Functions Demonstrated:

//     Process management:
//         getpid(): Get the current process ID.
//         getppid(): Get the parent process ID.

//     Directory operations:
//         getcwd(): Get the current working directory.
//         chdir(): Change the current working directory.

//     File access:
//         access(): Check a file's existence and permissions.

//     System sleep:
//         sleep(): Pause the program execution for a specified number of seconds.

//     System configuration:
//         sysconf(): Query system configuration values (e.g., _SC_PAGESIZE).




// The C code demonstrates several functions from the unistd.h library, which provides access to POSIX operating system services. These functions are commonly used for process management, working with directories, checking file access, and other system-level operations. Here's a breakdown:

// Process Management:

// getpid(): Returns the process ID of the currently running process.
// getppid(): Returns the process ID of the parent process.
// Directory Operations:

// getcwd(buffer, size): Gets the current working directory. It stores the path in the provided buffer, which must be large enough (up to size bytes). It returns a pointer to buffer upon success, or NULL on failure. Error handling is included to check for buffer overflow.
// chdir(path): Changes the current working directory to the specified path. It returns 0 on success, or -1 on failure.
// File Access:

// access(path, mode): Checks if a file exists and has specified permissions. mode can be:
// F_OK: Check for file existence.
// R_OK: Check for read permission.
// W_OK: Check for write permission.
// X_OK: Check for execute permission. The function returns 0 on success (access granted), or -1 on failure (access denied or file doesn't exist).
// System Sleep:

// sleep(seconds): Pauses the program's execution for the specified number of seconds.
// System Configuration:

// sysconf(name): Retrieves system configuration values. The code uses _SC_PAGESIZE to get the system's page size. The result is checked for errors. If sysconf fails, it will return -1.
// This code provides a concise example of how to use common functions from unistd.h for interacting with the operating system. It's important to note the error handling (e.g., checking the return value of getcwd and chdir) to ensure the code behaves correctly in different situations.