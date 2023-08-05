#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>
 
void write_file(int accepted){
	FILE *fp;
	fp = fopen("recv.txt","w");
	char buffer[1024];
	 
	while(1){
		int n = recv(accepted,buffer,1024,0);
		if (n <= 0) {
        		break;}
 
		fprintf(fp,"%s",buffer);
		bzero(buffer,1024);
		}}
		
int main( int argc, char *argv[]){

	struct sockaddr_in server;
	bzero(&server, sizeof(server));
	
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port = htons(atoi(argv[1]));
	
	int sd = socket(AF_INET,SOCK_STREAM,0);
	bind(sd, (struct sockaddr*)&server, sizeof(server));
	listen(sd,5);
	int accepted = accept(sd,NULL,NULL);
	
	write_file(accepted);
	printf("Success.\n");

	return 0;}
	
	
