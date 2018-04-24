#include "headerFiles.h"
int main (void){
	int s;
	int len;
	char buffer[256];
	struct sockaddr_in servAddr;
	struct sockaddr_in clntAddr;
	int clntAddrLen;


	memset(&servAddr,0,sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port =htons(50000);
	servAddr.sin_addr.s_addr =htonl(INADDR_ANY);

if((s=socket(AF_INET,SOCK_DGRAM,0))<0)
{
	perror("ERROR:SOCKET FAILED!");
	exit(1);
	}
printf(" before binf socket +%d \n",s);
if(bind(s,(struct sockaddr*)&servAddr,sizeof(servAddr))<0)
{
	perror("Error:bind failed!");
	exit(1);
}
printf(" after binf \n");
for( ; ; )
{

len =recvfrom(s,buffer,sizeof(buffer),0,(struct sockaddr*)&clntAddr,&clntAddrLen);
printf(" server : receive aftr recv %s \n", buffer);

sendto(s,&buffer[0],len,0,(struct sockaddr*)&clntAddr,sizeof(clntAddr));
printf(" server : receive afet send %s \n", buffer);

}

}
