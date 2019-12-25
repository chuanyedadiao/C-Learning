#include<iostream>
using namespace std;

class Date{
	private:
		int day,month,year;
	public:
		Date(int d,int m,int y):day(d),month(m),year(y){}
		Date operator++(int a);//后置++ 
		void print()
		{
			cout<<day<<"/"<<month<<"/"<<year<<endl;
		}
};

Date Date::operator++(int a)
{
	day++;
	switch(month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:{
			if(day > 31)
			{
				month++;
				day = 1;
			}
			break;
		}
		case 2:{
			if(day > 28)
			{
				month++;
				day = 1;
			}
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:{
			if(day > 30)
			{
				month++;
				day = 1;
			}
			break;
		}
		case 12:{
			if(day > 31)
			{
				year ++;
				month = 1;
				day = 1;
			}
			break;
		}
	}
	return *this;
}

int main()
{
	Date d1(28,2,2018),d2(31,5,2018),d3(31,12,2018);
	cout<<"初始:"<<endl;
	cout<<"d1:";
	d1.print();
	cout<<"d2:";
	d2.print();
	cout<<"d3:";
	d3.print();
	cout<<"d1++后:"<<endl;
	d1++;
	d1.print();
	cout<<"d2++后:"<<endl;
	d2++;
	d2.print();
	cout<<"d3++后:"<<endl;
	d3++;
	d3.print();
	return 0;
}
















