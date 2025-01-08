#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void print_terminal_size() {
    struct winsize ws;
    
    // Get terminal window size (rows and columns)
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
        perror("ioctl(TIOCGWINSZ) failed");
        exit(1);
    }
    
    printf("Terminal size: %d rows, %d columns\n", ws.ws_row, ws.ws_col);
}

void set_non_blocking(int fd) {
    int flags;

    // Get the current file descriptor flags
    flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl(F_GETFL) failed");
        exit(1);
    }

    // Set the non-blocking flag
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl(F_SETFL) failed");
        exit(1);
    }
    printf("File descriptor set to non-blocking mode\n");
}

void get_disk_size(const char *device) {
    int fd;
    unsigned long size;

    // Open the block device file
    fd = open(device, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open device");
        exit(1);
    }

    // Get the size of the device (in bytes)
    if (ioctl(fd, BLKGETSIZE, &size) == -1) {
        perror("ioctl(BLKGETSIZE) failed");
        exit(1);
    }

    printf("Disk size: %lu bytes\n", size);

    // Close the device file
    close(fd);
}

void get_network_interface_address(const char *iface) {
    struct ifreq ifr;
    int sockfd;

    // Create a socket for network operations
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(1);
    }

    // Copy the interface name into the ifreq structure
    strncpy(ifr.ifr_name, iface, IFNAMSIZ);

    // Get the IP address of the interface
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl(SIOCGIFADDR) failed");
        exit(1);
    }

    // Print the IP address
    struct sockaddr_in *addr = (struct sockaddr_in *)&ifr.ifr_addr;
    printf("IP address of %s: %s\n", iface, inet_ntoa(addr->sin_addr));

    // Close the socket
    close(sockfd);
}

int main() {
    // 1. Print the terminal size
    print_terminal_size();

    // 2. Set file descriptor to non-blocking mode (example with stdin)
    set_non_blocking(STDIN_FILENO);

    // 3. Get the size of a disk (example with /dev/sda)
    get_disk_size("/dev/sda");

    // 4. Get the IP address of a network interface (example with eth0)
    get_network_interface_address("eth0");

    return 0;
}




// The <sys/ioctl.h> header provides the necessary functions and macros for performing input/output control operations on devices. The primary function in this header is ioctl(), but it also includes various predefined command codes used for device-specific operations, especially for file descriptors representing devices.
// Key Concepts and Functions in <sys/ioctl.h>:

//     ioctl(): This is the main function used for device-specific input/output control. It allows a program to request operations that are specific to a device driver (e.g., getting or setting device parameters).

//     int ioctl(int fd, unsigned long request, ...);

//         fd: The file descriptor referring to the device.
//         request: The command code specifying the operation to perform.
//         The third parameter is optional and depends on the command.

//     Command codes: Each device has a set of operations represented by command codes that ioctl() can use. These are typically defined in header files for specific subsystems (e.g., terminals, network devices, etc.).

//     Device-specific commands: Different types of devices (e.g., terminal devices, block devices, network devices) have different ioctl() commands that may be used to get or set device parameters or to issue specific device operations.

// Commonly Used ioctl() Command Codes:

// These command codes are defined in various headers and are used to control specific device behavior.

//     Terminal control (<termios.h>):
//         TIOCGWINSZ: Get window size of a terminal.
//         TIOCSWINSZ: Set window size of a terminal.

//     File descriptor control:
//         FIONREAD: Returns the number of bytes available to read from a file descriptor.
//         FIONBIO: Sets the file descriptor to non-blocking mode.

//     Disk operations:
//         BLKGETSIZE: Get the size of a block device in bytes.
//         BLKSSZGET: Get the sector size of a block device.

//     Network interface control:
//         SIOCGIFADDR: Get the IP address associated with a network interface.
//         SIOCSIFADDR: Set the IP address for a network interface.





// Explanation of the Code:

//     print_terminal_size():
//         The TIOCGWINSZ command is used with ioctl() to get the current terminal's window size (rows and columns).
//         This function uses the winsize struct to hold the terminal's size and then prints it.

//     set_non_blocking():
//         The fcntl() function is used to get the current file descriptor flags and then modify them.
//         F_GETFL retrieves the current flags, and F_SETFL is used to modify them, specifically adding the O_NONBLOCK flag to set the file descriptor to non-blocking mode.

//     get_disk_size():
//         The BLKGETSIZE ioctl command is used to retrieve the size of a block device (e.g., a disk or partition).
//         The unsigned long variable size holds the disk size, which is then printed.

//     get_network_interface_address():
//         The SIOCGIFADDR ioctl command is used to retrieve the IP address of a specified network interface.
//         The function uses the ifreq struct to hold the interface information, and then it extracts and prints the IP address of the given interface (eth0 in this case).

// Common ioctl Command Codes:

//     For Terminal Control (<termios.h>):
//         TIOCGWINSZ: Get terminal window size (rows, columns).
//         TIOCSWINSZ: Set terminal window size.

//     For File Descriptor Control (<fcntl.h>):
//         FIONREAD: Get the number of bytes available to read.
//         FIONBIO: Set the file descriptor to non-blocking mode.

//     For Disk Control (<linux/fs.h> or <sys/ioctl.h>):
//         BLKGETSIZE: Get the size of a block device in bytes.
//         BLKSSZGET: Get the block sector size.

//     For Network Interfaces (<net/if.h>):
//         SIOCGIFADDR: Get the IP address associated with a network interface.
//         SIOCSIFADDR: Set the IP address for a network interface.

// Compilation and Execution:

// Save the code to a file called ioctl_demo.c and compile it:

// gcc -o ioctl_demo ioctl_demo.c

// Run the program:

// ./ioctl_demo

// Sample Output:

// Terminal size: 24 rows, 80 columns
// File descriptor set to non-blocking mode
// Disk size: 500107862016 bytes
// IP address of eth0: 192.168.1.100

// Notes:

//     Some of these operations, especially those involving network and disk devices, may require root privileges. Running the program as a regular user might result in permission errors for certain commands (e.g., BLKGETSIZE for block devices or SIOCGIFADDR for network interfaces).
//     Always check the return values of ioctl() and handle errors appropriately. ioctl() may fail for various reasons depending on the device or command.