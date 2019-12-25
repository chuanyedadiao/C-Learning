#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string>
#define MAX_NO 5
#define MAX_PERSON 100
#define MAX_BOOK 100
using namespace std;

class Student{
	private:
		string num;
		string name;
        int borrow_num;
		string book_num[MAX_NO];
	public:
		void initstu(string s1,string s2){
			num = s1;
			name = s2;
			borrow_num = 0;
			for(int i = 0;i < MAX_NO;i++)
			     book_num[i] = '0';
		}
		string Getnum(){
			return num;
		}
		void Lend(string s){
			book_num[borrow_num] = s;
			borrow_num++;
		}
		void Return(string s){
			int i,j;
			for(i = 0; i < borrow_num;i++){
				if(book_num[i] == s)
				    break;
			}
			if(i == borrow_num){
				cout<<"This person didn't borrow this book"<<endl;
				return ;
			}
			for(j = i;j < borrow_num-1;i++){
				book_num[j] = book_num[j+1];
			}
			borrow_num--;
		}
		int GetBorrowNum(){
			return borrow_num;
		}
		void print()
		{
			cout<<"ѧ��:"<<num<<" ";
			cout<<"����:"<<name<<" ";
			if(borrow_num == 0){
				cout<<"���޽����鼮"<<endl;
				return ;
			}
			cout<<"�����鼮��ŷֱ�Ϊ:"<<endl;
			for(int i = 0;i < borrow_num;i++){
				cout<<book_num[i]<<endl;
			}
		}
}; 

class Teacher{
	private:
		string num;
		string name;
		int borrow_num;
		string book_num[MAX_NO];
	public:
		void inittea(string s1,string s2){
			num = s1;
			name = s2;
			borrow_num = 0;
			for(int i = 0;i < MAX_NO;i++)
			     book_num[i] = '0';
		}
		string Getnum(){
			return num;
		}
		void Lend(string s){
			book_num[borrow_num] = s;
			borrow_num++;
		}
		void Return(string s){
			int i,j;
			for(i = 0; i < borrow_num;i++){
				if(book_num[i] == s)
				    break;
			}
			if(i == borrow_num){
				cout<<"This person didn't borrow this book"<<endl;
				return ;
			}
			for(j = i;j < borrow_num-1;i++){
				book_num[j] = book_num[j+1];
			}
			borrow_num--;
		}
		int GetBorrowNum(){
			return borrow_num;
		}
		void print()
		{
			cout<<"����:"<<num<<" ";
			cout<<"����:"<<name<<" ";
			if(borrow_num == 0){
				cout<<"���޽����鼮"<<endl;
				return ;
			}
			cout<<"�����鼮��ŷֱ�Ϊ:"<<endl;
			for(int i = 0;i < borrow_num;i++){
				cout<<book_num[i]<<endl;
			}
		}
};

class Book{
	private:
		string name;
		string num;
		int total;
		int left;
	public:
		void initbook(string s1,string n,int t){
		    name = s1;
		    num = n;
		    total = t;
		    left = total;
		}
		void print(){
			cout<<"����:"<<name<<" ";
			cout<<"���:"<<num<<" ";
			cout<<"����:"<<total<<" ";
			cout<<"ʣ��:"<<left<<endl;
		}
		string Getnum(){
			return num;
		}
		int Gettotal(){
			return total;
		}
		int Getleft(){
			return left;
		}
		void borrow(){
			left--;
		}
		void back(){
			left++;
		}
};

class System{
	private:
		Student stu[MAX_PERSON];
		Teacher tea[MAX_PERSON];
		Book book[MAX_BOOK];
		int booknum;
		int stunum;
		int teanum;
	public:
		void InitLibrary(); 
		void InitStudent();
		void InitTeacher();
		void Borrow(string user,string id,string n);
		void Return(string user,string id,string n);
		void Scan();
		void PersonnalInformation(string user,string id);
}; 

void System::InitLibrary()
{
	string s,n;
	int t,k = 0;
	fstream fs1;
	fs1.open("book.txt",ios::in);
	while(fs1.eof() == false){
		fs1>>s>>t>>n;
		if(fs1.fail()){
			break;
		}
		book[k].initbook(s,n,t);
		k++;
	}
	booknum = k;
	fs1.close();
}

void System::InitStudent()
{
	int k = 0;
	fstream fs2;
	fs2.open("reader.txt",ios::in);
	string s1,s2;
	while(fs2.eof() == false){
		fs2>>s1>>s2;
		if(fs2.fail()){
			break;
		}
		stu[k].initstu(s1,s2);
		k++;
	}
	stunum = k;
	fs2.close();
}

void System::InitTeacher()
{
	int k = 0;
	fstream fs3;
	fs3.open("readers.txt",ios::in);
	string s1,s2;
	while(fs3.eof() == false){
		fs3>>s1>>s2;
		if(fs3.fail()){
			break;
		}
		tea[k].inittea(s1,s2);
		k++;
	}
	teanum = k;
	fs3.close();
}//��ʼ��ͼ���ѧ������ʦ

void System::Scan()
{
	for(int i = 0;i < booknum;i++)
	{
		book[i].print();
	}
} 

void System::Borrow(string user,string id,string n)
{
	int i,j;
	if(user == "teacher"){
		for(i = 0;i < teanum;i++)
		{
			if(tea[i].Getnum() == id)
		        break;
		}
		if(i == teanum){
			cout<<"No this Teacher"<<endl;
			return ;
		}
		for(j = 0;j < booknum;j++)
		{
			if(book[j].Getnum() == n)
			    break;
		}
		if(j == booknum){
	    	cout<<"No this Book"<<endl;
	    	return ;
	    }
		if(book[j].Getleft() == 0){
			cout<<"There is no left book"<<endl;
			return ;
		}
		if(tea[i].GetBorrowNum() > MAX_NO){
			cout<<"You can't borrow books anymore"<<endl;
		    return ;
		}
		book[j].borrow();
		tea[i].Lend(book[j].Getnum());
	}
	if(user == "student"){
		for(i = 0;i < stunum;i++)
		{
			if(stu[i].Getnum() == id)
		        break;
		}
		if(i == stunum){
			cout<<"No this Student"<<endl;
			return;
		}
		for(j = 0;j < booknum;j++)
		{
			if(book[j].Getnum() == n)
			    break;
		}
		if(j == booknum){
	    	cout<<"No this Book"<<endl;
	    }
		if(book[j].Getleft() == 0){
			cout<<"There is no left book"<<endl;
			return ;
		}
		if(stu[i].GetBorrowNum() > MAX_NO){
			cout<<"You can't borrow books anymore"<<endl;
			return ;
		}
		book[j].borrow();
		stu[i].Lend(book[j].Getnum());
	}
}

void System::Return(string user,string id,string n)
{
	int i,j;
	if(user == "teacher"){
		for(i = 0;i < teanum;i++)
		{
			if(tea[i].Getnum() == id)
		        break;
		}
		if(i == teanum){
			cout<<"No this Teacher"<<endl;
			return ;
		}
		for(j = 0;j < booknum;j++)
		{
			if(book[j].Getnum() == n)
			    break;
	    }
	    if(j == booknum){
	    	cout<<"No this Book"<<endl;
	    	return ;
	    }
		book[j].back();
		tea[i].Return(book[j].Getnum());
	}
	if(user == "student"){
		for(i = 0;i < stunum;i++)
		{
			if(stu[i].Getnum() == id)
		        break;
		}
		if(i == stunum){
			cout<<"No this Student"<<endl;
			return ;
		}
		for(j = 0;j < booknum;j++)
		{
			if(book[j].Getnum() == n)
			    break;
	    }
	    if(j == booknum){
	    	cout<<"No this Book"<<endl;
	    	return ;
	    }
		book[j].back();
		stu[i].Return(book[j].Getnum());
	}
}

void System::PersonnalInformation(string user,string id)
{
	int i;
	if(user == "teacher")
	{
		for(i = 0;i < teanum;i++)
		{
			if(tea[i].Getnum() == id)
		        break;
		}
		if(i == teanum){
			cout<<"No this Teacher"<<endl;
			return ;
		}
		tea[i].print();
	}
	if(user == "student")
	{
		for(i = 0;i < stunum;i++)
		{
			if(stu[i].Getnum() == id)
		        break;
		}
		if(i == stunum){
			cout<<"No this Teacher"<<endl;
			return ;
		}
		stu[i].print();
	}
}

int main()
{
	string user;
	int m;
	System lib;
	lib.InitStudent();
	lib.InitTeacher();
	lib.InitLibrary();
	while(1)
	{
		cout<<"Please enter the thing you want to do!"<<endl;
		cout<<"1.return Book"<<endl;
		cout<<"2.Borrow Book"<<endl;
		cout<<"3.Scan the books"<<endl;
		cout<<"4.Find one's information"<<endl;
		cout<<"0.Exit the system"<<endl;
		cin>>m;
		cout<<"And Please enter your identity(student or teacher):"<<endl;
		cin>>user;
		system("cls");
		switch(m){
			case 1:{	
				string id,n;
				cout<<"������Ĺ��Ż���ѧ��!"<<endl;
				cin>>id;
				cout<<"��������黹�鼮�ı��"<<endl;
				cin>>n;
				lib.Return(user,id,n);
				system("pause");
				system("cls");
				break;
			}
			case 2:{
				string id,n;
				cout<<"������Ĺ��Ż���ѧ��!"<<endl;
				cin>>id;
				cout<<"������������鼮�ı��"<<endl;
				cin>>n;
				lib.Borrow(user,id,n);
				system("pause");
				system("cls");
				break;
			}
			case 3:{
				lib.Scan();
				system("pause");
				system("cls");
				break;
			}
			case 4:{
				string id;
				cout<<"������Ĺ��Ż���ѧ��!"<<endl;
				cin>>id;
				lib.PersonnalInformation(user,id);
				system("pause");
				system("cls");
				break;
			}
			case 0:{
				cout<<"�˳�ϵͳ"<<endl; 
				exit(0);
				break;
			}
		}
	}
	return 0;
}
