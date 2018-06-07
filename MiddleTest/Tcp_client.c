#include "headerFiles.h"

#define BUFFER_SIZE 256
int serverfd;

void process_exit(int sig)
{

    close(serverfd);
}

int main(int argc, char *argv[])
{
    signal(SIGKILL, process_exit);

    char *hostName;
    int hostPort;
    char buffer[BUFFER_SIZE];

    struct sockaddr_in serverAddr;

    //filename hostIP hostPort data
    if (argc < 3)
    {
        puts("Usage: hostIP hostPort data");
        exit(1);
    }

    hostName = argv[1];
    hostPort = atoi(argv[2]);
    //strcpy(buffer, argv[3]);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, hostName, &serverAddr.sin_addr);
    serverAddr.sin_port = htons(hostPort);

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        perror("fail to create socket");
        exit(1);
    }

    if (connect(serverfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("fail to connect");
        exit(1);
    }
    puts("Tcp_Connection Success");

    while (1)
    {
        printf("input : ");
        scanf("%s", buffer);
        send(serverfd, (void *)buffer, strlen(buffer),0);
        char temp[BUFFER_SIZE] = {
            0,
        };
        memcpy(temp, buffer, sizeof(buffer));
        recv(temp, (void*)temp,sizeof(temp), MSG_DONTWAIT);
        //buffer[nbytes];
        printf("recv : %s \n", temp);
        //nbytes=0;
    }

    close(serverfd);
    return 0;
}