#include<iostream>
#include<time.h>
using namespace std;
#define MAX 100
int fibValue[MAX]={0};
 
int Fibonacci(int n,int &count)
{
	count++;
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else return Fibonacci(n-1,count)+Fibonacci(n-2,count);
} 

int FibonacciOP(int n,int &count)
{
	count++;
	if(n==0){
		return 0;
	}
	else if(n==1){
		return 1;
	}
	else {
		int f1=fibValue[n-1];
		int f2=fibValue[n-2];
		if(f1==0){
			f1=FibonacciOP(n-1,count);
			fibValue[n-1]=f1;
		}
		if(f2==0){
			f2=FibonacciOP(n-2,count);
			fibValue[n-2]=f2;
		}
		return f1+f2;
	}
} 

int main()
{
	int n,Total_count1=0,Total_count2=0,num1,num2;
	cin>>n;
	const time_t t1=time(NULL);
	num1=Fibonacci(n,Total_count1);
	const time_t t2=time(NULL);//计算Fibonacci的时间
	const time_t t3=time(NULL);
	num2=FibonacciOP(n,Total_count2);
	const time_t t4=time(NULL);//计算优化之后的时间
	cout<<"Fibonacci Time: "<<t2-t1<<" "<<num1<<" count: "<<Total_count1<<endl;
	cout<<"FibonacciOP Time: "<<t4-t3<<" "<<num2<<" count: "<<Total_count2<<endl;
	return 0;
}
