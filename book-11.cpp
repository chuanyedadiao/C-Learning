#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<math.h>

string fun(int n)
{
	string str;
	if(n==0){
		str="��";
		return str;
	} 
	if(n==1){
		str="Ҽ";
		return str;
	} 
	if(n==2){
		str="��";
		return str;
	} 
	if(n==3){
		str="��";
		return str;
	} 
	if(n==4){
		str="��";
		return str;
	} 
	if(n==5){
		str="��";
		return str;
	} 
	if(n==6){
		str="½";
		return str;
	} 
	if(n==7){
		str="��";
		return str;
	} 
	if(n==8){
		str="��";
		return str;
	} 
	if(n==9){
		str="��";
		return str;
	} 
}

class Customer{
	private:
		int day,month,year;
		char name[20];
		float checkNum;
	public:
		void initInformation(int d,int m,int y,char str[],float num);
		void printInformation();
};

void Customer::initInformation(int d,int m,int y,char str[],float num)
{
	day=d;
	month=m;
	year=y;
	strcpy(name,str);
	checkNum=num;
}

void Customer::printInformation()
{
	cout<<"����: "<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
	cout<<"������"<<name<<" RMB"<<checkNum<<endl;
	if((int)checkNum==10000){
		cout<<"�����: Ҽ��"<<endl;
		return ; 
	} 
	int integer[4];
	int num1=(int)checkNum;
	int num2=(int)(checkNum*100),i,j;
	for(i=0;i<4;i++)
	{
		integer[i]=(num1/(int)pow(10,3-i))%10;
	} 
	int decimal[2];
	for(j=0;j<2;j++)
	{
		decimal[j]=(num2/(int)pow(10,1-j))%10;
	}
	cout<<"�����: ";
	for(i=0;i<4;i++)
	{
	    if(integer[i]!=0) break;
	}
	if(i==0){
		cout<<fun(integer[0])<<"Ǫ"<<fun(integer[1])<<"��"<<fun(integer[2])<<"ʰ";
		cout<<fun(integer[3])<<"Ԫ"<<fun(decimal[0])<<"��"<<fun(decimal[1])<<"��"<<endl; 
	}
	if(i==1){
		cout<<fun(integer[1])<<"��"<<fun(integer[2])<<"ʰ";
		cout<<fun(integer[3])<<"Ԫ"<<fun(decimal[0])<<"��"<<fun(decimal[1])<<"��"<<endl; 
	}
	if(i==2){
		cout<<fun(integer[2])<<"ʰ";
		cout<<fun(integer[3])<<"Ԫ"<<fun(decimal[0])<<"��"<<fun(decimal[1])<<"��"<<endl; 
	}
	if(i==3){
		cout<<fun(integer[3])<<"Ԫ"<<fun(decimal[0])<<"��"<<fun(decimal[1])<<"��"<<endl; 
	}
	if(i==4){
		cout<<"��Ԫ"<<fun(decimal[0])<<"��"<<fun(decimal[1])<<"��"<<endl; 
	}
}

int main()
{
	Customer c;
    char str[20];
    float num=20000;
    int d,m,y;
    cout<<"Please enter the day,month,year!"<<endl;
    cin>>d>>m>>y;
    cout<<"Please enter the name"<<endl;
    cin>>str;
    cout<<"Please enter the checkNum"<<endl;
    while(num>10000)
    {
    	cin>>num;
    	if(num>10000)
    	{
    		cout<<"Enter the wrong num!Make sure the num is under 10000"<<endl;
    	}
    }
	c.initInformation(d,m,y,str,num);
	c.printInformation();
}
