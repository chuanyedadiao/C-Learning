#include<iostream>
#include<cmath>
using namespace std;

//实验6第一题

class Location{
	private:
		double x,y;
	public:
		Location(double a,double b):x(a),y(b){}
		double distance(Location &in);
		friend double Distance(Location &A,Location &B);
};

double Location::distance(Location &in)
{
	double dis;
	dis = (in.x - x) * (in.x - x) + (in.y - y) * (in.y - y);
	dis = sqrt(dis);
	return dis;
}

double Distance(Location &A,Location &B)
{
	double dis;
	dis = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
	dis = sqrt(dis);
	return dis;
}

int main()
{
	Location A(0,0),B(1,1);
	cout<<"Distance1="<<A.distance(B)<<endl;
	cout<<"Distance2="<<Distance(A,B)<<endl;
	return 0;
} 
