#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
	int nf,ws,tr(0);
	srand(100);
	cout<<"Enter the no of frames ;";
	cin>>nf;
	cout<<"Enter the size of window :";
	cin>>ws;

	int i=1;

	while(i<=nf)
	{
		int inc=0;

		for(int j=i;j<i+ws && j<=nf;j++)
		{
			cout<<"Sent frame "<<j<<endl;
			tr++;
		}

		for(int j=i;j<i+ws && j<=nf;j++)
		{
			int flag = rand()%2;

			if(!flag)
			{
				cout<<"Ack rec for "<<j<<endl;
				tr++;
				inc++;
			}
			else{
				cout<<"Ack failed for "<<j<<endl;
				cout<<"Restransmitting the window"<<endl;
				break;
			}
		}
		i = i +inc;

	}

	cout<<"Total transmissions"<<tr;
}