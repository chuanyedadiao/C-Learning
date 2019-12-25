#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	fstream file1,file2,file3;
	file1.open("a1.txt",ios::in);
	if(!file1){
		cout<<"Open the file wrong!"<<endl;
		exit(0);
	}
	file2.open("a2.txt",ios::in);
	if(!file2){
		cout<<"Open the file wrong!"<<endl;
		exit(0);
	}
	file3.open("a3.txt",ios::out);
	if(!file3){
		cout<<"Open the file wrong!"<<endl;
		exit(0);
	}//分别打开文件
	
	int num1,num2;
	file1>>num1;
	file2>>num2;
	
	while(!file1.eof() && !file2.eof()){
		if(num1<num2){
			file3<<num1<<" ";
			file1>>num1;
		}
		else{
			file3<<num2<<" ";
			file2>>num2;
		}
	} 
	
	while(file1.eof() == false)
	{
		file3<<num1<<" ";
		file1>>num1;
	}
	
	while(file2.eof() == false)
	{
		file3<<num2<<" ";
		file2>>num2;
	}//若两个文件中有哪一个没有读完则继续读
	file3<<endl;
	file1.close();
	file2.close();
	file3.close();
	return 0; 
}
