#include "headerFiles.h"

int main(int argc,char* argv[]){
	int s;
	int n;
	char* servName;
	int servPort;
	char *string;
	int len;
	int maxLen;
	char buffer[256+1];
	char *ptr =buffer;
	struct sockaddr_in servAddr;

	if(argc !=4){
		printf("need arge");
		exit(1);
	}

	servName = argv[1];
	servPort = atoi(argv[2]);
	string =argv[3];
	printf("test\n");
	memset(&servAddr,0,sizeof(servAddr));

	printf("test\n");
	inet_pton(AF_INET,servName,&servAddr.sin_addr);

	printf("test\n");
	servAddr.sin_port = htons(50000);
	if((s=socket(PF_INET,SOCK_STREAM,0))<0){
		perror("Error socet craetion fail");
		exit(1);
	}

	printf("test\n");
	if(connect(s,(struct sockaddr *)&servAddr,sizeof(servAddr))<0){
		perror("connection fail");
		exit(1);
	}

	printf("test3\n");
	send(s,string,strlen(string),0);

	printf("test %d \n",s);

	while((n =recv(s,ptr,maxLen,0))>0){
	printf("tes1t3\n");
		ptr +=n;
		maxLen -=n;
		len +=n;
	}

	printf("test2\n");
	buffer[len] ='\0';
	printf("echo received");
	fputs(buffer,stdout);
	close(s);
	exit(0);
}

