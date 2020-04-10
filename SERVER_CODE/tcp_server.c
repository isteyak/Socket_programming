

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
    int sockfd;

    struct sockaddr_in serverAddr;

    int newSocket;

    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char buffer[1024];

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    printf("[+] server socket created successfully\n");
    memset(&serverAddr, '\0', sizeof(serverAddr));



    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    

    bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("[+]bind to the port number %d\n", 4455);
    
    listen(sockfd, 5);
    printf("[+] listening.....\n");

    addr_size = sizeof(newAddr);
    
    newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

    strcpy(buffer, "hello");
    while (1) 
{
    sleep(2);
    send(newSocket, buffer, strlen(buffer), 0);
}
}
