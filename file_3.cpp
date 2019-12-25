#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
	fstream in,out;
	int count = 0;
	string str;
	in.open("File.txt",ios::in);
	out.open("TextFile.txt",ios::out);
	char ch;
	ch = in.get();
	while(!in.eof()){
		if(ch >= 'a' && ch <= 'z'){
			ch -= 32;
		}
		out<<ch;
		ch = in.get();
	}
	in.close();
	out.close();
	
	in.open("TextFile.txt",ios::in);
	ch = in.get();
	while(!in.eof())
	{
		cout<<ch;
		ch = in.get();
	}
	in.close();
	
	in.open("TextFile.txt",ios::in);
	in>>str;
	while(!in.eof())
	{
		if(str == "THE"){
			count++;
		}
		in>>str;
	}
	in.close();
	cout<<"\n"<<count;
	return 0;
}
