#include<iostream>
#include<string>
using namespace std;
//令string中不包含ch这个字符


string Delete(string s,char ch)
{
	int len = s.size(),i,j,k = 0;
	for(i = 0;i < len;)
	{
		if(s[i] == ch)
		{
			for(j = i;j < len-1;j++)
			    s[j] = s[j+1];
			s[j] = '\0';
			len--;
		}
		else i++;
	}
	return s;
}

int main()
{
	string s;
	char ch;
	cout<<"Please enter s"<<endl;
	cin>>s;
	cout<<"Please enter ch"<<endl;
	cin>>ch;
	s = Delete(s,ch);
	cout<<"After delete\n";
	cout<<s;
	return 0;
}
