#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[1024];
    int n;

    // Step 1: Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Step 2: Prepare server address
    memset(&server_addr, 0, sizeof(server_addr)); // Clear the structure
    server_addr.sin_family = AF_INET;              // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;      // Listen on all interfaces
    server_addr.sin_port = htons(PORT);            // Convert port to network byte order

    // Step 3: Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(sockfd);
        exit(1);
    }

    // Step 4: Listen for connections
    listen(sockfd, 5);
    printf("Server listening on port %d...\n", PORT);

    // Step 5: Accept client connection
    client_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd < 0) {
        perror("Error accepting connection");
        close(sockfd);
        exit(1);
    }

    // Step 6: Get and print client address
    printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));

    // Step 7: Communicate with the client
    n = read(newsockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading from socket");
        close(newsockfd);
        close(sockfd);
        exit(1);
    }
    buffer[n] = '\0';
    printf("Received from client: %s\n", buffer);

    // Step 8: Send a message to the client
    const char *message = "Hello from server!";
    n = write(newsockfd, message, strlen(message));
    if (n < 0) {
        perror("Error writing to socket");
        close(newsockfd);
        close(sockfd);
        exit(1);
    }

    // Step 9: Close the sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}
