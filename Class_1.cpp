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
	Person P1("8124401","陈建华","中吴大道1801号");
	Person P2("1234567","xu","hunan");
	cout<<"P1的信息"<<endl;
	P1.print();
	cout<<"进行=操作前的P2的信息"<<endl;
	P2.print();
	cout<<"进行=操作后的P2的信息"<<endl;
	P2 = P1;
	P2.print();
	return 0;
}
