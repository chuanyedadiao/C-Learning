#include<iostream>
#include<fstream>
#include<stdlib.h> 
using namespace std;


int main()
{
	fstream file_in,file_out,rewrite;
	file_in.open("source.txt",ios::in);
	if(!file_in){
		cout<<"Can't open the file!"<<endl;
		exit(0);
	}//��ȡ�ļ�
	file_out.open("code.txt",ios::out);
	if(!file_out){
		cout<<"Can't open the file!"<<endl;
		exit(0);
	}
	rewrite.open("recode.txt",ios::out);
	if(!rewrite){
		cout<<"Can't open the file!"<<endl;
		exit(0);
	}
	
	char ch;
	file_in.get(ch);
	while(file_in.eof() == false)
	{
		ch = ch+2;
		file_out<<ch;
	    file_in.get(ch);
	}//��ÿ���ַ���ASCII���2 
	file_in.close();
	file_out.close();
	
	
	file_out.open("code.txt",ios::in);//����
	file_out.get(ch); 
	while(file_out.eof() == false)
	{
		ch=ch-2;
	    rewrite<<ch;
	    file_out.get(ch);
	}
	file_out.close();
	rewrite.close();
	return 0;
} 
