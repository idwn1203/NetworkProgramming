#include "headerFiles.h"
int main(int argc, char **argv){
	int ls1;
	int s1;
	char buffer[256];
	char* ptr =buffer;
	int len =0;
	int waitSize =5;  //16
	int n = 0;
	int maxLen = 256;
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	int clntAddrlen;

	memset(&servAddr,0,sizeof(servAddr));
	servAddr.sin_family =AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = htons(50000);
	ls1 = socket(AF_INET,SOCK_STREAM,0);


	if(ls1<0){
		perror("Listen fail");
		exit(1);
	}
	if(bind(ls1,(struct sockaddr*)&servAddr,sizeof(servAddr))<0){
		perror("binding fail");
		exit(1);
	}
	if(listen(ls1,waitSize)<0){
		perror("listening fail");
		exit(1);
	}
	clntAddrlen = sizeof(clntAddr);
	printf("test1 %d \n", ls1);
         
//        s1 = accept(ls1, (struct sockaddr *) &clntAddr, (socklen_t *) &clntAddrlen);


	while(1){
                s1 = accept(ls1,(struct sockaddr *)&clntAddr,(socklen_t *) &clntAddrlen);
                printf("test2 %d \n",s1);
		if(s1 <0){
			perror("Error:: accepting failed");
			exit(1);
		}

		while((n=recv(s1,ptr,maxLen,0))>0){		
			ptr += n;
			maxLen -=n;
			len += n;
		}

                printf("recv = %s \n", buffer);
                buffer[len] = 0;
                printf("recv = %s \n", buffer);
		send(s1,buffer,len,0);
		close(s1);
	}

} 


