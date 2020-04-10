

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

    sockfd = socket(PF_INET, SOCK_DGRAM, 0);
    memset(&serverAddr, '\0', sizeof(serverAddr));



    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    

   strcpy(buffer, "hello server\n");
   sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

   printf("[+]data send %s", buffer);

   recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));

   printf("[+]data recv %s", buffer);


    

}
