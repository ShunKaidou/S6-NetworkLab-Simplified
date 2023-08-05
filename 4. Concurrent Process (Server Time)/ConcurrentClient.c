#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>
 

void main(int argc, char *argv[]){

	struct sockaddr_in server;
	bzero(&server, sizeof(server));
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_port = htons(atoi(argv[2]));
	
	int sd = socket(AF_INET,SOCK_DGRAM,0);
	 	
	char buffer[100];

	sendto(sd,"",1,0,(struct sockaddr*)&server,sizeof(server));

	recvfrom(sd,buffer,sizeof(buffer),0,NULL,NULL);
	
	printf("The current time of the system is %s\n",buffer);
	
	}
