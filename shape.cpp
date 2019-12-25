#include <iostream>
using namespace std;

class Shape{
	public:
		virtual float Area() = 0;
};

class Rectangle:public Shape{
	private:
		float length,width;
	public:
		Rectangle(float l,float w):length(l),width(w){}
		float Area(){
			return width * length;
		}
};

class Square:public Shape{
	private:
		float edge;
	public:
		Square(float e):edge(e){}
		float Area(){
			return edge * edge;
		}
};

int main()
{
    Shape *p;
    Rectangle r(4.3,5);
    Square s(3.0);
	p = &r;
	cout<<"�����ε����Ϊ:"<<p->Area()<<endl;
	p = &s;
	cout<<"�����ε����Ϊ:"<<p->Area()<<endl;
	return 0;
}
