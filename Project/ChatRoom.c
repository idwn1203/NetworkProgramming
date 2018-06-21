#include "common.h"
#include "headerFiles.h"
extern void WaitingRoom();
extern char name[5];
extern int serverfd;

char output[256];
char *pOut = output;
char buffer[256];
char *pname = name;

void Input()
{
	char input[256]={0,};
	puts("-------------------------------------------------");
	printf("input : ");
	scanf("%s", buffer);
	if (!strcmp(input, "exit"))
	{
		return 0;
	}
	strcat(input, name);
	input[strlen(pname)] = ':';
	strcat(input, buffer);
	send(serverfd, input, sizeof(input), 0);
	buffer[0] = '\0';
}
void Output()
{
	int check;
	if(check>0){
	recv(serverfd, pOut, sizeof(output), MSG_DONTWAIT);
	output[strlen(pOut)]='\0';
	printf("%s\n",output);
	}
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
		Output();
		Input();
		system("clear");
	}
}
