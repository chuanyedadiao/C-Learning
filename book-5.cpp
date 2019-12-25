#include<iostream>
using namespace std;


int main()
{
	char answer[20]={'B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A'};
	char student_answer[20];
	int wrongNumber=0,wrongQuestion[20]={0};
	int k=0;
	cout<<"Please enter the answer of the student"<<endl;
	for(int i=0;i<20;i++)
	{
		cin>>student_answer[i];
		if(student_answer[i]!=answer[i]){
			wrongNumber++;
			wrongQuestion[k]=i+1;
			k++;
		}
	}
	if(wrongNumber>8){
		cout<<"Fail"<<" wrongNumber is:"<<wrongNumber<<endl;
		cout<<"They are:"<<endl;
		for(int j=0;j<k;j++)
		{
		    cout<<"No."<<wrongQuestion[j]<<endl;
		}
	}
	else 
	{
	    cout<<"PASS"<<" wrongNumber is:"<<wrongNumber<<endl;
	    if(wrongNumber!=0)
	    {
	        cout<<"They are:"<<endl;
			for(int j=0;j<k;j++)
			{
			    cout<<"No."<<wrongQuestion[j]<<endl;
			}	
	    }
	}
	return 0;
}
