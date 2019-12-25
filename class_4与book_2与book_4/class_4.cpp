#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//计数器

 
int main()
{
	char filename[80];
	cout<<"Please enter the filename //1-1(1).cpp"<<endl;
	cin>>filename;
	fstream datafile;
	datafile.open(filename,ios::in);
	if(!datafile){
		cout<<"打开文件错误"<<endl;
		exit(0);
	}
	char buf[256];
	int counter = 0;
	int line = 1;
	while(datafile.eof() == false){
		datafile.getline(buf,256);
		cout<<line<<": "<<buf<<endl;
		counter++;
		line++;
		if(counter % 24 == 0) getchar();
	}
	datafile.close();
	return 0;
}
