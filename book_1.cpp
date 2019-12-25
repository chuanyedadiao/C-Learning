#include<iostream>
#include<iomanip>
using namespace std;
//���ϵ�һ��ϰ��

class NumDays{
	private:
		int hours;
		float days;
	public:
		NumDays(int h = 0)
		{
			hours = h;
			days = (float)hours / 8;
		}
		int operator+(NumDays &in);
		int operator-(NumDays &in);
		NumDays operator++(int a);//����
		NumDays operator++();//ǰ�� 
		NumDays operator--(int a);//����
		NumDays operator--();//ǰ�� 
		void print()
		{
			cout<<"����ʱ��:";
			cout<<"Сʱ"<<hours<<" ";
			cout<<setprecision(2)<<"����"<<days<<endl; 
		}	
}; 

int NumDays::operator+(NumDays &in)
{
	int total;
	total = hours + in.hours;
	return total;
}

int NumDays::operator-(NumDays &in)
{
	int total;
	total = hours - in.hours;
	return total;
}

NumDays NumDays::operator++(int a)
{
	NumDays temp(hours);
	hours++;
	days = (float)hours / 8;
	return temp;
}

NumDays NumDays::operator++()
{
	hours++;
	days = (float)hours / 8;
	return *this;
}

NumDays NumDays::operator--(int a)
{
	NumDays temp(hours);
	hours--;
	days = (float)hours / 8;
	return temp;
}

NumDays NumDays::operator--()
{
	hours--;
	days = (float)hours / 8;
	return *this;
}

int main()
{
	NumDays d1(11),d2(15);
	NumDays d3(0);
	d1.print();
	d2.print();
	cout<<"������ӹ���ʱ��Ϊ:"<<d1+d2<<endl;
	cout<<"�����������ʱ��Ϊ:"<<d1-d2<<endl;
	cout<<"d1����++��:"<<endl;
	d3 = d1++; 
	cout<<"d3:"<<endl;
	d3.print();
	cout<<"d1:"<<endl;
	d1.print();
	cout<<"d2ǰ��++��:"<<endl;
	d3 = ++d2;
	cout<<"d3:"<<endl;
	d3.print();
	cout<<"d2:"<<endl;
	d2.print();
	cout<<"d1����--��:"<<endl;
	d3 = d1--;
	cout<<"d3:"<<endl;
	d3.print();
	cout<<"d1:"<<endl;
	d1.print();
	cout<<"d2ǰ��--��:"<<endl;
	d3 = --d2;
	cout<<"d3:"<<endl;
	d3.print();
	cout<<"d2:"<<endl;
	d2.print();
	return 0;
}














