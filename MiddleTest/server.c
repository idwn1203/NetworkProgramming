#include "headerFiles.h"
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 256
#define HOST_PORT1 50000
#define HOST_PORT2 50001
#define CLIENT_NUM 5

int clientfd;
int serverfd;

int clientfd1;
int serverfd1;

void process_exit(int sig)
{
    close(clientfd);
    close(serverfd);
    close(clientfd1);
    close(serverfd1);
}

int main(int argc, char *argv[])
{

    signal(SIGKILL, process_exit);
    char buffer_tcp[BUFFER_SIZE];
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    //tcp seatting
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(HOST_PORT1);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);

    // udp variable
    //int s;
    int len;
    char buffer_udp[BUFFER_SIZE];
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    int clntAddrLen;

    // udp seatting

    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(HOST_PORT2);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);


    //tcp Start
    if (clientfd < 0)
    {
        perror("Listen fail");
        exit(1);
    }

    if (bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("bind fail");
        exit(1);
    }

    if (listen(serverfd, CLIENT_NUM) < 0)
    {
        perror("listen fail");
        exit(1);
    }
    int clientSize = sizeof(clientAddr);
    clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, (socklen_t *)&clientSize);
    fcntl(serverfd,F_SETFL,O_NONBLOCK);
      if (clientfd < 0)
    {
        perror("accept fail");
        exit(1);
    }

    printf("udp conenction start \n");
    //udp connection
    if ((clientfd1 = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("ERROR:SOCKET FAILED!");
        exit(1);
    }

   if (bind(clientfd1, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        perror("Error:bind failed!");
        exit(1);
    }

    // ssize_t nbytes = 0;
    int cursor = 0;
    //server start
    while (1)
    {
        //tcp start
        fcntl(clientfd,F_SETFL,O_NONBLOCK);
        char data[BUFFER_SIZE] = {
            0,
        };
        ssize_t nbytes = recv(clientfd, (void *)buffer_tcp,sizeof(buffer_tcp), MSG_DONTWAIT); //blocking
  
       // printf("%d \n %d \n"),nbytes,sizeof(nbytes);
        memcpy(data, buffer_tcp,sizeof(buffer_tcp));
            send(clientfd, (void *)data,sizeof(data), MSG_DONTWAIT);
            printf("Tcp_recv data : %s\n", data);
            nbytes = 0;
            //tcp end
        char temp[BUFFER_SIZE] = {
            0,
        };
        //udp start
       
        len = recvfrom(clientfd1, buffer_udp, sizeof(buffer_udp), MSG_DONTWAIT, (struct sockaddr *)&clntAddr, &clntAddrLen);
        memcpy(temp, buffer_udp, sizeof(buffer_udp));
           printf("udp_send data :  %s \n",temp);
        sendto(clientfd1, temp, sizeof(temp), MSG_DONTWAIT, (struct sockaddr *)&clntAddr, sizeof(clntAddr));
        printf("udp_send data :  %s \n",temp);
        //udp endz

        //}
    }

    //tcp_end
    close(clientfd);
    close(serverfd);
    close(clientfd1);
    close(serverfd1);
    //udp connection

    return 0;
}