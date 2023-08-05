#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<time.h>
 
void main(int argc,char *argv[]){

	struct sockaddr_in server,client;
	bzero(&server, sizeof(server));
	bzero(&client, sizeof(client));
	
	int clilen = sizeof(client);

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port=htons(atoi(argv[1]));
	
	int sd = socket(AF_INET,SOCK_DGRAM,0);
	
	bind(sd,(struct sockaddr*)&server,sizeof(server));
	
	char buffer[100];
	time_t curtime;
 
	while(1){
		int n = recvfrom(sd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,&clilen);
	 
		int childpid = fork();	
		if(childpid==0){
			time(&curtime);
			
			sprintf(buffer,"= %s",ctime(&curtime));
			n=sendto(sd,buffer,sizeof(buffer),0,(struct sockaddr*)&client,clilen); 
			exit(1);}
		}}
		
		
			
	
	
	
	
