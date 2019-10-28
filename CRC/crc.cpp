#include<iostream>
using namespace std;

int main()
{
	int  fs,gs,rs,j,k;
	int f[20]={0};
	int g[20]={0};
	int ff[20]={0};
	int temp[20]={0};
	int rec[20]={0};
	int temp1[20]={0};
	int flag=0;
	char cc;
	cout<<"Enter the character in ASCII:";
	cin>>cc;

	fs = (int) cc;

	cout<<"The ascii code of entered character is "<<fs;
	
	int i=0;
	while(fs!=0)
	{
		ff[i]=fs%2;
		fs=fs/2;
		i++;
	}	
	fs = i;
	int k1=0;
	cout<<"\nThe binary of ascii is : ";
	for(int j=i-1;j>=0;j--)
	{
		f[k1]=ff[j];
		
		cout<<f[k1];
		temp[k1]=f[k1];
		k1++;
	}
	// cout<<"\n Enter the received code : ";
	// for(int i=0;i<fs;i++)
	// {
	// 	cin>>f[i];
	// 	temp[i]=f[i];
	// }

	cout<<"\nEnter the size of generator: ";
	cin>>gs;

	cout<<"Enter the generator :";
	for(int i=0;i<gs;i++)
	{
		cin>>g[i];
	}

	rs = gs -1;

	cout<<"Frame to be transmitted : ";
	for(int i=0;i<fs;i++)
		cout<<f[i];
	cout<<"\n Generator used : ";
	for(int i=0;i<gs;i++)
			cout<<g[i];


	for(int i=0;i<fs;i++)
	{
		j=0;
		k=i;
		if(temp[k]>=g[j])
		{
			for(j=0,k=i;j<gs;j++,k++)
			{
				temp[k]=temp[k]^g[j];
			}
		}
	}

	cout<<"\n CRC bits : ";
	for(int i=fs;i<fs+rs;i++)
	{
		f[i]=temp[i];
		cout<<f[i];
	}


	cout<<"\n Code actually sent : ";
	for(int i=0;i<fs+rs;i++)
		cout<<f[i];

	cout<<"\n Enter the receieved code : ";
	for(int i=0;i<fs+rs;i++)
	{
		cin>>rec[i];
		temp1[i]=rec[i];
	}


	for(int i=0;i<fs;i++)
	{
		j=0;
		k=i;
		if(temp1[k]>=g[j])
		{
			for(j=0,k=i;j<gs;j++,k++)
			{
				temp1[k]=temp1[k]^g[j];
			}
		}
	}

	cout<<"Remainder : ";
	for(int i=fs;i<fs+rs;i++)
	{
		cout<<temp1[i];
		if(temp1[i]!=0)
			flag=1;
	}

	if(flag==0)
	{
		cout<<"\n\n As the remainder is zero, there are no errors in the transmission.";
	}
	else{
		cout<<"\n\n As the remainder is not zero, there are errors in the transmission.";
	}

	return 0;
}