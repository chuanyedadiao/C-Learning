#include<iostream>
#include<string>
using namespace std;

class Person{
	private:
		string ID;
		string name;
		string homeadd;
	public:
		Person(){}
		Person(string s1,string s2,string s3):ID(s1),name(s2),homeadd(s3){
		}
		Person(Person& in):ID(in.ID),name(in.name),homeadd(in.homeadd){
		}
		~Person(){}
		void operator=(Person& p);
		void print(){
			cout<<ID<<" "<<name<<" "<<homeadd<<endl;
		}
};

void Person::operator=(Person& p)
{
	ID = p.ID;
	name = p.name;
	homeadd = p.homeadd;
}

int main()
{
	Person P1("8124401","�½���","������1801��");
	Person P2("1234567","xu","hunan");
	cout<<"P1����Ϣ"<<endl;
	P1.print();
	cout<<"����=����ǰ��P2����Ϣ"<<endl;
	P2.print();
	cout<<"����=�������P2����Ϣ"<<endl;
	P2 = P1;
	P2.print();
	return 0;
}
