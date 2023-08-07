#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>



int main(int argc, char* argv[]){

	struct sockaddr_in server;
	bzero(&server, sizeof(server));
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_port = htons(atoi(argv[2]));


	int sd = socket(AF_INET, SOCK_DGRAM, 0);
	
	char buffer[100];
	
	printf("Enter a string: ");
	fgets(buffer, sizeof(buffer), stdin);

	sendto(sd, buffer, strlen(buffer), 0, (struct sockaddr*) &server,sizeof(server));
	
	int n = recvfrom(sd, buffer, strlen(buffer), 0, NULL, NULL);
	buffer[n] = '\0';
	
	printf("Converted string: %s\n", buffer);
	close(sd);
}
