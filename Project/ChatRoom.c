#include "common.h"
#include "headerFiles.h"
extern void WaitingRoom();
extern char name[5];
extern int serverfd;
int a;

char buffer[256];
void Input()
{

		puts("-------------------------------------------------");
	puts("input : ");
	scanf("%s", buffer);
	if (buffer == "q")
	{
		WaitingRoom();
	}
	send(serverfd, (void *)buffer, strlen(buffer), 0);
	getchar();
}
void text()
{
	char temp[256] = {
		0,
	};
	memcpy(temp, buffer, sizeof(buffer));
	recv(temp, (void *)temp, sizeof(temp), MSG_DONTWAIT);
	//buffer[nbytes];
	printf("recv : %s \n", temp);
	//getchar();
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
		printf("Total : %d \nNow : %d \n", 1, 2);
		puts("-------------------------------------------------");
		User_Name();
		puts("-------------------------------------------------");
		text();
		Input();
		system("clear");
	}
}
