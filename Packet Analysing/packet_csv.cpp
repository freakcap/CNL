// You will need a csv dump from wireshark in the current directory


#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	string pro_ch,no,time,src,dest,protocol,len,info;
	int ch,i(0);
	int count;
	
	do{
	ifstream file("new.csv");
	cout<<"1.IP\n2.TCP\n3.UDP\n4.Ethernet\n5.exit\n";
	cin>>ch;

	switch(ch)
	{
		case 1 :
		pro_ch = "\"ICMPv6\"";
		break;
		case 2 :
		pro_ch = "\"TCP\"";
		break;
		case 3 :
		pro_ch = "\"UDP\"";
		break;
		case 4 :
		pro_ch = "\"ARP\"";
		break;
		default:
		pro_ch = "\"ARP\"";
		break;
	}

		count=-1;
		i=0;
		while(file.good())
		{
			getline(file,no,',');
			getline(file,time,',');
			getline(file,src,',');
			getline(file,dest,',');
			getline(file,protocol,',');
			getline(file,len,',');
			getline(file,info,'\n');


			if(protocol == pro_ch || protocol == "\"Protocol\"")
			{
				cout<<setw(4)<<left<<i++;
				cout<<setw(10)<<left<<string(time,1,time.length()-2);
				cout<<setw(30)<<left<<string(src,1,src.length()-2);
				cout<<setw(30)<<left<<string(dest,1,dest.length()-2);
				cout<<setw(10)<<left<<string(protocol,1,protocol.length()-2);
				cout<<setw(10)<<left<<string(len,1,len.length()-2);
				cout<<left<<string(info,1,info.length()-2);
				cout<<endl;
				count++;
			}
		}
		cout<<"\n Total count : "<<count<<endl;
		file.close();

}while(ch!=5);
}