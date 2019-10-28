#include<iostream>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<netdb.h>
#include<fstream>
using namespace std;

int main()
{
	int sock = socket(AF_INET,SOCK_DGRAM,0);

	struct sockaddr_in server,client;

	server.sin_family = AF_INET;
	server.sin_port = htons(8003);
	server.sin_addr.s_addr = INADDR_ANY;
	if(bind(sock,(struct sockaddr*)&server,sizeof(server)))
	{
		cout<<"FAIL";
	}
	socklen_t clilen = sizeof(client);

	// char msg[10];
	// //msg = "HI SERVER";
	// recvfrom(sock,msg,10,0,(struct sockaddr*)&client,&clilen);
	// cout<<msg;


	char fname[10000];
	cout<<"Enter the file name : ";
	cin>>fname;

	sendto(sock,fname,10000,0,(struct sockaddr*)&client,sizeof(client));

	fstream fin;
	fin.open(fname,ios::in|ios::out|ios::binary);
	fin.seekg(0,ios::end);
	int ss = fin.tellg();
	fin.seekg(0,ios::beg);
	char buff[10000];
	fin.read(buff,ss);

	sendto(sock,buff,ss,0,(struct sockaddr*)&client,sizeof(client));

	cout<<"\nFile transmission done.";
	fin.close();
	close(sock);
}