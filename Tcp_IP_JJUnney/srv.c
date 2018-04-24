#include "headerFiles.h"
int main(){
	int ls;
	int s;
	char buffer[256];
	char* ptr =buffer;
	int len =0;
	int waitSize =16;
	int n = 0;
	int maxLen = sizeof(buffer);
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	int clntAddrLen;

	memset(&servAddr,0,sizeof(servAddr));
	servAddr.sin_family =AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(50000);

	if((ls =socket(PF_INET,SOCK_STREAM,0))<0){
		perror("Listen fail");
		exit(1);
	}
	if(bind(ls,(struct sockaddr*)&servAddr,sizeof(servAddr))<0){
		perror("binding fail");
		exit(1);
	}
	if(listen(ls,waitSize)<0){
		perror("listening fail");
		exit(1);
	}
	while(1){
		if(s=accept(ls,(struct sockaddr *)&clntAddr,&clntAddrLen)<0){
			perror("Error:: accepting failed");
			exit(1);
		}
		while((n=recv(s,ptr,maxLen,0))>0){
			ptr += n;
			maxLen -=n;
			len += n;
		}
		send(s,buffer,len,0);
		close(s);
	}
} 

