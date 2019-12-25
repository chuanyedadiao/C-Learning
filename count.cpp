//统计一个string对象在另一个对象中出现的次数
#include<iostream>
#include<string>
using namespace std;


int main()
{
	int count = 0,i,j;
	string s1,s2;
	cout<<"Please enter s1 and s2"<<endl;
	cin>>s1;
	cin>>s2;
	
	for(i = 0;i < s1.size();i++)
	{
		if(s1[i] == s2[0])
		{
			for(j = 0;j < s2.size() && i+j < s1.size();j++)
			{
				if(s1[i+j] != s2[j])
				{
					break;
				}
			}
			if(j == s2.size())
			{
				count++;
			}
		}
	}
	
	cout<<s2<<"在"<<s1<<"中出现次数为:"<<count<<endl;
	return 0;
} 
