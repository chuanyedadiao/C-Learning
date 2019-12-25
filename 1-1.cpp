#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int key,i=0;
	key=rand()%10+1;//产生1-10的随机数 
	while(i!=key)
	{
		cin>>i;
		if(i!=key){
			cout<<"猜数错误请重新猜测！"<<endl;
			system("pause");
			system("cls");
		}
		else{
			cout<<"猜数正确"<<endl;
		}
	}//利用循环进行猜测 
	return 0;
}
