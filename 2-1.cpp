#include<iostream>
using namespace std;

void print(int num,int value=10)
{
	if(value==2){
		for(int i=31;i>=0;i--)
		{
			cout<<((num>>i)&1);
		}
		cout<<endl;
	}
	if(value==8){
		cout<<oct<<num<<endl;
	}
	if(value==10){
		cout<<num<<endl;
	}
	if(value==16){
		cout<<hex<<num<<endl;
	}
} 

int main()
{
	int n,value;
	cout<<"Please enter n and the value"<<endl;
	cin>>n>>value;
	print(n,value);
	return 0;
}
