#include<iostream>
#include<string.h> 
using namespace std;

class Date
{
	private:
		int year,month,day;
	public:
		Date(int year=1990,int month=1,int day=1);
		Date(Date &r);
		void Print();
};

Date::Date(int year,int month,int day)
{
	this->year=year;
	this->month=month;
	this->day=day;
}

Date::Date(Date &r)
{
	year=r.year;
	month=r.month;
	day=r.day;
}

void Date::Print()
{
	cout<<year<<'-'<<month<<'-'<<day<<endl;
}

class Person{
	protected:
		char name[20];
		char gender;
		Date birthday;
		static int count;
	public:
		Person(){}
		Person(char n[],char g,Date b){
			strcpy(name,n);
			gender = g;
			birthday = b;
		}
		Person(Person &in){
			strcpy(name,in.name);
			gender = in.gender;
			birthday = in.birthday;
		}
		virtual float GetCashFlow()
		{
			return 0.0;
		}
		void Print()
		{
			cout<<"����:"<<name<<";";
			if(gender == 'm') cout<<"�Ա�:��;";
			else cout<<"�Ա�:Ů;";
			cout<<"����:";
			birthday.Print();
			cout<<"\n"; 
		}
};

class Student:public Person{
	private:
		int stuId;
		int stuDuration;
		float tuition;
	public:
		Student(){}
		Student(char n[],char g,Date d,int s):Person(n,g,d){
			stuId = s;
			stuDuration = 0;
			tuition = 5000;
		}
		float GetCashFlow(){
			return tuition*stuDuration;
		}
		void SetDuration(int s)
		{
			stuDuration = s;
		}
		void Print(){
            cout<<"����:"<<name<<";";
			if(gender == 'm') cout<<"�Ա�:��;";
			else cout<<"�Ա�:Ů;";
			cout<<"����:";
			birthday.Print();
			cout<<"\n";
			cout<<"ѧ��:"<<stuId<<";";
			cout<<"�Ͷ�ʱ��:"<<stuDuration<<"��;"<<endl;
		}
	
};

void Test1()
{
	Date d1(1991,1,1),d2(1990,2,2);
    Person p1,p2("zhang",'f',d1),p3(p2);
    p3.Print();		//���: ������:zhang;�Ա�: Ů;����:1991-1-1;
    cout<<"��֧Ϊ:"<<p3.GetCashFlow()<<"Ԫ"<<endl; //�����0Ԫ
    Person *p=new Person("li",'m',d2);//�����Ѷ��󣨵����вι��죩
    p->Print();		//����Ѷ��������Ϣ
    delete p;		//�ͷŶѶ���
}

void Test2()
{
    Date d1(1992,1,1);
    Student s1,s2("zhang",'m',d1,1001);
   
    s2.Print(); //�������:

    //����:zhang; �Ա�: ��; ����:1992-1-1;
    //ѧ��:1001; �Ͷ�ʱ��:0��
   
    cout<<endl;
    s2.SetDuration(2);
    s2.Print();
    //����:zhang; �Ա�: ��; ����:1992-1-1;
    //ѧ��:1001; �Ͷ�ʱ��:2��
 
    cout<<endl<<"ѧ��֧��"<<s2.GetCashFlow()<<"Ԫ"<<endl;
    //ѧ��֧����10000Ԫ
   
    Student *p=new Student; //�Ѷ��󴴽��������޲ι��죩
    delete p;//�ͷŶѶ���
}

int main()
{ 
    Test1();
    Test2();
	return 0;
} 
