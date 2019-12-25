#include<iostream>
#include<string>
using namespace std;
//合并两个字符串 

string Merge(string s1,string s2)
{
	string s;
	s = s1;
	s.append(1,'.');
	s = s + s2;
	return s;
}

int main()
{
	string s1,s2,s3;
	cout<<"Please enter s1 and s2"<<endl;
	getline(cin,s1);
	getline(cin,s2);
	s3 = Merge(s1,s2);
	cout<<"After Merge:"<<endl;
	cout<<s3;
	return 0;
}
