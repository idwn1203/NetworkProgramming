#include "common.h"
#include "headerFiles.h"
extern void WaitingRoom();
extern char name[5];
extern int serverfd;
int a;

char buffer[256][256];
void Input()
{

	puts("-------------------------------------------------");
	puts("input : ");
	scanf("%s", buffer);
	if (!strcmp(buffer,"exit"))
	{

		system("clear");
		WaitingRoom();
	}
	send(serverfd, (void *)buffer, strlen(buffer), 0);
	getchar();
}
void text()
{
	char temp[256][256] = {
		0,
	};
	recv(temp, (void *)temp, sizeof(temp), MSG_DONTWAIT);
	memcpy(temp, buffer, sizeof(buffer));
	//buffer[nbytes];
	printf("%s : %s \n",name, temp);
	
	//getchar();

	/*
	char temp[256][256] = {
		0,
	};
	for(i=0;i<index;i++){
	recv(temp, (void *)temp, sizeof(temp), MSG_DONTWAIT);
	memcpy(temp, buffer, sizeof(buffer));
	//buffer[nbytes];
	}
	for(i=0;i<index;i++){
		printf("recv : %s \n", temp);
	}
	//getchar();
*/
}

void User_Name()
{
	printf("name : %s \n", name);
}

void ChatRoom()
{
	while (1)
	{
		int s;
		puts("-------------------------------------------------");
		puts("If you wann go out chattingRoom press exit");
		puts("-------------------------------------------------");
		printf("Total : %d \nNow : %d \n", 1, 2);
		puts("-------------------------------------------------");
		User_Name();
		puts("-------------------------------------------------");
		text();
		Input();
		system("clear");
	}
}
