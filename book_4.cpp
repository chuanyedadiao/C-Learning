#include<iostream>
#include<string.h>
using namespace std;

void Upper(char* s)
{
	int len = strlen(s);
	for(int i = 0;i < len;i++)
	{
		if(i == 0 && s[i] <= 'z' && s[i] >='a')
		{
			s[i] -= 32;
		} 
		if(s[i-1] == ' ' && s[i] <= 'z' && s[i] >='a')
		{
			s[i] -= 32;
		}
	}
}

int main()
{
	char* str;
	str = new char[80];
	cout<<"Please enter the string!\n";
	cin.getline(str,80);
	Upper(str);
	cout<<"After change:\n"<<str<<endl;
	return 0;
} 



