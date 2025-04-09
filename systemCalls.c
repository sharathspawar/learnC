#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>       // for fork, getpid, chdir, getcwd
#include <fcntl.h>        // for open
#include <sys/types.h>    // for pid_t, stat
#include <sys/stat.h>     // for stat
#include <sys/wait.h>     // for wait
#include <string.h>
#include <time.h>         // for time
#include <sys/time.h>     // for gettimeofday

int main() {
    printf("=== File Operations ===\n");

    // open() - system call to open a file
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644); // Create if not exists, write-only
    if (fd < 0) {
        perror("open failed");
        exit(1);
    }

    // write() - write to file
    const char *text = "Hello, Linux system calls!\n";
    write(fd, text, strlen(text));

    // close() - close the file descriptor
    close(fd);

    // read() - read from a file
    fd = open("test.txt", O_RDONLY);
    char buffer[100];
    int n = read(fd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("File content: %s\n", buffer);
    close(fd);

    printf("\n=== Process Control ===\n");

    pid_t pid = fork(); // fork() - create a child process
    if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());

        // exec() - replace process image (optional demonstration)
        // execl("/bin/ls", "ls", "-l", NULL); // Uncomment to run ls
        exit(0);
    } else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
        wait(NULL); // wait for child to finish
    }

    printf("\n=== Directory Operations ===\n");

    // mkdir() - create a directory
    mkdir("mydir", 0755);

    // chdir() - change current working directory
    chdir("mydir");

    // getcwd() - get current working directory
    char cwd[256];
    getcwd(cwd, sizeof(cwd));
    printf("Current working directory: %s\n", cwd);

    // Going back to previous directory
    chdir("..");

    printf("\n=== File Info ===\n");

    struct stat fileStat;
    if (stat("test.txt", &fileStat) == 0) {
        printf("File Size: %ld bytes\n", fileStat.st_size);
        printf("Inode: %ld\n", fileStat.st_ino);
        printf("File Permissions: %o\n", fileStat.st_mode & 0777);
    } else {
        perror("stat failed");
    }

    printf("\n=== Time and Date ===\n");

    time_t t = time(NULL);
    printf("Current time (using time()): %s", ctime(&t));

    struct timeval tv;
    gettimeofday(&tv, NULL);
    printf("Current time (using gettimeofday()): %ld.%06ld\n", tv.tv_sec, tv.tv_usec);

    printf("\n=== User and Group Info ===\n");

    printf("User ID: %d\n", getuid());   // getuid() - current user ID
    printf("Group ID: %d\n", getgid());  // getgid() - current group ID

    printf("\nAll basic system calls demonstrated successfully.\n");

    return 0;
}


// Linux provides a comprehensive set of system calls that serve as the interface between user applications and the kernel, enabling programs to request various services from the operating system. These system calls can be broadly categorized based on their functionalities. Below is an overview of these categories, along with examples and their typical uses:​
// Medium+1Linux Kernel Labs+1

// 1. Process Management System Calls:

//     fork: Creates a new process by duplicating the calling process.​

//     execve: Replaces the current process image with a new program.​

//     exit: Terminates the calling process.​

//     wait: Waits for a child process to change state.​

// 2. File Management System Calls:

//     open: Opens a file or device.​
//     Medium+3Linux Handbook+3Linux Kernel Labs+3

//     read: Reads data from a file descriptor.​

//     write: Writes data to a file descriptor.​

//     close: Closes an open file descriptor.​
//     Page Packagecloud Blog+2Wikipedia – Die freie Enzyklopädie+2Linux Handbook+2

//     lseek: Repositions the read/write file offset.​
//     Vivek Pandey's Homepage

// 3. Device Management System Calls:

//     ioctl: Manipulates the underlying device parameters of special files.​

//     mknod: Creates a filesystem node (file, device special file, or named pipe).​

// 4. Information Maintenance System Calls:

//     getpid: Returns the process ID of the calling process.​

//     alarm: Sets an alarm clock for signal delivery.​

//     sleep: Suspends execution for a specified time.​

// 5. Communication System Calls:

//     pipe: Creates a pair of file descriptors for interprocess communication.​

//     socket: Creates an endpoint for communication.​

//     connect: Initiates a connection on a socket.​
//     Linux Kernel Labs+3Naval Postgraduate School+3Wikipedia – Die freie Enzyklopädie+3

//     accept: Accepts a connection on a socket.​

// 6. Protection System Calls:

//     chmod: Changes the permissions of a file.​
//     Vivek Pandey's Homepage

//     chown: Changes the owner and group of a file.​

//     umask: Sets the file mode creation mask.​

// For a comprehensive and detailed list of Linux system calls, along with their specific functions and usage, you can refer to the following resources:

//     Linux System Call Table: This resource provides a detailed table of system calls, including their numbers and corresponding symbolic names. ​
//     Chromium Git Repositories+1Chromium+1

//     man7.org - syscalls(2) Manual Page: Offers an extensive list of system calls with descriptions and the kernel version they appeared in. ​
//     man7.org

//     Filippo Valsorda's Searchable Linux Syscall Table: A searchable table for the x86-64 architecture, detailing system call numbers, names, arguments, and links to manuals and implementations. ​
//     Filippo

// These resources provide in-depth information and are valuable for understanding the breadth and functionality of Linux system calls.