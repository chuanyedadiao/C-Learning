#include<iostream>
using namespace std; 
#include<string.h>

class Student{
	private:
		int num;
		char name[20];
		int score;
	public:
		Student(int number,char studentName[]);
		void add_score(int TotalScore);
		void printInformation();
}; 

Student::Student(int number,char studentName[])
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
	char str[20];
	strcpy(str,"Wang");
	Student stu(30720106,str);
	stu.add_score(594);
	stu.printInformation();
	return 0;
}
