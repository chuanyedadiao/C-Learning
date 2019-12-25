#include<iostream>
using namespace std;
#define Max 100

void SwapSort(int *p,int n)
{
	int i,j;
	int t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j+1]<p[j])
			{
				t=p[j+1];
				p[j+1]=p[j];
				p[j]=t;
			}
		}
	}
}//ц╟ещ 

int main()
{
	int num[Max]={-1};
	int *p;
	p=num;
    int n;
    cout<<"Please enter n"<<endl;
    cin>>n;
    cout<<"Please enter the value of the array"<<endl;
    for(int i=0;i<n;i++)
    {
    	cin>>*(p+i);
    }
    SwapSort(p,n);
    p=num;
    if(n%2==1){
    	int site=n/2;
    	cout<<"The middle num is: "<<p[site]<<endl;
    }
    if(n%2==0){
    	float middle;
    	middle=(float)(p[n/2-1]+p[n/2])/2;
    	cout<<"The middle num is: "<<middle<<endl;
    }
    return 0;
}
