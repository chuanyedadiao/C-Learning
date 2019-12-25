#include"student.h" 

float student::total_score = 0.0;
int student::count = 0;

void student::print()
{
	cout<<"Name:"<<name<<" ";
	cout<<"Age:"<<age<<" ";
	cout<<"Num:"<<num<<" ";
	cout<<"Score"<<score<<endl;
}

void student::account(float s)
{
	score = s;
}

float student::sum(float s)
{
	total_score += s;
	count++;
	return total_score; 
}

float student::average()
{
	return total_score/count;
}
