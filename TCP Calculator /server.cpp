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

	struct sockaddr_in server,client;

	server.sin_family= AF_INET;
	server.sin_port=htons(8003);
	server.sin_addr.s_addr=INADDR_ANY;

	if(bind(sock,(struct sockaddr*)&server,sizeof(server)))
	{
		cout<<"TERROR";
	}
	if(listen(sock,5)<0)
	{
		cout<<"TERROR";
	}
	socklen_t clilen = sizeof(client);
	int newsock = accept(sock,(struct sockaddr*)&client,&clilen);

	float ans1,a,b;
	char n1[20],n2[20],op[20],flg[20];

	while(1)
	{
		recv(newsock,n1,20,0);
		a=atof(n1);
		recv(newsock,n2,20,0);
		b=atof(n2);
		recv(newsock,op,20,0);
		
		cout<<"First : "<<a<<" Second: "<<b<<" Operation : "<<op[0]<<endl;

		bzero((char*)n1,sizeof(n1));
		bzero((char*)n2,sizeof(n2));

		switch(op[0])
		{
			case '+':
			{
				char ans[20];
				ans1=a+b;
				sprintf(ans,"%f",ans1);
				send(newsock,ans,20,0);
				bzero((char*)ans,sizeof(ans));
				break;
			}
			case '-':
			{
				char ans[20];
				ans1=a-b;
				sprintf(ans,"%f",ans1);
				send(newsock,ans,20,0);
				bzero((char*)ans,sizeof(ans));
				break;

			}
		}

		recv(newsock,flg,20,0);
		if(flg[0]=='0')
			break;
		
	}

	close(sock);

}