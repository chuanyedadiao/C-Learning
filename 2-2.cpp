#include<iostream>
#include<string>
#include<string.h>
using namespace std;

void ADD(int i1,int i2)
{
	cout<<"int: "<<i1+i2<<endl;
}

void ADD(float f1,float f2)
{
	cout<<"float: "<<f1+f2<<endl;
}

void ADD(double d1,double d2)
{
	cout<<"double: "<<d1+d2<<endl;
}

void ADD(char c1,char c2)
{
	char str[2];
	str[0]=c1;
	str[1]=c2;
	cout<<"char: "<<str<<endl;
}

void ADD(string s1,string s2)
{
	cout<<"string: "<<s1+s2<<endl;
}

int main()
{
	int i1,i2;
	float f1,f2;
	double d1,d2;
	char c1,c2;
	string str1,str2;
	cout<<"Please enter two int"<<endl;
	cin>>i1>>i2;
	cout<<"Please enter two float"<<endl;
	cin>>f1>>f2;
	cout<<"Please enter two double"<<endl;
	cin>>d1>>d2;
	cout<<"Please enter two char"<<endl;
	cin>>c1>>c2;
	cout<<"Please enter two string"<<endl;
	cin>>str1>>str2;
	ADD(i1,i2);
	ADD(f1,f2);
	ADD(d1,d2);
	ADD(c1,c2);
	ADD(str1,str2);
	return 0;
}
