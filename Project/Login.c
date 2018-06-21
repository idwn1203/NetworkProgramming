#include "common.h"
extern void ChatRoom();

char name[5];
	char a1[5];
	char b[5] = "a";
void login_menu()
{
	// Later..
	// puts("1.Create Accout");
	// puts("2.Login");
	// puts("3.Delete Accout");
	puts("Login....");
}
void Login()
{
	while (1)
	{
		system("clear");
		Login_Display();
		printf("Id : ");
		scanf("%s", name);
		getchar();
		printf("Password : ");
		scanf("%s", a1);
		if (strcmp(a1, b) == 0)
		{
			printf("Success\n");
			system("clear");
			ChatRoom();
			break;
		}
		else
			printf("Try Again\n");
		getchar();
		getchar();
		Login();
		break;
	}
}
void Login_Display()
{
	puts("-------------------------------------------------");
	puts("Welcome to the  IIC!!");
	puts("-------------------------------------------------");
	login_menu();
	puts("-------------------------------------------------");
}