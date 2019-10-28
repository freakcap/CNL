#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int snd[11],parity[4],rec[11];

	cout<<"Enter the data to be sent seperated by spaces :";
	for(int i=10;i>=0;i--)
	{
		if(i==0 || i==1 || i==3 || i==7)
			continue;
		cin>>snd[i];
	}

	snd[0]=snd[2]^snd[4]^snd[6]^snd[8]^snd[10];
	snd[1]=snd[2]^snd[5]^snd[6]^snd[9]^snd[10];
	snd[3]=snd[4]^snd[5]^snd[6];
	snd[7]=snd[8]^snd[9]^snd[10];

	cout<<"Input Data : ";
	for(int i=10;i>=0;i--)
	{
		if(i==0 || i==1 || i==3 || i==7)
			continue;
		cout<<snd[i];
	}

	cout<<"\n Code actually sent : ";
	for(int i=10;i>=0;i--)
	{
		cout<<snd[i];
	}

	cout<<"\n Enter the received code seperated by spaces : ";
	for(int i=10;i>=0;i--)
	{
		if(i==0 || i==1 || i==3 || i==7)
			continue;
		cin>>rec[i];
	}

	parity[0]=rec[2]^rec[4]^rec[6]^rec[8]^rec[10];
	parity[1]=rec[2]^rec[5]^rec[6]^rec[9]^rec[10];
	parity[2]=rec[4]^rec[5]^rec[6];
	parity[3]=rec[8]^rec[9]^rec[10];

	cout<<"\nCode actually received : ";
	int c=0;
	for(int i=10;i>=0;i--)
	{
		if(i==0 || i==1 || i==3 || i==7)
		{
			cout<<parity[c];
			c++;
			continue;
		}
		cout<<rec[i];
	}


	if(parity[0]==0 && parity[1]==0 && parity[2]==0 && parity[3]==0)
	{
		cout<<"\nNo eroors found .";
	}
	else{
		cout<<"\n Error found.\n Position of error in binary: ";
		for(int i=3;i>=0;i--)
			cout<<parity[i];
		int pos=0;
		cout<<"\n Position of error in decimal: ";
		for(int i=0;i<4;i++)
		{
			pos=pos+parity[i]*(1<<i);
		}
		cout<<pos<<"\n";
	}
}