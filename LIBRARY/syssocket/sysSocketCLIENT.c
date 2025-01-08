#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[1024];
    int n;

    // Step 1: Create socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);  // IPv4, TCP
    if (client_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Step 2: Prepare server address
    memset(&server_addr, 0, sizeof(server_addr));  // Clear structure
    server_addr.sin_family = AF_INET;               // IPv4
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP); // Server IP address
    server_addr.sin_port = htons(SERVER_PORT);      // Convert port to network byte order

    // Step 3: Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(client_fd);
        exit(1);
    }

    // Step 4: Send a message to the server
    const char *message = "Hello from client!";
    send(client_fd, message, strlen(message), 0);

    // Step 5: Receive a response from the server
    n = recv(client_fd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error reading from socket");
        close(client_fd);
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received from server: %s\n", buffer);

    // Step 6: Close the socket
    close(client_fd);

    return 0;
}
