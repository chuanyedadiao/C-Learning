#include<iostream>
#include<string.h>
using namespace std;

struct Student
{
	int num;
	bool availability;// �ɼ��Ƿ���Ч 
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
	strcpy(student.name,"��ɺ");
	student.availability=1;
	student.score=80.50;
	cout<<student;
	return 0;
}
