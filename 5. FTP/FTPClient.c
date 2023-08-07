#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

void send_file(int sd){
	
	FILE *fp;
	fp = fopen("send.txt","r");
	
	char buffer[1024]={0};
	 
	while(fgets(buffer,1024,fp)!=NULL){
	
		send(sd,buffer,sizeof(buffer),0);
		
		bzero(buffer,1024);
	
	}}
 
int main( int argc, char *argv[]){

	struct sockaddr_in server;
	bzero(&server, sizeof(server));
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_port = htons(atoi(argv[2]));

	int sd = socket(AF_INET,SOCK_STREAM,0);
	connect(sd,(struct sockaddr*)&server,sizeof(server));
	send_file(sd);
	close(sd);
	
return 0;}


