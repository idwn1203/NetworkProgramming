#include "common.h"
#include "headerFiles.h"

#define BUFFER_SIZE 256
extern void Login();
int serverfd;

int Connection() {
	char hostName[256];
	char *ph_Name=hostName;
	char h_Port[256];
	char *phPort=h_Port;
    int hostPort;
    char hP;
	char buffer[BUFFER_SIZE];
	char test;

    struct sockaddr_in serverAddr;
	printf("IP Input :");
	scanf("%s",ph_Name);

	printf("Port Input :");
	scanf("%s",phPort);
    hostPort = atoi(phPort);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET,ph_Name, &serverAddr.sin_addr);
    serverAddr.sin_port = htons(hostPort);
    serverfd = socket(PF_INET, SOCK_STREAM, 0);

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

	puts("-------------------------------------------------");
	puts("Welcome");
    puts("Press Enter");
	getchar();
	getchar();
	system("clear");
	Login();
}

void First_Display()
{
    system("clear");
	puts("-------------------------------------------------");
	puts("This is SNS for IIC!!");
	puts("-------------------------------------------------");
	puts("Please Enter the IP Addrress and IP Port");
	puts("-------------------------------------------------");	
}