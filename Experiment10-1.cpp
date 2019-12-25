#include<iostream>
using namespace std;

class Number{
	private:
		int value;
	public:
		Number(int i = 0){value = i;}
		Number(const Number &in):value(in.value){}
		void operator+=(Number &in);
	    Number operator++();	
	    Number operator++(int a);
	    Number operator--();
	    Number operator--(int a);
	    int getValue(){return value;}
};

void Number::operator+=(Number &in)
{
	value += in.value;
}

Number Number::operator++()
{
	value++;
	return *this;
}

Number Number::operator++(int a)
{
	Number temp(value);
	value++;
	return temp;
}

Number Number::operator--()
{
	value--;
	return *this;
}

Number Number::operator--(int a)
{
	Number temp(value);
	value--;
	return temp;
}

int main()
{
	Number a(2),b(5);
	Number c;
	a += b;
	cout<<"a += b 之后a为:"<<a.getValue()<<endl;
	c = ++a;
	cout<<"c = ++a 之后c为:"<<c.getValue()<<"  a为:"<<a.getValue()<<endl;
	c = a++;
	cout<<"c = a++ 之后c为:"<<c.getValue()<<"  a为:"<<a.getValue()<<endl;
    c = --b;
	cout<<"c = --b 之后c为:"<<c.getValue()<<"  b为:"<<b.getValue()<<endl;
	c = b--;
	cout<<"c = b-- 之后c为:"<<c.getValue()<<"  b为:"<<b.getValue()<<endl;
	return 0;
}


