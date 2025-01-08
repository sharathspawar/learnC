#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[1024];
    int n;

    // Step 1: Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0); // IPv4, TCP
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Step 2: Prepare server address
    memset(&server_addr, 0, sizeof(server_addr));  // Clear structure
    server_addr.sin_family = AF_INET;               // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;       // Any available interface
    server_addr.sin_port = htons(PORT);             // Convert port to network byte order

    // Step 3: Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(1);
    }

    // Step 4: Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Step 5: Accept client connection
    client_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(1);
    }

    // Step 6: Print client IP address
    printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

    // Step 7: Communicate with the client
    n = recv(client_fd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error reading from socket");
        close(client_fd);
        close(server_fd);
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received from client: %s\n", buffer);

    // Step 8: Send a response to the client
    const char *response = "Hello from the server!";
    send(client_fd, response, strlen(response), 0);

    // Step 9: Close the sockets
    close(client_fd);
    close(server_fd);

    return 0;
}





// The <sys/socket.h> header in C provides definitions and functions for socket programming, which is crucial for network communication. It defines the interface for creating and managing sockets, sending and receiving data over the network, and handling different types of sockets (e.g., TCP, UDP).
// Key Concepts in <sys/socket.h>:

//     Socket Creation: You create a socket with the socket() function.
//     Socket Address Structures: These structures (sockaddr, sockaddr_in, etc.) are used to represent addresses of network entities (e.g., servers or clients).
//     Binding: You bind a socket to an address and port using the bind() function.
//     Listening and Accepting: For server sockets, you need to listen for incoming connections with listen() and accept them with accept().
//     Connecting: For client sockets, you connect to a server using connect().
//     Sending and Receiving Data: Use send() and recv() to send and receive data, or write() and read() for simpler communication.
//     Closing a Socket: Use close() to release resources associated with the socket.

// Important Structures:

//     struct sockaddr: A general structure for storing socket address information. Other specific structures like sockaddr_in (IPv4), sockaddr_in6 (IPv6), etc., are based on this.
//     struct sockaddr_in: Used to specify IPv4 addresses (IP and port).
//     struct sockaddr_in6: Used for IPv6 addresses.

// Key Functions:

//     socket(): Creates a new socket.
//     bind(): Binds a socket to a specific address and port.
//     listen(): Makes a socket ready to accept incoming connections (for TCP).
//     accept(): Accepts a connection from a client (for TCP).
//     connect(): Connects a socket to a remote address (for TCP).
//     send() / recv(): Sends and receives data over a socket.
//     close(): Closes a socket and releases associated resources.




// Explanation of the Code:
// Server Code:

//     Create Socket:
//         The server creates a socket using socket(AF_INET, SOCK_STREAM, 0).
//         AF_INET specifies IPv4, and SOCK_STREAM specifies TCP (a connection-oriented protocol).

//     Bind:
//         bind() associates the socket with a specific IP address and port (using INADDR_ANY to listen on all available network interfaces).
//         htons(PORT) ensures the port is in network byte order.

//     Listen and Accept:
//         The listen() function prepares the server to accept connections (maximum queue size of 5).
//         accept() accepts an incoming connection and returns a new socket for communication with the client.

//     Receive and Send Data:
//         The server receives data from the client using recv(), then sends a response back using send().

//     Close the Socket:
//         After communication, the server closes both the client socket and the server socket using close().

// Client Code:

//     Create Socket:
//         The client also creates a socket using socket(AF_INET, SOCK_STREAM, 0).

//     Server Address:
//         inet_addr(SERVER_IP) converts the server IP address (string form) into binary format.
//         htons(SERVER_PORT) converts the port number into network byte order.

//     Connect:
//         The connect() function connects the client socket to the server.

//     Send and Receive Data:
//         The client sends a message using send() and receives a response with recv().

//     Close the Socket:
//         After communication, the client closes its socket using close().

// Compilation and Execution:

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

// Received from server: Hello from the server!

// Notes:

//     Socket Types:
//         SOCK_STREAM (TCP) is used for connection-oriented communication.
//         SOCK_DGRAM (UDP) is used for connectionless communication.

//     Byte Order:
//         htons() and htonl() ensure that data is in network byte order (big-endian).
//         Similarly, ntohs() and ntohl() are used to convert network byte order data back to host byte order.

//     Error Handling:
//         Proper error handling (using perror() and checking