#include<string>
#include"student.cpp"

int main()
{
	int i,age;
	string name,num;
	float score,sum,average;
	student stu[5];
	cout<<"Please enter 5 students name,age,num\n";
	for(i = 0;i < 5;i++)
	{
		cin>>name>>age>>num;
		student s(name,age,num,0);
		stu[i] = s;
	}
	cout<<"Please enter the score of every student;\n";
	for(i = 0;i < 5;i++)
	{
		cin>>score;
		stu[i].account(score);
		sum = student::sum(score);
	}
	average = student::average();
	cout<<"The total_score of this class is:"<<sum<<endl;
	cout<<"The average_score of this class is:"<<average<<endl;
	cout<<"��һ��ѧ������Ϣ: "<<endl;
	stu[0].print();
	cout<<"������ѧ������Ϣ: "<<endl;
	stu[2].print();
	cout<<"�����ѧ������Ϣ: "<<endl;
	stu[4].print();
	return 0;
} 
