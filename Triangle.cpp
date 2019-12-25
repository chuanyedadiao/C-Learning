#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class Triangle{
	private:
		double a,b,c;//三条边长
	public:
	    Triangle(double a = 0,double b = 0,double c = 0){
	    	this->a = a;
	    	this->b = b;
	    	this->c = c;
	    } 
	    double Area()
	    {
	    	double p,area;
	    	p = (a + b + c)/2;
	    	p = p * (p - a) * (p - b) * (p - c);
	    	area = sqrt(p);
	    	return area;
	    }
	    friend double operator+(Triangle t1,Triangle t2);
};

double operator+(Triangle t1,Triangle t2)
{
	double total;
	total = t1.Area() + t2.Area();
	return total;
}

int main()
{
	Triangle t1(2.0,1.0,2.5),t2(1.5,1.3,1.4);
	cout<<"两个三角形面积相加:"<<endl;
	cout<<setprecision(3)<<t1+t2<<endl;
	return 0; 
}



