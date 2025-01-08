#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <linux/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Step 1: Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Step 2: Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;  // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Bind to all available interfaces
    server_addr.sin_port = htons(PORT);  // Convert port to network byte order

    // Step 3: Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_fd);
        exit(1);
    }

    // Step 4: Listen for incoming connections
    if (listen(server_fd, 3) == -1) {
        perror("Listen failed");
        close(server_fd);
        exit(1);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Step 5: Accept incoming connections
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
    if (client_fd == -1) {
        perror("Accept failed");
        close(server_fd);
        exit(1);
    }

    // Step 6: Get and print the client's IP address
    printf("Client connected from IP: %s\n", inet_ntoa(client_addr.sin_addr));

    // Step 7: Receive data from the client
    bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received == -1) {
        perror("Receive failed");
        close(client_fd);
        close(server_fd);
        exit(1);
    }

    buffer[bytes_received] = '\0';  // Null-terminate the received data
    printf("Received from client: %s\n", buffer);

    // Step 8: Send a response to the client
    const char *response = "Hello from server!";
    if (send(client_fd, response, strlen(response), 0) == -1) {
        perror("Send failed");
        close(client_fd);
        close(server_fd);
        exit(1);
    }

    // Step 9: Close the client and server sockets
    close(client_fd);
    close(server_fd);

    return 0;
}





// The <linux/in.h> header is part of the Linux system's networking APIs and defines constants and structures related to IP addresses and internet domain sockets. It provides functionality for working with Internet Protocol (IP) addresses and is used in applications that require socket programming for network communication, particularly with IPv4 addresses.
// Key Concepts in <linux/in.h>:

//     Internet Addressing: Defines structures and constants for dealing with IP addresses.
//     Socket Programming: Provides constants for use in creating and manipulating sockets.
//     Address Structures: Defines structures to represent Internet Protocol addresses (IPv4 and IPv6).

// Key Definitions and Structures:

//     struct sockaddr_in:
//         This structure is used to represent an IPv4 address.
//         Contains fields for the address family (AF_INET), port number, and the actual IP address.

//     INADDR_ANY:
//         Represents the special IP address 0.0.0.0, used to bind a socket to all available interfaces.

//     INADDR_LOOPBACK:
//         Represents the loopback IP address 127.0.0.1.

//     htons() and ntohs():
//         Functions used to convert port numbers between host byte order and network byte order.

//     inet_pton() and inet_ntop():
//         Functions used to convert IP addresses between text (string) format and binary format.



// Explanation of the Code:

//     Create Socket:
//         server_fd = socket(AF_INET, SOCK_STREAM, 0);
//             Creates a TCP/IP socket (SOCK_STREAM) using the IPv4 address family (AF_INET).
//             The socket() function returns a file descriptor that will be used to interact with the socket.

//     Setup Server Address:
//         server_addr.sin_family = AF_INET;
//             Sets the address family to AF_INET (IPv4).
//         server_addr.sin_addr.s_addr = INADDR_ANY;
//             Binds the socket to all available interfaces (i.e., it will accept connections from any IP address).
//         server_addr.sin_port = htons(PORT);
//             Converts the port number to network byte order using htons() (host-to-network short).

//     Bind Socket:
//         bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
//             Associates the socket with the specified address and port using the bind() function.

//     Listen for Connections:
//         listen(server_fd, 3);
//             Puts the socket into listening mode, waiting for incoming connections. The 3 specifies the backlog (maximum number of connections that can be waiting while the server is handling another connection).

//     Accept Client Connection:
//         client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
//             Accepts an incoming connection and returns a new socket file descriptor (client_fd) for the client communication.
//             The client’s address is stored in client_addr, and the size of the address structure is passed via addr_len.

//     Print Client IP:
//         inet_ntoa(client_addr.sin_addr);
//             Converts the client's IP address from binary format (sin_addr.s_addr) to a human-readable string (IPv4 format) using inet_ntoa().

//     Receive Data:
//         bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
//             Reads data sent by the client into the buffer. The recv() function is used to receive data on the socket.

//     Send Response:
//         send(client_fd, response, strlen(response), 0);
//             Sends a response back to the client using the send() function.

//     Close Sockets:
//         close(client_fd); close(server_fd);
//             Closes the client and server sockets after the communication is finished.

// Key Functions and Concepts:

//     socket():
//         Creates a socket and returns a file descriptor used for communication. The arguments specify the domain (IPv4), type (TCP/UDP), and protocol (0 for default).

//     bind():
//         Binds a socket to a specific IP address and port. It associates the socket with the provided sockaddr_in structure.

//     listen():
//         Prepares the server socket to accept incoming connections. It specifies how many connections can be queued at a time.

//     accept():
//         Accepts an incoming client connection. It returns a new socket file descriptor for the client, while the original socket continues to listen for new connections.

//     recv():
//         Receives data from the client. The function returns the number of bytes received.

//     send():
//         Sends data to the client. It returns the number of bytes sent.

//     inet_ntoa():
//         Converts an IPv4 address from network byte order to a readable string (e.g., "127.0.0.1").

//     htons():
//         Converts the port number from host byte order to network byte order.

// Compilation:

// To compile the program, use the following command:

// gcc -o socket_example socket_example.c

// Execution:

// Run the program with:

// ./socket_example

// Sample Output:

// Server is listening on port 8080...
// Client connected from IP: 127.0.0.1
// Received from client: Hello from client!

// Key Constants from <linux/in.h>:

//     INADDR_ANY: 0.0.0.0 — a special address used for binding to all available network interfaces.
//     INADDR_LOOPBACK: 127.0.0.1 — the loopback address used for local communication within the same machine.

// Conclusion:

// This example demonstrates how to use the <linux/in.h> header for basic socket programming with IPv4 addresses. It shows how to create a socket, bind it to a port, listen for incoming connections, and exchange data with clients using TCP. The program uses key structures like sockaddr_in and functions like inet_ntoa(), htons(), recv(), and send() to implement network communication.

