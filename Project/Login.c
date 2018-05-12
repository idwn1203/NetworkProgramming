#include "common.h"

extern void WaitingRoom();
char name[5];


void login(){
	char a1[5];
	char b[5] = "abcd";
	puts("-------------------------------------------------");
	puts("Welcome to the  IIC!!");
	puts("-------------------------------------------------");

	while(1){
		system("clear");
		printf("Id : ");
		scanf("%s",name);
		getchar();
		printf("Password : ");
		scanf("%s",a1);
		if(strcmp(a1,b)==0){
			printf("Success\n");
			system("cls");
			WaitingRoom();
			break;
		}
		else
			printf("Try Again\n");
			getchar();
			getchar();
			system("cls");
			login();
		break;
	}
	puts("---------------");
}