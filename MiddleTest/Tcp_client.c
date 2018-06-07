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
        printf("after send\n");

        char temp[BUFFER_SIZE] = {
            0,
        };
        printf("before recv\n");

        ssize_t nbytes = recv(serverfd, (void *)buffer,sizeof(buffer), MSG_DONTWAIT);
        printf("after recv\n");
        memcpy(temp, buffer, sizeof(buffer));

        //buffer[nbytes];
        printf("recsdfv : %s \n", temp);
        //nbytes=0;
    }

    close(serverfd);
    return 0;
}