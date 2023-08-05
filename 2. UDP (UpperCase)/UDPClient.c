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
	
	char sendline[1024], recvline[1024];
	
	printf("Enter a string: ");
	fgets(sendline, 1024, stdin);

	sendto(sd, sendline, strlen(sendline) + 1, 0, (struct sockaddr*) &server,sizeof(server));
	
	int n = recvfrom(sd, recvline, 1024, 0, NULL, NULL);
	recvline[n] = '\0';
	
	printf("Converted string: %s\n", recvline);
	close(sd);
}
