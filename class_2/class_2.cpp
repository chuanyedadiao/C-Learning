#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{
	fstream file;
	int buffer[10]={0,1,2,3,4,5,6,7,8,9}; 
	file.open("a1.txt",ios::out|ios::binary);
	file.write((char*)buffer,sizeof(buffer));
	file.close();//–¥»Î 
	file.open("a1.txt",ios::in|ios::binary);
	file.read((char*)buffer,sizeof(buffer));
	for(int count = 0;count<10;count++)
	{
		cout<<setw(6)<<buffer[count];
	}//∂¡»° 
	cout<<endl; 
    file.close(); 
    return 0;
} 
