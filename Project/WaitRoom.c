#include "common.h"
#include "headerFiles.h"

#define BUFFER_SIZE 256
int serverfd;

extern void ChatRoom();
extern void login();
extern char name[5];
int serverfd;

int Enter_ChatRoom() {
	char hostName[256];
	char *ph_Name=hostName;
    int hostPort;
    char hP;
	char buffer[BUFFER_SIZE];
	char test;

    struct sockaddr_in serverAddr;
	printf("IP Input :");
	//scanf("%s",hP);
	//hostPort=atoi(hP);
	//puts("Port Input :");
	scanf("%s",ph_Name);

    //hostName = test;
    //hostPort = atoi(*hostName);
   
    //strcpy(buffer, argv[3]);

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET,ph_Name, &serverAddr.sin_addr);
    serverAddr.sin_port = htons(50000);

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
	puts("Welcome");
	getchar();
	getchar();
	system("clear");
	ChatRoom();
}

void Create_ChatRoom(){
	printf("Create_ChatRoom\n");
	getchar();
}

void Delete_ChatRoom(){
	printf("Delete_ChatRoom\n");
	close (serverfd);
	getchar();
	system("clear");
	WaitingRoom_menu();
}

void logout(){
	puts("log out!");
	login();
}

void WaitingRoom_menu(){
	printf("%s		:	Public \n","iic");
	printf("%s		:	Private \n","iic_1");
	puts("-------------------------------------------------");
	printf("1.Enter Chatroom | 2.Create Chatroom | 3.Delete Chatroom | 4.logout\n");
	puts("-------------------------------------------------");
}

void WaitingRoom(){
	int s;
	puts("-------------------------------------------------");
	printf("WaitingRoom\n");
	puts("-------------------------------------------------");
	printf("UserID :%s \n",name);
	puts("-------------------------------------------------");
	WaitingRoom_menu();
	
	while(1){
		puts("Choose Menu : ");
		scanf("%d",&s);
		system("clear");
		switch(s){
			case 1:
				Enter_ChatRoom();
				break;
			case 2:
				Create_ChatRoom();
				WaitingRoom();
				break;
			case 3:
				WaitingRoom();
				Delete_ChatRoom();
				break;
			case 4:
				logout();
				break;
		}
	}
}

void Exit(){
	int s;
	puts("What to do ?");
	scanf("%d",&s);

	while(1){
		switch(s){
		case 1 :
			break;
		case 2:
			break;
		}	
	}
	printf("1.Previous");
	printf("2.Exit");
}

