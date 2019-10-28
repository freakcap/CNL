#include<iostream>
#include<sys/socket.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
using namespace std;

int main()
{
	int sock = socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in server;

	server.sin_family= AF_INET;
	server.sin_port=htons(8003);
	server.sin_addr.s_addr=inet_addr("127.0.0.1");

	connect(sock,(struct sockaddr*)&server,sizeof(server));

	char n1[20],n2[20],op[20],flg[20],ans[20];

	while(1)
	{
		cout<<"Enter the first no. : ";
		cin>>n1;
		cout<<"Enter the second no. : ";
		cin>>n2;
		cout<<"Enter the operator no. : ";
		cin>>op;

		send(sock,n1,20,0);
		send(sock,n2,20,0);
		send(sock,op,20,0);

		bzero((char*)n1,sizeof(n1));
		bzero((char*)n2,sizeof(n1));
		bzero((char*)op,sizeof(n1));
		bzero((char*)ans,sizeof(ans));

		recv(sock,ans,20,0);
		cout<<" The Result is "<<atof(ans)<<endl;

		cout<<"Continue ? : ";
		cin>>flg;
		send(sock,flg,20,0);
		if(flg[0]=='0')
			break;
		
	}

	close(sock);

}