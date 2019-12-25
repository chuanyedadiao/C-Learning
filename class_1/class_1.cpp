#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream out_file;
	out_file.open("write.txt");
	if(out_file.fail() == false)
	{
		for(int i = 0;i <10;i++)
		{
			out_file<<i<<" ";
		}
	}//将数字写入文件 
	out_file.close();
	int num;
	ifstream in_file;
	in_file.open("write.txt");
	if(in_file.fail() == false)
	{
		in_file>>num;
		while(!in_file.eof())
		{
			cout<<num<<" ";
			in_file>>num;
		}
	}//读取到num，输出到屏幕 
	in_file.close();
	return 0;
}
