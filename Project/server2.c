//server2.c

#include "headerFiles.h"
#include "common.h"
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include "queue.h"
#define HOST_PORT 50000
#define CLIENT_NUM 10
#define BUFFER_SIZE 256

enum Protocol{ LOGIN = 0, MESSAGE};

int listenfd;

void* recvMain(void *arg);

void process_exit(int sig)
{
    shutdown(listenfd, SHUT_RDWR);
    
}
    char data[BUFFER_SIZE] = {
        0,
    };
int main(int argc, char *argv[])
{
    signal(SIGKILL, process_exit);
    char *pdata = data;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    int index = 0;

    //tcp seatting
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(HOST_PORT);
    listenfd = socket(PF_INET, SOCK_STREAM, 0);

    //tcp Start
    if (listenfd < 0)
    {
        perror("socket create fail");
        exit(1);
    }

    if (bind(listenfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("bind fail");
        close(listenfd);
        exit(1);
    }

    if (listen(listenfd, CLIENT_NUM) < 0)
    {
        perror("listen fail");
        close(listenfd);
        exit(1);
    }

    int clientfd;
    int clientSize = sizeof(clientAddr);
 

    while(1){
        clientfd = accept(listenfd, (struct sockaddr *)&clientAddr, (socklen_t *)&clientSize);
        if(clientfd > 0){
            pthread_t threadID;
            pthread_create(&threadID, NULL, &recvMain, (void*)clientfd);
        }

    }

    return 0;
}

void* recvMain(void* arg){
    int n;
    char buffer[256];
    char *p =buffer;
    int clientfd = (int)arg;
    //while(1){
    //     n = recv(clientfd, buffer, 256, 0);
    //     enum Protocol protocol = buffer[0];
    //     switch(protocol){
    //         case LOGIN:

    //             break;
    //         case MESSAGE:

    //             break;
    //     }

    //     send(clientfd, buffer, 256, MSG_DONTWAIT);
    //}
       int check;
       int index=0;
       while(1){
        check = recv(clientfd, p, sizeof(buffer), MSG_DONTWAIT); //blocking
        if (check > 0)
        {
            strcat(data, buffer);
            index += strlen(p);
            data[index] = '\n';
            index++;
           // printf("sizeof %d strlen %d\n", sizeof(data), strlen(prcv));
            printf("%s", data);
            send(clientfd, data, 256, MSG_DONTWAIT);
        }
        }
}