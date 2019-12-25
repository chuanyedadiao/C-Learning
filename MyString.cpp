#include<iostream>
#include<string.h>
using namespace std;

class Mystring{
	private:
		char *mystr;
		int len;
	public:
		Mystring(){
			len = 0;
			mystr = NULL;
		}
		Mystring(const char *p){
			len = strlen(p);
			mystr = new char[len];
			strcpy(mystr,p);
		}
		Mystring(Mystring &in){
			len = in.len;
			mystr = new char[len];
			strcpy(mystr,in.mystr);
		} 
		~Mystring(){
			delete []mystr;
			len = 0;
		}
		char *GetStr(){return mystr;}
		void ShowStr(){cout<<mystr<<endl;}
		bool isSubstring(const char*str);
		void toUpperCase();
}; 

bool Mystring::isSubstring(const char*str)
{
	if(strcmp(mystr,str) == 0)
	{
		return true;
	}
	else return false;
}

void Mystring::toUpperCase()
{
	for(int i = 0;i < len;i++)
	{
		if(mystr[i] >= 'a' && mystr[i] <= 'z')
		{
			mystr[i] -=32;
		}
	}
}

int main()
{
	Mystring s("C++Programming");
	cout<<"初始:"<<endl;
	s.ShowStr();
	if(s.isSubstring("C Programming"))
	{
		cout<<"Mystring的字符串与C Programming一致"<<endl;
	}
	else{
		cout<<"Mystring的字符串与C Programming不一致"<<endl;
	}
	s.toUpperCase();
	cout<<"变成大写后:"<<endl;
	s.ShowStr();
	return 0;
}



