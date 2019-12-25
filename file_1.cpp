#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct student{
	char num[11];
	char name[11];
	int age;
	char gender;
};

int main()
{
	char n[11];
	student stu[10];
    ifstream in("student.dat",ios::in|ios::binary);
	if(!in)
	{
		cout<<"Can not open the file!\n";
		exit(0);
	}
	cin>>n;
	in.read((char*)&stu,sizeof(stu));//remember 
	for(int i = 0;i < 10 ;i++)
	{
		if(strcmp(stu[i].num,n) == 0)
		{
			cout<<stu[i].num<<" "<<stu[i].name<<" "<<stu[i].age<<" "<<stu[i].gender<<endl;
			break;
		}
	}
	in.close();
	return 0;
}
