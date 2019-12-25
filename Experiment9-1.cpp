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
			cout<<"姓名:"<<name<<";";
			if(gender == 'm') cout<<"性别:男;";
			else cout<<"性别:女;";
			cout<<"生日:";
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
            cout<<"姓名:"<<name<<";";
			if(gender == 'm') cout<<"性别:男;";
			else cout<<"性别:女;";
			cout<<"生日:";
			birthday.Print();
			cout<<"\n";
			cout<<"学号:"<<stuId<<";";
			cout<<"就读时间:"<<stuDuration<<"年;"<<endl;
		}
	
};

void Test1()
{
	Date d1(1991,1,1),d2(1990,2,2);
    Person p1,p2("zhang",'f',d1),p3(p2);
    p3.Print();		//输出: “姓名:zhang;性别: 女;生日:1991-1-1;
    cout<<"收支为:"<<p3.GetCashFlow()<<"元"<<endl; //输出：0元
    Person *p=new Person("li",'m',d2);//创建堆对象（调用有参构造）
    p->Print();		//输出堆对象基本信息
    delete p;		//释放堆对象
}

void Test2()
{
    Date d1(1992,1,1);
    Student s1,s2("zhang",'m',d1,1001);
   
    s2.Print(); //输出如下:

    //姓名:zhang; 性别: 男; 生日:1992-1-1;
    //学号:1001; 就读时间:0年
   
    cout<<endl;
    s2.SetDuration(2);
    s2.Print();
    //姓名:zhang; 性别: 男; 生日:1992-1-1;
    //学号:1001; 就读时间:2年
 
    cout<<endl<<"学费支出"<<s2.GetCashFlow()<<"元"<<endl;
    //学费支出：10000元
   
    Student *p=new Student; //堆对象创建（调用无参构造）
    delete p;//释放堆对象
}

int main()
{ 
    Test1();
    Test2();
	return 0;
} 
