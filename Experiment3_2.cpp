#include<iostream>
#include<string.h>
#define Max_F 100
#define Max_G 100
using namespace std;

class friends
{
	private:		
	    string name;//�洢��������
	    char sex;//f or m
		int age;
	    string telephone;
	    string email;
	    string birthday;
	public:
		 friends(){}
		 friends(string n,char s,int a,string t,string e,string b)
		 {
		 	name = n;
		 	sex = s;
		 	age = a;
		 	telephone = t;
		 	email = e;
		 	birthday = b;
		 }
		 friends(const friends &in)
		 {
		 	name = in.name;
		 	sex = in.sex;
		 	age = in.age;
		 	telephone = in.telephone;
		 	email = in.email;
		 	birthday = in.birthday;
		 }
	     bool operator==(friends f2);
	     string GetName(){return name;}
	     void NameChan(string n){name =n;}
	     void SexChan(char s){sex =s;}
	     void AgeChan(int a){age =a;}
	     void telephoneChan(string t){telephone =t;}
	     void emailChan(string e){email =e;}
	     void birthdayChan(string b){birthday =b;}
	     void print(){
	     	cout<<"Name:"<<name<<" ";
	     	cout<<"Sex:"<<sex<<" ";
	     	cout<<"Age:"<<age<<" "<<endl;
	     	cout<<"Telephone:"<<telephone<<" ";
	     	cout<<"Email:"<<email<<" ";
	     	cout<<"Birthday:"<<birthday<<endl;
	     }
};

bool friends::operator==(friends in)
{
	if(name == in.name && sex == in.sex && age == in.age &&telephone == in.telephone && email == in.email &&birthday ==in.birthday)
	    return true;
	else return false;
}

class Friend{
	private:
		friends fr[Max_F];
		int friend_count;
		string groupName;
	public:
		void init(string s){
			groupName = s;
			friend_count = 0;
		}
		string GetGroupName(){return groupName;}
	    void add_friends(friends in)
	    {
	    	fr[friend_count] = in;
	    	friend_count++;
	    }
	    void Delete_friends(friends in);
	    void ChangeIn(friends in);
	    void displayIn();
};

void Friend::Delete_friends(friends in)
{
	int i,j;
	for(i = 0;i < friend_count;i++)
	{
		if(fr[i] == in)
		{
			break;
		}
	}
	if(i == friend_count){
		cout<<"������"<<in.GetName()<<"���ڴ˷���"<<groupName<<"��"<<endl;
		return;
	}
	for(j = i;j < friend_count-1;j++)
	{
		fr[j] = fr[j+1];
	}
	friend_count--;
}

void Friend::ChangeIn(friends in)
{
	int i;
	string s1,info;
	char sex;
	int chan_age;
	for(i = 0;i < friend_count;i++)
	{
		if(fr[i] == in)
		{
			break;
		}
	}
	if(i == friend_count){
		cout<<"������"<<in.GetName()<<"���ڴ˷���"<<groupName<<"��"<<endl;
		return;
	}
	cout<<"������������ĵ���Ϣ"<<endl;
	cin>>s1;
	if(s1 == "Name"){
		cout<<"������������ĵ�����"<<endl;
		cin>>info;
		fr[i].NameChan(info);
		return;
	}
	if(s1 == "Sex"){
		cout<<"������������ĵ��Ա�"<<endl;
		cin>>sex;
		fr[i].SexChan(sex);
		return;
	}
	if(s1 == "Age"){
		cout<<"������������ĵ�����"<<endl;
		cin>>chan_age;
		fr[i].AgeChan(chan_age);
		return;
	}
	if(s1 == "Telephone"){
		cout<<"������������ĵĵ绰"<<endl;
		cin>>info;
		fr[i].telephoneChan(info);
		return;
	}
	if(s1 == "Email"){
		cout<<"������������ĵ�����"<<endl;
		cin>>info;
		fr[i].emailChan(info);
		return;
	}
	if(s1 == "Birthday"){
		cout<<"������������ĵ�����"<<endl;
		cin>>info;
		fr[i].birthdayChan(info);
		return;
	}
}

void Friend::displayIn()
{
	cout<<groupName<<":\n\n";
	for(int i = 0 ; i < friend_count;i++)
	{
		cout<<i+1<<":";
		fr[i].print();
		cout<<"\n";
	}
}

class Master{
	private:
		int group_count;
		Friend group[Max_G];
	public:
		Master(){
			group_count = 0;
		}
		void Add_Group(string groupname);
		void Add(string groupname,friends in);
		void Delete(string groupname,friends in);
		void ChangeInformation(string groupname,friends in);
		void Display();
};

void  Master::Add_Group(string groupname)
{
    group[group_count].init(groupname);
    group_count++;
}

void Master::Add(string groupname,friends in)
{
	int i;
	for(i = 0;i < group_count;i++)
	{
		if(groupname == group[i].GetGroupName())
		{
			break;
		}
	}
	if(i == group_count)
	{
		cout<<"û�и÷���"<<groupname<<endl;
		return ; 
	}
	group[i].add_friends(in);
}

void Master::Delete(string groupname,friends in)
{
	int i;
	for(i = 0;i < group_count;i++)
	{
		if(groupname == group[i].GetGroupName())
		{
			break;
		}
	}
	if(i == group_count)
	{
		cout<<"û�и÷���"<<groupname<<endl;
		return ; 
	}
	group[i].Delete_friends(in);
}

void Master::ChangeInformation(string groupname,friends in)
{
	int i;
	for(i = 0;i < group_count;i++)
	{
		if(groupname == group[i].GetGroupName())
		{
			break;
		}
	}
	if(i == group_count)
	{
		cout<<"û�и÷���"<<groupname<<endl;
		return ; 
	}
	group[i].ChangeIn(in);
}

void Master::Display()
{
	int i;
	for(i = 0 ;i < group_count;i++)
	{
		group[i].displayIn();
	}
}

int main()
{
	Master s;
	s.Add_Group("Family");
	s.Add_Group("ClassMates");
	s.Add_Group("WorkMates");//����������
	friends f1("xu",'f',20,"13242353456","7099872@qq.com","6.7.1998");
	friends f2("chen",'m',19,"15326354728","7654321@nuaa.edu.cn","5.8.1999");
	friends f3("xiang",'f',21,"19876543210","2314567@qq.com","8.10.2000");
	
	cout<<"��f1��ӵ�family,��f2��ӵ�Classmates,��f3��ӵ�WorkMates\n";
	s.Add("Family",f1);
	s.Add("ClassMates",f2);
	s.Add("WorkMates",f3);
	s.Display();
	cout<<"\n\n\n";
	
	cout<<"��f3��ӵ�Family"<<endl;
	s.Add("Family",f3);
	s.Display();
	cout<<"\n\n\n";
	
	cout<<"��Family��ɾ��f2,f1"<<endl;
	s.Delete("Family",f2);
	s.Delete("Family",f1);
	s.Display();
	cout<<"\n\n\n";
	
	cout<<"����ClassMates��f2����Ϣ"<<endl;
	s.ChangeInformation("ClassMates",f2);
	s.Display();
	return 0;
}
