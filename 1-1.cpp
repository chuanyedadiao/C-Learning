#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int key,i=0;
	key=rand()%10+1;//����1-10������� 
	while(i!=key)
	{
		cin>>i;
		if(i!=key){
			cout<<"�������������²²⣡"<<endl;
			system("pause");
			system("cls");
		}
		else{
			cout<<"������ȷ"<<endl;
		}
	}//����ѭ�����в²� 
	return 0;
}
