#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nf,ws;
	srand(100);
	cout<<"Enter the no of frames :";
	cin>>nf;
	cout<<"Enter the window size :";
	cin>>ws;
	int drop_pack[nf+1];
	int ack_rec =0;
	int last_pack =0;
	int last_pack_ack = last_pack;
	int insertHere = 1;
	int i=1;

	for(int i=0;i<=nf+1;i++)
	{
		drop_pack[i]=MAX_INPUT;
	}

	while(ack_rec < nf)
	{

		for(int i=1;i<=ws && ack_rec<nf;i++)
		{
			if(drop_pack[i]!=MAX_INPUT)
			{
				cout<<"Sent frame "<<drop_pack[i]<<endl;
			}
			else{
				if(last_pack==nf)
					continue;
				cout<<"Sent frame "<<last_pack+1<<endl;
				last_pack++;
			}
		}


		for(int i=1;i<=ws && ack_rec<nf;i++)
		{
			int flag = rand()%2;
			if(!flag)
			{
				if(drop_pack[i]!=MAX_INPUT)
			{
				cout<<"Ack rec for frame "<<drop_pack[i]<<endl;
				drop_pack[i]=MAX_INPUT;
			}
			else{
				if(last_pack_ack==nf)
					continue;
				cout<<"Ack rec for frame "<<last_pack_ack+1<<endl;
				last_pack_ack++;
			}
			ack_rec++;
			}
			else{
				if(drop_pack[i]!=MAX_INPUT)
			{
				cout<<"Ack failed for frame "<<drop_pack[i]<<endl;
			}
			else{
				if(last_pack_ack==nf)
					continue;
				cout<<"Ack failed for frame "<<last_pack_ack+1<<endl;
				drop_pack[insertHere]=last_pack_ack+1;
				last_pack_ack++;
				insertHere++;
			}
			}
		}

		sort(drop_pack+1,drop_pack+nf+1);
		for(int i=1;i<=nf+1;i++)
		{
			if(drop_pack[i]==MAX_INPUT)
			{
				insertHere=i;
				break;
			}
		}

	}
}