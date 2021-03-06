

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4455

void main()
{
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    memset(&server_addr, '\0', sizeof(server_addr));
printf("[+] socket created successfully\n");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
 
    printf("[+] client socket is created succesfully\n");
    while (1) {
	sleep(2);
    recv(client_socket, buffer, 1024, 0);
    printf("[+]data received :\n %s", buffer);
    }
    printf("[+]data received :\n %s", buffer);
}
