#include<iostream>
#include<string.h>
using namespace std;

class Student{
	private:
		int num;
		char name[20];
		int score;
	public:
		void initInformaion(int number,char studentName[]);
		void add_score(int TotalScore);
		void printInformation();
}; 

void Student::initInformaion(int number,char studentName[])
{
	num=number;
	strcpy(name,studentName);
}

void Student::add_score(int TotalScore)
{
	score=TotalScore;
}

void Student::printInformation()
{
	cout<<num<<" "<<name<<" "<<score<<endl;
}

int main()
{
	Student stu;
	char str[20];
	strcpy(str,"Wang");
	stu.initInformaion(30720106,str);
	stu.add_score(594);
	stu.printInformation();
	return 0;
} 
