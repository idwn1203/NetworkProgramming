#include "common.h"

extern void ChatRoom();
extern void login();
extern char name[5];

void Enter_ChatRoom() {
	ChatRoom();
}

void Create_ChatRoom(){
	printf("Create_ChatRoom\n");
	getchar();
}

void Delete_ChatRoom(){
	printf("Delete_ChatRoom\n");
	getchar();
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
		system("cls");
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

