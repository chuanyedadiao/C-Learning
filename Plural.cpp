#include<iostream>
#include<iomanip>
using namespace std;
//����������
 
class Plural
{
	private:
		float a;//aΪʵ�� 
		float b;//bΪ�鲿 
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
}//������������е���� 

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
	cout<<"�ӷ�:";
	Plural p3 = p1+p2;
	p3.print();
	cout<<"����:";
	p3 = p1-p2;
	p3.print();
	cout<<"�˷�:";
	p3 = p1 * p2;
	p3.print();
	cout<<"����:";
	p3 = p1 / p2;
	p3.print();
	if(p1 == p2)
	{
		cout<<"p1,p2���"<<endl;
	}
	if(p1 != p2)
	{
		cout<<"p1,p2����"<<endl;
	}
	return 0;
} 
