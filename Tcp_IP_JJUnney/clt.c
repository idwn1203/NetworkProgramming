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

	memset(&servAddr,0,sizeof(servAddr));
	servAddr.sin_family =AF_INET;	
	inet_pton(AF_INET,servName,&servAddr.sin_addr);
	servAddr.sin_port = htons(50000);
	s = socket(AF_INET,SOCK_STREAM,0);


//create socket
	if(s<0){
		perror("Error socet craetion fail");
		exit(1);
	}
//connect to the server

	if(connect(s,(struct sockaddr *)&servAddr,sizeof(servAddr))<0){
		perror("connection fail");
		exit(1);
	}
//Data send
	send(s,string,strlen(string),0);

	printf("test5 soc =%d string=%s n=%d \n",s,string,n);

	while((n =recv(s,ptr,maxLen,0))>0){
	printf("tes1t3\n");
		ptr +=n;
		maxLen -=n;
		len +=n;
	}

	printf("test2\n");

	printf("echo received : %s \n",buffer);
	buffer[len] ='\0';
	printf("echo received : %s \n",buffer);
	fputs(buffer,stdout);
	close(s);
	exit(0);
}

