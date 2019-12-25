#include<iostream>
using namespace std;

void swap(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}

int main()
{
	int a,b;
	cout<<"Please enter two numbers for a and b!"<<endl;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
