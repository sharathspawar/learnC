#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>

void get_ip_address(const char *interface) {
    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // Create a socket

    if (sockfd == -1) {
        perror("socket");
        return;
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ);  // Set interface name

    // Get IP address of the interface
    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl");
        close(sockfd);
        return;
    }

    struct sockaddr_in *ipaddr = (struct sockaddr_in *)&ifr.ifr_addr;
    printf("IP address of %s: %s\n", interface, inet_ntoa(ipaddr->sin_addr));

    close(sockfd);
}

void get_mac_address(const char *interface) {
    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // Create a socket

    if (sockfd == -1) {
        perror("socket");
        return;
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ);  // Set interface name

    // Get MAC address of the interface
    if (ioctl(sockfd, SIOCGIFHWADDR, &ifr) == -1) {
        perror("ioctl");
        close(sockfd);
        return;
    }

    unsigned char *mac = (unsigned char *)ifr.ifr_hwaddr.sa_data;
    printf("MAC address of %s: %02x:%02x:%02x:%02x:%02x:%02x\n", interface,
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    close(sockfd);
}

void get_netmask(const char *interface) {
    struct ifreq ifr;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // Create a socket

    if (sockfd == -1) {
        perror("socket");
        return;
    }

    strncpy(ifr.ifr_name, interface, IFNAMSIZ);  // Set interface name

    // Get netmask of the interface
    if (ioctl(sockfd, SIOCGIFNETMASK, &ifr) == -1) {
        perror("ioctl");
        close(sockfd);
        return;
    }

    struct sockaddr_in *netmask = (struct sockaddr_in *)&ifr.ifr_netmask;
    printf("Netmask of %s: %s\n", interface, inet_ntoa(netmask->sin_addr));

    close(sockfd);
}

int main() {
    const char *interface = "eth0";  // Name of the network interface

    // Get IP address
    get_ip_address(interface);

    // Get MAC address
    get_mac_address(interface);

    // Get netmask
    get_netmask(interface);

    return 0;
}




// The <net/if.h> header file is used in C programming for network interface management in Unix-like operating systems. It provides functions and structures for querying and configuring network interfaces such as Ethernet, Wi-Fi, and loopback interfaces. This header file is primarily used to interact with network interfaces and obtain their properties (such as IP addresses, MAC addresses, and network statistics).
// Key Concepts and Functions in <net/if.h>:

//     struct ifreq: A structure used to represent an interface request, which holds information about network interfaces.
//     ioctl(): A system call that allows for device-specific operations, including network interfaces.
//     SIOCGIFADDR: An ioctl command to get the IP address of an interface.
//     SIOCGIFHWADDR: An ioctl command to get the MAC address of an interface.
//     SIOCGIFNETMASK: An ioctl command to get the network mask of an interface.
//     SIOCGIFBRDADDR: An ioctl command to get the broadcast address of an interface.

// Key Structures in <net/if.h>:

//     struct ifreq: This structure is used for interacting with network interface devices. It contains various fields such as the interface name, the IP address, the MAC address, etc.
//     struct ifconf: A structure used to obtain a list of network interfaces.

// Functions and Commands in Detail:
// 1. struct ifreq:

// This structure is used in combination with the ioctl() system call to interact with network interfaces.

// struct ifreq {
//     char ifr_name[IFNAMSIZ];    // Interface name, e.g., "eth0", "wlan0"
//     union {
//         struct sockaddr ifr_addr;
//         struct sockaddr ifr_dstaddr;
//         struct sockaddr ifr_broadaddr;
//         struct sockaddr ifr_netmask;
//         struct sockaddr ifr_hwaddr;
//         short           ifr_flags;
//         int             ifr_ifindex;
//         struct mtu     ifr_mtu;
//     };
// };

//     ifr_name: Name of the network interface (e.g., "eth0").
//     ifr_addr: The IP address of the interface.
//     ifr_hwaddr: The MAC address of the interface.
//     ifr_flags: Flags representing the status of the interface.
//     ifr_mtu: The MTU (Maximum Transmission Unit) size of the interface.

// 2. ioctl():

// The ioctl() system call is used to manipulate the underlying device parameters of special files. It can interact with network interfaces to get and set interface properties.

// int ioctl(int fd, unsigned long request, ...);

//     fd: The file descriptor for the device (use socket() for networking devices).
//     request: The command (e.g., SIOCGIFADDR, SIOCGIFHWADDR).
//     ...: Additional arguments required by the specific command.

// 3. SIOCGIFADDR:

// This ioctl command is used to get the IP address of a network interface.

// #define SIOCGIFADDR 0x8915

// 4. SIOCGIFHWADDR:

// This ioctl command is used to get the MAC address of a network interface.

// #define SIOCGIFHWADDR 0x8927

// 5. SIOCGIFNETMASK:

// This ioctl command is used to get the network mask of a network interface.

// #define SIOCGIFNETMASK 0x891b

// 6. SIOCGIFBRDADDR:

// This ioctl command is used to get the broadcast address of a network interface.

// #define SIOCGIFBRDADDR 0x8919




// Explanation of the Code:

//     get_ip_address(const char *interface):
//         This function retrieves the IP address of a network interface using the SIOCGIFADDR ioctl command. It creates a socket, sets the interface name in the ifr structure, and calls ioctl() to get the IP address. The address is then printed using inet_ntoa().

//     get_mac_address(const char *interface):
//         This function retrieves the MAC address of a network interface using the SIOCGIFHWADDR ioctl command. It extracts the MAC address from the ifr structure and prints it in a readable format (e.g., 00:11:22:33:44:55).

//     get_netmask(const char *interface):
//         This function retrieves the netmask of a network interface using the SIOCGIFNETMASK ioctl command. It extracts the netmask from the ifr structure and prints it in a readable format.

//     main():
//         In the main function, we call the three functions (get_ip_address(), get_mac_address(), and get_netmask()) for a given interface ("eth0" in this case).

// Compilation and Execution:

// Save the code as if_demo.c, and compile it using gcc:

// gcc -o if_demo if_demo.c

// Run the program:

// ./if_demo

// Sample Output:

// IP address of eth0: 192.168.1.2
// MAC address of eth0: 00:1a:2b:3c:4d:5e
// Netmask of eth0: 255.255.255.0

// Notes:

//     Permissions: Accessing network interface information typically requires root privileges, so you might need to run the program as sudo for certain interfaces.
//     Network Interface: The name of the network interface may vary depending on the system configuration (e.g., eth0, wlan0, lo for loopback). Ensure that you use the correct interface name for your system.
//     Error Handling: The program handles errors gracefully, printing appropriate error messages if any ioctl operation fails.

// This example program provides a basic demonstration of how to interact with network interfaces using the <net/if.h> header in C. It covers fetching the IP address, MAC address, and netmask of a given interface using ioctl() commands.