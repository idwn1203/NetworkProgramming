#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define BUFFER_SIZE 256
#define HOST_PORT 50000
#define CLIENT_NUM 5


int clientfd;
int serverfd;

void process_exit(int sig){
    close(clientfd);
    close(serverfd);
}

int main(int argc, char* argv[]){

    signal(SIGKILL, process_exit);
   // printf("%d ", getpid());

    char buffer[BUFFER_SIZE];

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(HOST_PORT);
    
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if( clientfd < 0){
        perror("Listen fail");
        exit(1);
    }

    if( bind(serverfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        perror("bind fail");
        exit(1);
    }

    if( listen(serverfd, CLIENT_NUM) < 0 ){
        perror("listen fail");
        exit(1);
    }

    int clientSize = sizeof(clientAddr);
    clientfd = accept(serverfd, (struct sockaddr *)&clientAddr,(socklen_t*) &clientSize);
    if( clientfd < 0){
        perror("accept fail");
        exit(1);
    }

    // ssize_t nbytes = 0;
    int cursor = 0;
     while(1){
        char data[BUFFER_SIZE] = {0, };
        ssize_t nbytes = recv(clientfd, (void*)buffer, BUFFER_SIZE, 0);
        memcpy(data, buffer, nbytes);
        if( nbytes != 0){
            //data[nbytes+1] = '\0';
            printf("recv : %s\n",data);
            //data[nbytes+1] = '\0';
            //nbytes = 0;
            //data[nbytes];
            send(clientfd,(void*)data,BUFFER_SIZE,0);
            nbytes = 0;
        }
     }
    /*
     while(1){
        ssize_t nbytes = recv(clientfd, (void*)buffer, BUFFER_SIZE, 0);
        if( nbytes == 0){
            data[cursor] = '\0';
            // break;
            puts(data);
            cursor = 0;
        }
        else {
            memcpy(data+cursor, buffer, nbytes);
            cursor = nbytes;
        }
        // memcpy(data, buffer, nbytes);
        // data[nbytes] = '\0';
        // puts(data);

     }*/
    //puts(data);
    // printf("%d ", clientfd);

    close(clientfd);
    close(serverfd);

    return 0;
}