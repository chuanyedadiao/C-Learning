#include<iostream>
#include<iomanip>
using namespace std;
//复数计算器
 
class Plural
{
	private:
		float a;//a为实部 
		float b;//b为虚部 
	public:
		Plural(float a = 0,float b = 0){
			this->a = a;
			this->b = b;
		}
		Plural operator+(Plural &in);
		Plural operator-(Plural &in);
		Plural operator*(Plural &in);
		Plural operator/(Plural &in);
		bool operator==(Plural &in);
		bool operator!=(Plural &in);
		void print()
		{
			cout.precision(2);
			cout.setf(ios::fixed|ios::showpoint);
			if(b < 0)
			{
				cout<<a<<b<<"i"<<endl;
			}
			else{
				cout<<a<<"+"<<b<<"i"<<endl;
			}
		}
};

Plural Plural::operator+(Plural &in)
{
	Plural result;
	result.a = a + in.a;
	result.b = b + in.b;
	return result;
}

Plural Plural::operator-(Plural &in)
{
	Plural result;
	result.a = a - in.a;
	result.b = b - in.b;
	return result;
}

Plural Plural::operator*(Plural &in)
{
	Plural result;
	result.a = a * in.a - b * in.b;
	result.b = a * in.b + in.a *b;
	return result;
} 

Plural Plural::operator/(Plural &in)
{
	Plural result;
	result.a = (a * in.a + b * in.b) / (in.a * in.a + in.b * in.b);
	result.b = (in.a * b - a * in.b) / (in.a * in.a + in.b * in.b);
	return result;
}//除法好像计算有点错误 

bool Plural::operator==(Plural &in)
{
	if(a == in.a && b == in.b)
	{
		return true;
	}
	else return false;
}

bool Plural::operator!=(Plural &in)
{
	if(a == in.a && b == in.b)
	{
		return false;
	}
	else return true;
}

int main()
{
	Plural p1(5.0,4.0),p2(5.0,7.0);
	cout<<"加法:";
	Plural p3 = p1+p2;
	p3.print();
	cout<<"减法:";
	p3 = p1-p2;
	p3.print();
	cout<<"乘法:";
	p3 = p1 * p2;
	p3.print();
	cout<<"除法:";
	p3 = p1 / p2;
	p3.print();
	if(p1 == p2)
	{
		cout<<"p1,p2相等"<<endl;
	}
	if(p1 != p2)
	{
		cout<<"p1,p2不等"<<endl;
	}
	return 0;
} 
