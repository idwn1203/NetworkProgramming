#include "common.h"

extern void WaitingRoom();
char name[5];

	char a1[5];
	char b[5] = "a";
void login_menu()
{
	puts("1.Create Accout");
	puts("2.login");
}
void Creat_Accout() {}


void login()
{
	while (1)
	{
		system("clear");
		printf("Id : ");
		scanf("%s", name);
		getchar();
		printf("Password : ");
		scanf("%s", a1);
		if (strcmp(a1, b) == 0)
		{
			printf("Success\n");
			system("cls");
			WaitingRoom();
			break;
		}
		else
			printf("Try Again\n");
		getchar();
		getchar();
		login();
		break;
	}
}
void login_Display()
{

	puts("-------------------------------------------------");
	puts("Welcome to the  IIC!!");
	puts("-------------------------------------------------");
	login_menu();
	puts("-------------------------------------------------");
	puts("---------------");
	
}