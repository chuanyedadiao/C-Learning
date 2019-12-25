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
	cout<<"��ʼ:"<<endl;
	s.ShowStr();
	if(s.isSubstring("C Programming"))
	{
		cout<<"Mystring���ַ�����C Programmingһ��"<<endl;
	}
	else{
		cout<<"Mystring���ַ�����C Programming��һ��"<<endl;
	}
	s.toUpperCase();
	cout<<"��ɴ�д��:"<<endl;
	s.ShowStr();
	return 0;
}



