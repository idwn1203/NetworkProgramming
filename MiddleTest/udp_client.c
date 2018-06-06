#include "headerFiles.h"
#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
        int hostPort;
        int Datalen;
        char *hostName;
        char buffer[BUFFER_SIZE];
        struct sockaddr_in servAddr;
        /*
        if(argc !=4){
                printf ("Error: three arguments are needed!");
                exit(1);
        }*/

        hostName = argv[1];
        hostPort = atoi(argv[2]);

        printf(" servname = %s, serport = %d, input = %s \n", hostName, hostPort, buffer);

        memset(&servAddr, 0, sizeof(servAddr));
        servAddr.sin_family = AF_INET;
        inet_pton(AF_INET, hostName, &servAddr.sin_addr);
        servAddr.sin_port = htons(hostPort);

        if ((hostPort = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
        {
                perror("Error:Socket failed!");
                exit(1);
        }
        puts("Udp_Connection Success");

        while (1)
        {
                char temp[BUFFER_SIZE] = {
                    0,
                };
                printf("Input : ");
                scanf("%s", buffer);
                sendto(hostPort, buffer, sizeof(buffer),MSG_DONTWAIT, (struct sockaddr *)&servAddr, sizeof(servAddr));
                printf("buffer :%s \n", buffer);
                printf("before recvfrom\n");

                recvfrom(hostPort, buffer, sizeof(buffer), MSG_DONTWAIT, NULL, NULL);
                printf("after recvfrom\n");

                memcpy(temp, buffer, sizeof(buffer));
                printf("temp : %s \n", temp);
                //buffer[len] = '\0';
                printf("recv string : %s \n", buffer);
                //fputs(buffer,stdout);
        }

        close(hostPort);
        exit(0);
}
