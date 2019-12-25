#include<iostream>
using namespace std;

float Max(float rain[])
{
	int i=0;
	float max=rain[0];
	while(i<12)
	{
		if(rain[i]>max) max=rain[i];
		i++;
	}
	return max;
}

float Min(float rain[])
{
	int i=0;
	float min=rain[0];
	while(i<12)
	{
		if(rain[i]<min) min=rain[i];
		i++;
	}
	return min;
}

int main()
{
	float rain[12];
	for(int i=0;i<12;i++)
	{
		rain[i]=-1.0;
	}//init
	float rainMax,rainMin,rainTotal=0,rainAverage;
	int i=0;
	cout<<"Please enter the height of rain of every month"<<endl;
	for(;i<12;i++)
	{
		while(rain[i]<0){
			cin>>rain[i];
			if(rain[i]<0){
				cout<<"The num is minus.Please enter again!"<<endl;
			}
		}
		rainTotal+=rain[i];
	}
	rainAverage=rainTotal/12;
	rainMax=Max(rain);
	rainMin=Min(rain);
	cout<<"rainTotal: "<<rainTotal<<" rainAverage: "<<rainAverage<<endl;
	cout<<"rainMax: "<<rainMax<<" rainMin: "<<rainMin<<endl;
	return 0; 
}
