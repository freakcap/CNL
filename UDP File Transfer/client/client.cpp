#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<unistd.h>
using namespace std;

int main()
{
	int sock = socket(AF_INET,SOCK_DGRAM,0);

	struct sockaddr_in server;

	server.sin_family = AF_INET;
	server.sin_port = htons(8003);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");


	socklen_t serlen = sizeof(server);
	//char buff[10000];
	//char msg[10];
	//recvfrom(sock,msg,10,0,(struct sockaddr*)&server,&serlen);
	//cout<<msg;

	// char msg[10]="HI SERVER";
	// sendto(sock,msg,10,0,(struct sockaddr*)&server,sizeof(server));

	
	char buff[10000];
	recvfrom(sock,buff,10000,0,(struct sockaddr*)&server,&serlen);

	fstream fout;
	fout.open(buff,ios::out|ios::binary);

	bzero((char*)buff,10000);

	int msgs = recvfrom(sock,buff,10000,0,(struct sockaddr*)&server,&serlen);

	fout.write(buff,1);

	fout.close();
	cout<<"File transmission successfull.";
	close(sock);
}