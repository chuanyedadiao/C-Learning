#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//读写二进制文件

struct student{
	char num[11];
	char name[10];
	int age;
	char gender;
};

ostream& operator<<(ostream& out,const student& data)
{
	out<<data.num<<" "<<data.name<<" "<<data.age<<" "<<data.gender<<endl;
	return out;
}

void LoadFile(char *file)
{
	fstream fs(file,ios::in|ios::binary);
	if(!fs){
		cout<<"打开文件失败"<<endl;
		exit(0);
	}
	while(!fs.eof())
	{
		student data;
		fs.read((char*)&data,sizeof(student));
		if(fs.fail())
		    break;
		cout<<data<<endl;
	}
	fs.close();
}

bool SearchStudent(char* file,char id[],student* out)
{
	fstream fs(file,ios::in|ios::binary);
	if(!fs){
		cout<<"打开文件失败"<<endl;
		exit(0);
	}
	bool find = false;
	while(!fs.eof())
	{
		fs.read((char*)out,sizeof(student));
		if(fs.fail())
		    break;
		if(strcmp(out->num,id) == 0){
			find = true;
			break;
		}
	}
	fs.close();
	return find;
}

void ChangeInformation(student *data)
{
	char information[30];
	cout<<"请问想修改什么信息？"<<endl;
	cin.ignore();
	cin.getline(information,30);
	if(strcmp(information,"学号") == 0){
		char num[20];
		cout<<"请输入你想修改的学号:";
		cin>>num;
		strcpy(data->num,num);
		return ;
	} 
	if(strcmp(information,"姓名") == 0){
		char name[20];
		cout<<"请输入你想修改的姓名:";
		cin>>name;
		strcpy(data->name,name);
	}
	if(strcmp(information,"年龄") == 0){
		int age;
		cout<<"请输入你想修改的年龄:";
		cin>>age;
		data->age = age;
	}
	if(strcmp(information,"性别") == 0){
		char gender;
		cout<<"请输入你想修改的性别:";
		cin>>gender;
		data->gender = gender;
	}
}

bool UpDate(char* file,int id)
{
	fstream fs(file,ios::in|ios::out|ios::binary);
	if(!fs){
		cout<<"打开文件失败"<<endl;
		exit(0);
	}
	fs.seekg((id-1) * sizeof(student));
	student data;
	fs.read((char*)&data,sizeof(student));
	ChangeInformation(&data);
	fs.seekp((id-1) * sizeof(student));
	fs.write((char*)&data,sizeof(data));
	
	fs.close();
	return true;
}
 
int main()
{
	char filename[30];
	strcpy(filename,"student.txt");
	LoadFile(filename);

	char id[20];
	cout<<"Please input the student's ID"<<endl;
	cin.getline(id,20);
	
	student out;
	bool find = SearchStudent(filename, id, &out);
	
	if(find){
		cout<<"找到该同学:"<<endl;
		cout<<"学号："<<out.num<<endl;
		cout<<"姓名："<<out.name<<endl;
		cout<<"年龄："<<out.age<<endl;
		cout<<"性别："<<out.gender<<endl;
	}
	else{
		cout<<"找不到该同学的信息"<<endl;
		return 0; 
	}
	
	int i;
	cout<<"请问你想修改第几位同学的信息？"<<endl;
	cin>>i;
	LoadFile(filename);
	UpDate(filename,i);
	LoadFile(filename);
	return 0;
	
}
