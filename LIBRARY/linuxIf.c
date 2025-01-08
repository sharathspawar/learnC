#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct ifreq ifr;
    char iface[] = "eth0"; // Replace with your interface name
    char ip[INET_ADDRSTRLEN];
    char mac[18];

    // Create a socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set interface name
    strncpy(ifr.ifr_name, iface, IFNAMSIZ);

    // Get interface flags
    if (ioctl(sock, SIOCGIFFLAGS, &ifr) == 0) {
        printf("Interface %s flags: 0x%x\n", iface, ifr.ifr_flags);
        if (ifr.ifr_flags & IFF_UP) {
            printf("  Interface is UP\n");
        }
        if (ifr.ifr_flags & IFF_RUNNING) {
            printf("  Interface is RUNNING\n");
        }
        if (ifr.ifr_flags & IFF_LOOPBACK) {
            printf("  Interface is LOOPBACK\n");
        }
    } else {
        perror("Failed to get interface flags");
    }

    // Get MAC address
    if (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0) {
        snprintf(mac, sizeof(mac), "%02x:%02x:%02x:%02x:%02x:%02x",
                 (unsigned char)ifr.ifr_hwaddr.sa_data[0],
                 (unsigned char)ifr.ifr_hwaddr.sa_data[1],
                 (unsigned char)ifr.ifr_hwaddr.sa_data[2],
                 (unsigned char)ifr.ifr_hwaddr.sa_data[3],
                 (unsigned char)ifr.ifr_hwaddr.sa_data[4],
                 (unsigned char)ifr.ifr_hwaddr.sa_data[5]);
        printf("MAC Address: %s\n", mac);
    } else {
        perror("Failed to get MAC address");
    }

    // Get IP address
    if (ioctl(sock, SIOCGIFADDR, &ifr) == 0) {
        struct sockaddr_in *ipaddr = (struct sockaddr_in *)&ifr.ifr_addr;
        inet_ntop(AF_INET, &ipaddr->sin_addr, ip, sizeof(ip));
        printf("IP Address: %s\n", ip);
    } else {
        perror("Failed to get IP address");
    }

    // Close the socket
    close(sock);

    return 0;
}




// The <linux/if.h> header in C provides constants, structures, and macros for managing network interfaces in Linux systems. It is primarily used for tasks like querying or configuring network interfaces via system calls such as ioctl.
// Key Features of <linux/if.h>:

//     Interface Names and Indexes:
//         Definitions for maximum interface name lengths (IFNAMSIZ).
//         Structures like ifreq for interfacing with ioctl.

//     Interface Flags:
//         Flags indicating the state and capabilities of interfaces (IFF_UP, IFF_BROADCAST, IFF_LOOPBACK, etc.).

//     Socket Address Structures:
//         Structures for managing hardware addresses, IP addresses, and more.

//     Constants:
//         Various constants for interface operations (IFHWADDRLEN, IFNAMSIZ).

// Important Elements of <linux/if.h>:
// Constants:

//     IFNAMSIZ: Maximum size of a network interface name (usually 16 bytes).
//     IFHWADDRLEN: Maximum hardware address length (6 bytes for MAC addresses).

// Flags:

//     IFF_UP: Interface is up.
//     IFF_BROADCAST: Interface supports broadcasting.
//     IFF_LOOPBACK: Interface is a loopback device.
//     IFF_RUNNING: Interface is operational.
//     IFF_PROMISC: Interface is in promiscuous mode.
//     IFF_MULTICAST: Interface supports multicast.

// Structures:

//     struct ifreq: Used for ioctl calls to get/set interface parameters.
//         Fields include:
//             ifr_name: Interface name (e.g., "eth0").
//             ifr_flags: Flags representing the interface state.
//             ifr_addr: Address of the interface.
//             ifr_hwaddr: Hardware (MAC) address.




// Explanation of the Code:

//     Socket Creation:
//         A socket is created using socket(AF_INET, SOCK_DGRAM, 0) to interact with network interfaces.

//     Set Interface Name:
//         The name of the interface (e.g., eth0) is copied into ifr.ifr_name.

//     Query Flags:
//         The SIOCGIFFLAGS ioctl command retrieves the flags of the interface (e.g., whether it's UP, RUNNING, etc.).

//     Get MAC Address:
//         The SIOCGIFHWADDR ioctl command retrieves the hardware (MAC) address of the interface.

//     Get IP Address:
//         The SIOCGIFADDR ioctl command retrieves the IPv4 address of the interface.

// Compilation:

// To compile the program, use the following command:

// gcc -o if_example if_example.c

// Execution:

// Run the program with root privileges (required for certain ioctl operations):

// sudo ./if_example

// Sample Output:

// Interface eth0 flags: 0x1043
//   Interface is UP
//   Interface is RUNNING
// MAC Address: 08:00:27:12:34:56
// IP Address: 192.168.1.100

// Key Points:

//     Portability:
//         <linux/if.h> is specific to Linux. Use <net/if.h> for more portable code.

//     Practical Uses:
//         Querying and configuring network interfaces (e.g., enabling promiscuous mode or modifying IP settings).

//     Safety:
//         Always check the return values of ioctl and other system calls to handle errors gracefully.

//     Privilege Requirements:
//         Many operations involving ioctl on network interfaces require superuser privileges.

// This program provides a comprehensive example of using <linux/if.h> to manage network interfaces in Linux, demonstrating key functionalities with detailed explanations.