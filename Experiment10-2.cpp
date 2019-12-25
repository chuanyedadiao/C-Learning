#include<iostream>
using namespace std;

class Rect{
	protected:
		float width,length,area;
	public:
		Rect(){width = 0;length = 0;area = 0;}
		Rect(float w,float l){
			width = w;
			length = l;
			area = width * length;
		}
		virtual float getArea(){return area;}
		float getLen(){return length;}
		float GetWidth(){return width;}
};

class Cube:public Rect{
	protected:
		float height;
	public:
		Cube(float w,float l,float h):Rect(w,l),height(h){}
		float getArea(){
			area =2*(length * width + height * length + height *width);
			return area; 
		}
};

int main()
{
	Rect *p; 
	Cube c(3.1,4.2,5.3);
	p = &c;
	cout<<"表面积为:"<<p->getArea()<<endl;
	return 0;
}
