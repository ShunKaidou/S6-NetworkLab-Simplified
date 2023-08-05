#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char *argv[]){

	struct sockaddr_in server, client;
	bzero(&server, sizeof(server));
	bzero(&client, sizeof(client));
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(atoi(argv[1]));
	
	int clilen = sizeof(client);


	int sd = socket(AF_INET, SOCK_DGRAM, 0);

	bind(sd, (struct sockaddr*)&server, sizeof(server));	

	char buffer[1024];
	
	int n = recvfrom(sd, buffer, 1024, 0, (struct sockaddr*) &client, &clilen); //0 IS FLAG //CLIADDR SET

	
	for (int i = 0; i < n; i++) {
		buffer[i] = toupper(buffer[i]);}
	
	sendto(sd, buffer, n, 0, (struct sockaddr*) &client, clilen);
	
	close(sd);
	
return 0;}
