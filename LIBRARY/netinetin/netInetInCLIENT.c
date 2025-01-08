#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n;

    // Step 1: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Step 2: Prepare server address
    memset(&server_addr, 0, sizeof(server_addr));  // Clear the structure
    server_addr.sin_family = AF_INET;               // IPv4
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); // Server IP address
    server_addr.sin_port = htons(SERVER_PORT);      // Convert port to network byte order

    // Step 3: Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        exit(1);
    }

    // Step 4: Send message to the server
    const char *message = "Hello from client!";
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("Error writing to socket");
        close(sockfd);
        exit(1);
    }

    // Step 5: Receive response from the server
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        close(sockfd);
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received from server: %s\n", buffer);

    // Step 6: Close the socket
    close(sockfd);

    return 0;
}






// The <netinet/in.h> header file in C is part of the POSIX standard and provides constants, macros, and function prototypes used for network communication, particularly for Internet-based networking. It is commonly used when working with the socket() API for setting up networking applications, such as creating servers and clients.
// Key Concepts in <netinet/in.h>:

//     Internet Addresses: The file provides structures and functions to handle internet addresses, including IPv4 and IPv6.
//     struct sockaddr_in and struct sockaddr_in6: These structures represent IPv4 and IPv6 addresses, respectively.
//     htons() and ntohs(): Functions to convert data between host and network byte order (big-endian vs. little-endian).
//     inet_pton() and inet_ntop(): Functions for converting IP addresses between binary and text representations.
//     htons() and ntohs(): These are used to convert short integers between host and network byte order.

// Key Structures and Constants:

//     struct sockaddr_in: Represents an IPv4 socket address.
//     struct sockaddr_in6: Represents an IPv6 socket address.
//     INADDR_ANY, INADDR_LOOPBACK, INADDR_BROADCAST: Constants representing special IPv4 addresses.
//     AF_INET, AF_INET6: Address families for IPv4 and IPv6 sockets.
//     SOCK_STREAM, SOCK_DGRAM: Socket types for TCP and UDP.

// Functions in <netinet/in.h>:

//     inet_pton(): Converts a textual IP address into its binary form (network byte order).

// int inet_pton(int af, const char *src, void *dst);

//     af: Address family (AF_INET for IPv4 or AF_INET6 for IPv6).
//     src: The string containing the IP address.
//     dst: A pointer to a buffer where the binary address will be stored.

// inet_ntop(): Converts a binary IP address into its string representation.

// const char *inet_ntop(int af, const void *src, char *dst, socklen_t size);

//     af: Address family (AF_INET for IPv4 or AF_INET6 for IPv6).
//     src: The binary IP address to convert.
//     dst: The buffer where the string representation of the IP will be stored.
//     size: The size of the destination buffer.

// htons() and ntohs(): Convert short integers between host and network byte order.

// uint16_t htons(uint16_t hostshort);
// uint16_t ntohs(uint16_t netshort);

// htonl() and ntohl(): Convert long integers between host and network byte order.

// uint32_t htonl(uint32_t hostlong);
// uint32_t ntohl(uint32_t netlong);






// Explanation of the Code:
// Server Code:

//     Create Socket:
//         The server creates a socket using socket(AF_INET, SOCK_STREAM, 0) where AF_INET specifies IPv4 and SOCK_STREAM specifies a TCP socket.

//     Bind:
//         The bind() function binds the socket to a specific port on the machine (INADDR_ANY tells it to listen on all network interfaces).
//         The htons(PORT) function is used to ensure the port number is in network byte order (big-endian format).

//     Listen and Accept:
//         The server listens for incoming connections and accepts them with accept(). It then prints the client's IP address using inet_ntoa() to convert the binary address to a human-readable string.

//     Read and Write:
//         The server reads data from the client and then sends a response back.

// Client Code:

//     Create Socket:
//         The client also creates a socket using socket(AF_INET, SOCK_STREAM, 0).

//     Server Address:
//         The inet_addr(SERVER_IP) function is used to convert the server IP (in string format) to a binary format.
//         The htons(SERVER_PORT) function converts the port number to network byte order.

//     Connect:
//         The connect() function connects the client to the server using the provided address.

//     Send and Receive Data:
//         The client sends a message to the server and receives a response.

// Compilation and Execution:

// To compile and run the server and client programs, follow these steps:

//     Server Compilation:

// gcc -o server server.c

//     Client Compilation:

// gcc -o client client.c

//     Running the Programs:

//     First, start the server:

// ./server

// Then, start the client in a different terminal:

// ./client

// Sample Output:
// Server Output:

// Server listening on port 8080...
// Client connected: 127.0.0.1
// Received from client: Hello from client!

// Client Output:

// Received from server: Hello from server!

// Notes:

//     IP Conversion:
//         The program demonstrates how to convert between text-based IP addresses and binary format using inet_pton() and inet_ntop().
//     Network Byte Order:
//         The htons() and htonl() functions ensure that port numbers and IP addresses are transmitted in the correct byte order across networks.

// This program illustrates how to create a simple network application using IPv4, including setting up a socket, binding it to an address, connecting clients to the server, and exchanging messages. It also demonstrates how to handle IP addresses and byte order conversions using the <netinet/in.h> library.