#include "./headerFiles.h"

int main(int argc, char* argv[]) {	//three arguments to be checked later
	//declare and define
	int s;	//socket descriptor
	int n;	//num of bytes in each recv call
	char* servName;	//server name 
	int servPort;	//server port number
	char* string;	//string to be echoed
	int len;	//length of string to be echoed
	char buffer[1024];	//buffer
	char* ptr = buffer;	//ptr to move along the buffer
	int maxLen = sizeof(buffer);
	struct sockaddr_in servAddr;	//server socket address
	
	//check and set arguments
	if(argc != 4) {
		printf("Error: four arguments are needed!");
		exit(1);
	}
	servName = argv[1];
	servPort = atoi(argv[2]);
	string = argv[3];
	maxLen = sizeof(string);
	//create remote (server) socket address
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	inet_pton(AF_INET, servName, &servAddr.sin_addr);	//server IP address
	servAddr.sin_port = htons(servPort);
	
	//create socket
	if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Error: socket creation failed!");
		exit(1);
	}
	
	//connect to the server
	if(connect(s, (struct sockaddr*) &servAddr, sizeof(servAddr)) < 0) {
		perror("Error: connection failed!");
		exit(1);
	}
	
	//data transfer section
	send(s, string, strlen(string), 0);
	while((n = recv(s, ptr, maxLen, 0)) > 0) {
		ptr += n;	//move pointer along the buffer
		maxLen -= n;	//adjust the maximum num of bytes
		len += n;	//update the length of string received
	}//end of while loop
	
	//print and verify the echoed string
	buffer[len] = '\0';
	printf("Echoed string received: ");
	
	//close socket
	close(s);
	//stop programm
	exit(0);
}//end of echo client programm
