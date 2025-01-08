#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

void get_host_by_name(const char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        return;
    }
    
    printf("Host: %s\n", host->h_name);
    printf("Official name: %s\n", host->h_name);
    
    char **addr_list = host->h_addr_list;
    printf("IP addresses:\n");
    for (int i = 0; addr_list[i] != NULL; i++) {
        struct in_addr addr;
        memcpy(&addr, addr_list[i], sizeof(struct in_addr));
        printf("  %s\n", inet_ntoa(addr));
    }
}

void get_info_by_addr(const char *ip) {
    struct in_addr addr;
    inet_pton(AF_INET, ip, &addr);
    
    struct hostent *host = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    if (host == NULL) {
        herror("gethostbyaddr");
        return;
    }
    
    printf("IP Address: %s\n", ip);
    printf("Host Name: %s\n", host->h_name);
}

void get_service_by_name(const char *service, const char *protocol) {
    struct servent *srv = getservbyname(service, protocol);
    if (srv == NULL) {
        herror("getservbyname");
        return;
    }

    printf("Service: %s\n", srv->s_name);
    printf("Port: %d\n", ntohs(srv->s_port));
}

void get_address_info(const char *hostname, const char *service) {
    struct addrinfo hints, *res;
    
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP
    
    int status = getaddrinfo(hostname, service, &hints, &res);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return;
    }
    
    printf("Address Information for %s:%s\n", hostname, service);
    
    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    char ipstr[INET_ADDRSTRLEN];
    inet_ntop(res->ai_family, &(ipv4->sin_addr), ipstr, sizeof(ipstr));
    printf("  IP address: %s\n", ipstr);
    
    freeaddrinfo(res);
}

int main() {
    const char *hostname = "www.example.com";
    const char *ip_address = "93.184.216.34";  // IP of www.example.com
    const char *service = "http";
    const char *protocol = "tcp";

    // 1. Get host information by name
    get_host_by_name(hostname);
    
    // 2. Get host information by IP address
    get_info_by_addr(ip_address);
    
    // 3. Get service information by name
    get_service_by_name(service, protocol);
    
    // 4. Get address information by hostname and service
    get_address_info(hostname, service);

    return 0;
}







// The <netdb.h> header provides functions and definitions for network database operations. It defines structures and functions that allow you to look up information about hosts, services, and protocols, which is essential when working with network programming in C.
// Key Concepts and Functions in <netdb.h>:

//     gethostbyname(): This function retrieves host information given a hostname (e.g., domain name).
//     gethostbyaddr(): This function retrieves host information given an IP address.
//     getaddrinfo(): A more modern and flexible function than gethostbyname() and gethostbyaddr(). It allows you to retrieve address information for both IPv4 and IPv6.
//     getnameinfo(): This function converts a socket address into a human-readable name (reverse of getaddrinfo()).
//     getservbyname(): This function retrieves service information given a service name (like http, ftp) and its protocol.
//     getservbyport(): This function retrieves service information given a port number and protocol.
//     h_errno: This variable stores error codes for hostname lookup operations.

// Functions in Detail:
// 1. gethostbyname():

// This function retrieves host information given a hostname.

// struct hostent *gethostbyname(const char *name);

//     name: The hostname (e.g., "www.example.com").
//     Returns a pointer to a struct hostent containing host information, or NULL on failure.

// 2. gethostbyaddr():

// This function retrieves host information given an IP address.

// struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type);

//     addr: The address of the host (in network byte order).
//     len: The length of the address.
//     type: The type of address (e.g., AF_INET for IPv4).

// 3. getaddrinfo():

// This function retrieves address information for both IPv4 and IPv6.

// int getaddrinfo(const char *node, const char *service,
//                 const struct addrinfo *hints, struct addrinfo **res);

//     node: The hostname or IP address.
//     service: The service name (e.g., "http") or port number.
//     hints: A pointer to a struct addrinfo with hints about the types of addresses to return.
//     res: A pointer to a list of address structures returned.

// 4. getnameinfo():

// This function converts a socket address into a human-readable name.

// int getnameinfo(const struct sockaddr *sa, socklen_t salen,
//                 char *host, size_t hostlen,
//                 char *serv, size_t servlen, int flags);

//     sa: A pointer to the socket address structure.
//     host: A buffer to store the host name.
//     serv: A buffer to store the service name.

// 5. getservbyname():

// This function retrieves service information by name.

// struct servent *getservbyname(const char *name, const char *proto);

//     name: The name of the service (e.g., "http").
//     proto: The protocol used (e.g., "tcp").

// 6. getservbyport():

// This function retrieves service information by port number.

// struct servent *getservbyport(int port, const char *proto);

//     port: The port number.
//     proto: The protocol used (e.g., "tcp").








// Explanation of the Code:

//     get_host_by_name(const char *hostname):
//         Uses gethostbyname() to retrieve host information for the given hostname (e.g., "www.example.com").
//         Prints the official host name and all associated IP addresses.

//     get_info_by_addr(const char *ip):
//         Uses gethostbyaddr() to retrieve host information for a given IP address.
//         This is the reverse lookup function that translates an IP address into a hostname.

//     get_service_by_name(const char *service, const char *protocol):
//         Uses getservbyname() to retrieve service information for a given service name (e.g., "http") and protocol (e.g., "tcp").
//         Prints the service's name and port number.

//     get_address_info(const char *hostname, const char *service):
//         Uses getaddrinfo() to retrieve a list of address structures for the given hostname and service. This allows you to retrieve address information for both IPv4 and IPv6.
//         Prints the IP address of the given hostname and service.

// Compilation and Execution:

// Save the code as netdb_demo.c, and compile it using gcc:

// gcc -o netdb_demo netdb_demo.c

// Run the program:

// ./netdb_demo

// Sample Output:

// Host: www.example.com
// Official name: www.example.com
// IP addresses:
//   93.184.216.34
// IP Address: 93.184.216.34
// Host Name: www.example.com
// Service: http
// Port: 80
// Address Information for www.example.com:http
//   IP address: 93.184.216.34

// Notes:

//     gethostbyname() and gethostbyaddr() are legacy functions, and it is recommended to use getaddrinfo() in modern network programming because it supports both IPv4 and IPv6 and provides more flexibility.
//     getaddrinfo() is more robust and flexible, allowing you to handle both IPv4 and IPv6 addresses, as well as the ability to specify socket types (e.g., SOCK_STREAM for TCP).
//     For the gethostbyname() and gethostbyaddr() functions, you may encounter deprecation warnings in modern compilers, so it’s best to use getaddrinfo() where possible.