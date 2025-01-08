#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>  // Include arpa/inet.h for inet_pton, inet_ntop, htonl, htons

int main() {
    // Example 1: Convert IP address from string to binary format (inet_pton)
    const char *ip_string = "192.168.1.1";
    struct in_addr ip_binary;  // Struct to hold binary representation
    if (inet_pton(AF_INET, ip_string, &ip_binary) == 1) {
        printf("IP address '%s' converted to binary: %u\n", ip_string, ip_binary.s_addr);
    } else {
        printf("Invalid IP address format\n");
    }

    // Example 2: Convert IP address from binary to string format (inet_ntop)
    char ip_string_out[INET_ADDRSTRLEN];  // Buffer to hold string output
    if (inet_ntop(AF_INET, &ip_binary, ip_string_out, INET_ADDRSTRLEN)) {
        printf("Binary IP address converted back to string: %s\n", ip_string_out);
    } else {
        printf("Error converting binary IP address to string\n");
    }

    // Example 3: Convert port number from host byte order to network byte order (htons)
    uint16_t port_host = 8080;  // Port number in host byte order
    uint16_t port_network = htons(port_host);  // Convert to network byte order
    printf("Port %u in host byte order is converted to network byte order: %u\n", port_host, port_network);

    // Example 4: Convert port number from network byte order to host byte order (ntohs)
    uint16_t port_host_back = ntohs(port_network);  // Convert back to host byte order
    printf("Port %u in network byte order is converted back to host byte order: %u\n", port_network, port_host_back);

    // Example 5: Convert IP address from host byte order to network byte order (htonl)
    uint32_t ip_host = 3232235777;  // IP address in host byte order (e.g., 192.168.1.1)
    uint32_t ip_network = htonl(ip_host);  // Convert to network byte order
    printf("IP address %u in host byte order is converted to network byte order: %u\n", ip_host, ip_network);

    // Example 6: Convert IP address from network byte order to host byte order (ntohl)
    uint32_t ip_host_back = ntohl(ip_network);  // Convert back to host byte order
    printf("IP address %u in network byte order is converted back to host byte order: %u\n", ip_network, ip_host_back);

    return 0;
}





// The <arpa/inet.h> header file in C is a standard library for Internet operations. It provides functions to manipulate Internet addresses in both human-readable (string) format and binary (network) format. It plays an important role in socket programming, especially when working with IP addresses and ports.
// Key Functions in <arpa/inet.h>:

//     inet_pton(): Converts an IP address from its text (string) form to its binary form.
//     inet_ntop(): Converts an IP address from its binary form to its text (string) form.
//     ntohs() and htons(): Convert port numbers between host byte order and network byte order.
//     ntohl() and htonl(): Convert IP addresses between host byte order and network byte order.

// Overview of Functions:

//     inet_pton(): Takes an IP address in string format (e.g., "192.168.0.1") and converts it to binary format (e.g., 0xC0A80001).
//     inet_ntop(): Takes an IP address in binary format and converts it back to a string format.
//     htonl() / ntohl(): Convert a 32-bit number (like an IP address) between host byte order and network byte order.
//     htons() / ntohs(): Convert a 16-bit number (like a port number) between host byte order and network byte order.



// Explanation of the Code:

//     inet_pton():
//         inet_pton(AF_INET, ip_string, &ip_binary);
//         Converts the string representation of the IP address ("192.168.1.1") into a binary format (ip_binary.s_addr), which can be used in socket programming for binding, connecting, etc.
//         The AF_INET argument specifies that we are working with IPv4 addresses. This function returns 1 on success, 0 if the string is not a valid address, and -1 on error.

//     inet_ntop():
//         inet_ntop(AF_INET, &ip_binary, ip_string_out, INET_ADDRSTRLEN);
//         Converts the binary representation of an IP address back to its string form. INET_ADDRSTRLEN is a constant that defines the maximum length of the string (including the null terminator).
//         This function returns a pointer to the string representation of the IP address.

//     htons() and ntohs():
//         htons() converts a 16-bit port number from host byte order to network byte order. Network byte order is Big-Endian (most significant byte first).
//         ntohs() converts the port number back from network byte order to host byte order.

//     htonl() and ntohl():
//         htonl() converts a 32-bit IP address from host byte order to network byte order.
//         ntohl() converts the IP address back from network byte order to host byte order.

// Key Constants and Types:

//     struct in_addr: This structure is used to represent an IPv4 address in binary format.
//         s_addr: A 32-bit field that holds the binary representation of the IP address.

//     AF_INET: This constant represents the address family for IPv4 addresses.

//     INET_ADDRSTRLEN: Defines the maximum length of an IPv4 address string (16 characters, including the null terminator).

// Compilation:

// To compile the program, use the following command:

// gcc -o arpa_inet_example arpa_inet_example.c

// Execution:

// Run the program with:

// ./arpa_inet_example

// Sample Output:

// IP address '192.168.1.1' converted to binary: 3232235777
// Binary IP address converted back to string: 192.168.1.1
// Port 8080 in host byte order is converted to network byte order: 8080
// Port 8080 in network byte order is converted back to host byte order: 8080
// IP address 3232235777 in host byte order is converted to network byte order: 3232235777
// IP address 3232235777 in network byte order is converted back to host byte order: 3232235777

// Explanation of Sample Output:

//     IP Address Conversion:
//         The program first converts the string "192.168.1.1" to binary format, represented as 3232235777.
//         Then, it converts this binary value back to the string "192.168.1.1" using inet_ntop().

//     Port Number Conversion:
//         The port number 8080 is converted from host byte order to network byte order using htons() and back using ntohs(). Since 8080 is already in network byte order (the system's endianness is often the same for ports), the numbers remain the same.

//     IP Address (32-bit) Conversion:
//         The integer value 3232235777 corresponds to the IP address 192.168.1.1 in host byte order. The program converts it to network byte order using htonl() and then back to host byte order using ntohl().

// Summary:

//     <arpa/inet.h> is used to convert between string and binary formats for IP addresses and port numbers.
//     inet_pton() converts an IP address from string format to binary format.
//     inet_ntop() converts an IP address from binary format to string format.
//     htonl() / ntohl() and htons() / ntohs() are used to convert IP addresses and port numbers between host byte order and network byte order.
//     This library is essential for socket programming, especially when dealing with IP addresses and ports in network communications.

// This example demonstrates how to use the functions provided by <arpa/inet.h> to handle IP addresses and ports, making it easier to work with network-related tasks in C.