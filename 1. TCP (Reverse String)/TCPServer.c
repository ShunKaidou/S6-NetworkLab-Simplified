#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>

int main( int argc, char *argv[]){

	struct sockaddr_in server;
	bzero(&server, sizeof(server));
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(atoi(argv[1]));
	
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	
	bind(sd, (struct sockaddr*)&server, sizeof(server));
	
	listen(sd,5);
	
	int accepted = accept(sd , NULL, NULL);
	
	int i, temp;
	char buffer[100];
	
	read(accepted,buffer, sizeof(buffer));
	int len = strlen(buffer);
	
	for( i =0; i<= len/2; i++){
		temp = buffer[i];
		buffer[i] = buffer[len - 1-i];
		buffer[len-1-i] = temp;}
		
	write (accepted, buffer, sizeof(buffer));
	close(accepted);
	close(sd);}
