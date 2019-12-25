#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;

bool FindString(char out[],char find[],int &count)
{
	int len = strlen(find);
	int i = 0;
	bool judge = false;
	while(out[i] != '\0'){
		if(strncmp(find,&out[i],len) == 0){
			count++;
			judge = true;
		}
		i++;
	}
	return judge;
}

void Clear(char out[])
{
	for(int i = 0;out[i] != '\0';i++)
	{
		out[i] = '\0';
	}
}

int main()
{
	char filename[30];
	cout<<"Please input the file name:"<<endl;
	cin.getline(filename,30);
	char find[30];
	cout<<"Please input the string you want to find:"<<endl;
	cin.getline(find,30);
	fstream file;
	file.open(filename,ios::in);
	if(!file){
		cout<<"Open the file wrong!"<<endl;
		exit(0);
	}
	
	int count = 0;
	char out[80];
	while(file.eof() == false){
		file.getline(out,80);
		if(FindString(out,find,count)){
			cout<<out<<endl;
		}
		Clear(out);
	}
	cout<<find<<"出现了"<<count<<"次"<<endl; 
} 
