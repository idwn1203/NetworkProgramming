#include "headerFiles.h"
#include "common.h"
#include <unistd.h>
#include <fcntl.h>
#define HOST_PORT 50000
#define CLIENT_NUM 5
#define BUFFER_SIZE 256

int clientfd;
int clientfd1;
int serverfd;

void process_exit(int sig)
{
    close(clientfd);
    close(serverfd);
}

int main(int argc, char *argv[])
{
    signal(SIGKILL, process_exit);
    char data[BUFFER_SIZE] = {
        0,
    };
    char rcv[BUFFER_SIZE] = {
        0,
    };
    char *prcv = rcv;
    char *pdata = data;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    struct sockaddr_in clientAddr1;
    int fdSet;
    int clientNum[CLIENT_NUM];
    int index = 0;

    //tcp seatting
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(HOST_PORT);
    serverfd = socket(PF_INET, SOCK_STREAM, 0);

    //tcp Start
    if (clientfd < 0)
    {
        perror("Listen fail");
        exit(1);
    }

    if (bind(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("bind fail");
        close(serverfd);
        exit(1);
    }

    if (listen(serverfd, CLIENT_NUM) < 0)
    {
        perror("listen fail");
        close(serverfd);
        exit(1);
    }

    int clientSize = sizeof(clientAddr);
    int clientSize1 = sizeof(clientAddr1);
    //clientfd[0] = accept(serverfd, (struct sockaddr *)&clientAddr, (socklen_t *)&clientSize);

    /*
    if (clientfd < 0)
    {
        perror("accept fail");
        exit(1);
    }*/
     if(clientfd >0){
        clientfd1 = accept(serverfd,(struct sockaddr *)&clientAddr1, (socklen_t *)&clientSize1);
    }
      clientfd = accept(serverfd, (struct sockaddr *)&clientAddr, (socklen_t *)&clientSize);
            if (clientfd < 0)
            {
                perror("accept fail");
                exit(1);
            }

    while (1)
    {
        int check;
        check = recv(clientfd, prcv, sizeof(rcv), MSG_DONTWAIT); //blocking
        if (check > 0)
        {
            strcat(data, rcv);
            index += strlen(prcv);
            data[index] = '\n';
            index++;
            printf("sizeof %d strlen %d\n", sizeof(rcv), strlen(prcv));
            printf("%s\n", data);
            send(clientfd, data, sizeof(data), MSG_DONTWAIT);
        }
    }

    return 0;
}