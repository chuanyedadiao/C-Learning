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
	}//������д���ļ� 
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
	}//��ȡ��num���������Ļ 
	in_file.close();
	return 0;
}
