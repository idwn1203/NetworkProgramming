#include "common.h"

extern void WaitingRoom();
extern char name[5];
int a;

void Input(){
	printf("Input : ");
	scanf("%d",&a);
	getchar();
}

void Previous(){
	WaitingRoom();
}
void ChatRoom_Menu(){
	puts("-------------------------------------------------");
	puts("1.Input | 2.Previous");
	puts("-------------------------------------------------");
}
void Chat(){
	printf("name : %s \n",name);
}

void ChatRoom(){
	int s;
	puts("-------------------------------------------------");
	printf("Total : %d \nNow : %d \n",1,2);
	puts("-------------------------------------------------");
	Chat();
	puts("----------------------------------------------\n");
	ChatRoom_Menu();
	while(1){
		puts("Choose Menu : ");
		scanf("%d",&s);
		switch(s){
			case 1 :
				Input();
				system("clear");
				ChatRoom();
				break;
			case 2 :
				system("clear");
				Previous();
				break;
		}
	}
}

