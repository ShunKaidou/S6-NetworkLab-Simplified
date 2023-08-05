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
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_port = htons(atoi(argv[2]));

	int sd = socket(AF_INET, SOCK_STREAM, 0);
	
	connect(sd, (struct sockaddr *)&server, sizeof(server));
	
	char buffer[200];
	printf("Enter the string to be reversed: ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';
	
	write (sd,buffer, sizeof(buffer));
	read(sd,buffer, sizeof(buffer));
	
	printf("Reversed String: ");
	printf("%s\n", buffer);
	close(sd);
}
