#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//��д�������ļ�

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
		cout<<"���ļ�ʧ��"<<endl;
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
		cout<<"���ļ�ʧ��"<<endl;
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
	cout<<"�������޸�ʲô��Ϣ��"<<endl;
	cin.ignore();
	cin.getline(information,30);
	if(strcmp(information,"ѧ��") == 0){
		char num[20];
		cout<<"�����������޸ĵ�ѧ��:";
		cin>>num;
		strcpy(data->num,num);
		return ;
	} 
	if(strcmp(information,"����") == 0){
		char name[20];
		cout<<"�����������޸ĵ�����:";
		cin>>name;
		strcpy(data->name,name);
	}
	if(strcmp(information,"����") == 0){
		int age;
		cout<<"�����������޸ĵ�����:";
		cin>>age;
		data->age = age;
	}
	if(strcmp(information,"�Ա�") == 0){
		char gender;
		cout<<"�����������޸ĵ��Ա�:";
		cin>>gender;
		data->gender = gender;
	}
}

bool UpDate(char* file,int id)
{
	fstream fs(file,ios::in|ios::out|ios::binary);
	if(!fs){
		cout<<"���ļ�ʧ��"<<endl;
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
		cout<<"�ҵ���ͬѧ:"<<endl;
		cout<<"ѧ�ţ�"<<out.num<<endl;
		cout<<"������"<<out.name<<endl;
		cout<<"���䣺"<<out.age<<endl;
		cout<<"�Ա�"<<out.gender<<endl;
	}
	else{
		cout<<"�Ҳ�����ͬѧ����Ϣ"<<endl;
		return 0; 
	}
	
	int i;
	cout<<"���������޸ĵڼ�λͬѧ����Ϣ��"<<endl;
	cin>>i;
	LoadFile(filename);
	UpDate(filename,i);
	LoadFile(filename);
	return 0;
	
}
