#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
using namespace std;

class Point{
	private:
		float x,y;
		string des;
	public:
		Point(){}
		Point(float a,float b,string in):x(a),y(b),des(in){}
		Point(const Point &in):x(in.x),y(in.y),des(in.des){}
		void Set(float a,float b,string in){
			x = a;
			y = b;
			des = in;
		}
		void Print(){
			cout<<x<<" "<<y<<" "<<des<<endl;
		}
};

ifstream& operator>>(ifstream& in,Point& p)
{
	float a,b;
	string buf;
	in>>a>>b>>buf;
	p.Set(a,b,buf);
	return in;
} 

int main()
{
	ifstream in_file;
	in_file.open("a.txt",ios::in);
	if(in_file.fail()){
		in_file.close();
		cout<<"打开文件出错"<<endl;
		exit(0);
	}
	while(in_file.eof() == false)
	{
		Point p;
		in_file>>p;
		p.Print();
	}
	in_file.close();
	return 0; 
}
