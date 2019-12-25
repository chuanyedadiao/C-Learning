#include<iostream>
using namespace std;

class student{
	private:
		string name;
		int age;
		string num;
		float score;
		static float total_score;
		static int count;
	public:
		student(string n1 = " ",int a = 0,string n2 = " ",float s = 0):name(n1),age(a),num(n2),score(s){}
		student(student &in):name(in.name),age(in.age),num(in.num),score(in.score){}
		~student(){age = 0;}
		void account(float s);
		static float sum(float s);
		static float average(); 
		void print();
};

