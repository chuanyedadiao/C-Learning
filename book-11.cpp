#include<iostream>
using namespace std;
#include<string.h>
#include<string>
#include<math.h>

string fun(int n)
{
	string str;
	if(n==0){
		str="零";
		return str;
	} 
	if(n==1){
		str="壹";
		return str;
	} 
	if(n==2){
		str="贰";
		return str;
	} 
	if(n==3){
		str="叁";
		return str;
	} 
	if(n==4){
		str="肆";
		return str;
	} 
	if(n==5){
		str="伍";
		return str;
	} 
	if(n==6){
		str="陆";
		return str;
	} 
	if(n==7){
		str="柒";
		return str;
	} 
	if(n==8){
		str="捌";
		return str;
	} 
	if(n==9){
		str="玖";
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
	cout<<"日期: "<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
	cout<<"姓名："<<name<<" RMB"<<checkNum<<endl;
	if((int)checkNum==10000){
		cout<<"人民币: 壹万"<<endl;
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
	cout<<"人民币: ";
	for(i=0;i<4;i++)
	{
	    if(integer[i]!=0) break;
	}
	if(i==0){
		cout<<fun(integer[0])<<"仟"<<fun(integer[1])<<"佰"<<fun(integer[2])<<"拾";
		cout<<fun(integer[3])<<"元"<<fun(decimal[0])<<"角"<<fun(decimal[1])<<"分"<<endl; 
	}
	if(i==1){
		cout<<fun(integer[1])<<"佰"<<fun(integer[2])<<"拾";
		cout<<fun(integer[3])<<"元"<<fun(decimal[0])<<"角"<<fun(decimal[1])<<"分"<<endl; 
	}
	if(i==2){
		cout<<fun(integer[2])<<"拾";
		cout<<fun(integer[3])<<"元"<<fun(decimal[0])<<"角"<<fun(decimal[1])<<"分"<<endl; 
	}
	if(i==3){
		cout<<fun(integer[3])<<"元"<<fun(decimal[0])<<"角"<<fun(decimal[1])<<"分"<<endl; 
	}
	if(i==4){
		cout<<"零元"<<fun(decimal[0])<<"角"<<fun(decimal[1])<<"分"<<endl; 
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
