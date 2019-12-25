#include<iostream>
#include<string.h>
using namespace std;

struct Student
{
	int num;
	bool availability;// 成绩是否有效 
	char name[20];
	double score;
};

ostream& operator<<(ostream& o,const Student& stu)
{
	o<<stu.num<<" "<<stu.name<<" ";
	if(stu.availability==1) o<<"Yes"<<" "<<stu.score<<endl;
	else o<<"No"<<" "<<"No Score"<<endl;
}

int main()
{
	Student student;
	student.num=1;
	strcpy(student.name,"张珊");
	student.availability=1;
	student.score=80.50;
	cout<<student;
	return 0;
}
