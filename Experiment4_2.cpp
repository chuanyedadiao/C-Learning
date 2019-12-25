#include<iostream>
#define Max_F 100
using namespace std;
//���չ���Ա�Ĳ���

class FlightInfo
{
	private:
		string No;//�����
		string StartCity;//��ɵص�
		string EndCity;//����ص�
		string StartDate;//����
		string StartTime;//���ʱ��
		string EndTime;//����ʱ��
		int FirstTicket;//ͷ�Ȳ�ʣ��Ʊ��
		int FirstPrice;//ͷ�Ȳռ۸�
		int SecondTicket;//���ò�ʣ��Ʊ��
		int SecondPrice;//���ü۸�
	public:
		FlightInfo(){}
		FlightInfo(string n,string d){
			No = n;
			StartDate = d;
		}
		FlightInfo(const FlightInfo& in){
			No = in.No;
			StartCity = in.StartCity;
			EndCity = in.EndCity;
			StartDate = in.StartDate;
			StartTime = in.StartTime;
			EndTime = in.EndTime;
			FirstTicket = in.FirstTicket;
			FirstPrice = in.FirstPrice;
            SecondTicket = in.SecondTicket;
            SecondPrice = in.SecondPrice;
		}
		void SetNo(string n){No = n;}
		void SetStartCity(string sc){StartCity = sc;}
		void SetEndCity(string ec){EndCity = ec;}
		void SetStartDate(string sd){StartDate = sd;}
		void SetStartTime(string st){StartTime = st;}
		void SetEndTime(string et){EndTime = et;}
		void SetFirstTicket(int ft){FirstTicket = ft;}
		void SetFirstPrice(int fp){FirstPrice = fp;}
		void SetSecondTicket(int st){SecondTicket = st;}
		void SetSecondPrice(int sp){SecondPrice = sp;}
		int BuyFirstTicket(int n);
		int BuySecondTicket(int n);
		//bool operator==(FlightInfo in);
		string GetNo(){return No;}
		void print();
};

int FlightInfo::BuyFirstTicket(int n)
{
	if(FirstTicket < n)
	{
		cout<<"�ú���ͷ�Ȳ���λ����"<<n<<"��"<<endl;
		return 0;
	}
	else {
		FirstTicket -= n;
		return n * FirstPrice;
	}
}

int FlightInfo::BuySecondTicket(int n)
{
	if(SecondTicket < n)
	{
		cout<<"�ú��ྭ�ò���λ����"<<n<<"��"<<endl;
		return 0;
	}
	else {
		SecondTicket -= n;
		return n * SecondPrice;
	}
}

void FlightInfo::print()
{
	cout<<"�����:"<<No<<endl;
	cout<<"��ɵص�:"<<StartCity<<" ";
	cout<<"����ص�:"<<EndCity<<endl;
	cout<<"�������:"<<StartDate<<" ";
	cout<<"���ʱ��:"<<StartTime<<" ";
	cout<<"����ʱ��:"<<EndTime<<endl;
	cout<<"ͷ�Ȳ�ʣ��Ʊ��:"<<FirstTicket<<" ";
	cout<<"ͷ�Ȳռ۸�:"<<FirstPrice<<endl;
	cout<<"���ò�ʣ��Ʊ��:"<<SecondTicket<<" ";
	cout<<"���òռ۸�:"<<SecondPrice<<endl;
}

class FlightManager{
	private:
		FlightInfo flights[Max_F];
		int flight_count;
	public:
		FlightManager(){flight_count = 0;}
		void AddFlight();
		void DeleteFlight();
		void ChangeFlight();
		void BuyFirstTicket();
		void BuySecondTicket();
		void Display();
};

void FlightManager::AddFlight()
{
	string temp;
	int t;
	cout<<"Please enter No"<<endl;
	cin>>temp;
	flights[flight_count].SetNo(temp);
	cout<<"Please enter StartCity"<<endl;
	cin>>temp;
	flights[flight_count].SetStartCity(temp);
	cout<<"Please enter EndCity"<<endl;
	cin>>temp;
	flights[flight_count].SetEndCity(temp);
	cout<<"Please enter StartDate"<<endl;
	cin>>temp;
	flights[flight_count].SetStartDate(temp);
	cout<<"Please enter StartTime"<<endl;
	cin>>temp;
	flights[flight_count].SetStartTime(temp);
	cout<<"Please enter EndTime"<<endl;
	cin>>temp;
	flights[flight_count].SetEndTime(temp);
	cout<<"Please enter FirstTicket"<<endl;
	cin>>t;
	flights[flight_count].SetFirstTicket(t);
	cout<<"Please enter FirstPrice"<<endl;
	cin>>t;
	flights[flight_count].SetFirstPrice(t);
	cout<<"Please enter SecondTicket"<<endl;
	cin>>t;
	flights[flight_count].SetSecondTicket(t);
	cout<<"Please enter SecondPrice"<<endl;
	cin>>t;
	flights[flight_count].SetSecondPrice(t);
	flight_count++;
}

void FlightManager::DeleteFlight()
{
	string temp;
	int i,j;
	cout<<"Please enter the flight's No you want to delete"<<endl;
	cin>>temp;
	for(i = 0; i < flight_count;i++)
	{
		if(temp == flights[i].GetNo()){ break;}
	}
	if(i == flight_count)
	{
		cout<<"There is no such a flight"<<endl;
		return ;
	}
	for(j = i; j < flight_count-1;j++)
	{
		flights[j] = flights[j+1];
	}
	flight_count--;
}

void FlightManager::ChangeFlight()
{
	string temp,no,t;
	int i,num;
	cout<<"Please enter the flight's No"<<endl;
	cin>>no;
	for(i = 0; i < flight_count;i++)
	{
		if(no == flights[i].GetNo()){ break;}
	}
	if(i == flight_count)
	{
		cout<<"There is no such a flight"<<endl;
		return ;
	}
	cout<<"Please enter the flight information you want to change?"<<endl;
	cin>>temp;
    if(temp == "No")
    {
    	cout<<"Please enter the No"<<endl;
    	cin>>t;
    	flights[i].SetNo(t);
    	return;
    }
    if(temp == "StartCity")
    {
    	cout<<"Please enter the StartCity"<<endl;
    	cin>>t;
    	flights[i].SetStartCity(t);
    	return;
    }
    if(temp == "EndCity")
    {
    	cout<<"Please enter the EndCity"<<endl;
    	cin>>t;
    	flights[i].SetEndCity(t);
    	return;
    }
    if(temp == "StartDate")
    {
    	cout<<"Please enter the StartDate"<<endl;
    	cin>>t;
    	flights[i].SetStartDate(t);
    	return;
    }
    if(temp == "StartTime")
    {
    	cout<<"Please enter the StartTime"<<endl;
    	cin>>t;
    	flights[i].SetStartTime(t);
    	return;
    }
    if(temp == "EndTime")
    {
    	cout<<"Please enter the EndTime"<<endl;
    	cin>>t;
    	flights[i].SetEndTime(t);
    	return;
    }
    if(temp == "FirstTicket")
    {
    	cout<<"Please enter the FirstTicket"<<endl;
    	cin>>num;
    	flights[i].SetFirstTicket(num);
    	return;
    }
    if(temp == "FirstPrice")
    {
    	cout<<"Please enter the FirstPrice"<<endl;
    	cin>>num;
    	flights[i].SetFirstPrice(num);
    	return;
    }
    if(temp == "SecondTicket")
    {
    	cout<<"Please enter the SecondTicket"<<endl;
    	cin>>num;
    	flights[i].SetSecondTicket(num);
    	return;
    }
    if(temp == "SecondPrice")
    {
    	cout<<"Please enter the SecondPrice"<<endl;
    	cin>>num;
    	flights[i].SetSecondPrice(num);
    	return;
    }
}

void FlightManager::BuyFirstTicket()
{
	int num,total;
	string no;
	int i;
	cout<<"Please enter the flight's No"<<endl;
	cin>>no;
	for(i = 0; i < flight_count;i++)
	{
		if(no == flights[i].GetNo()){ break;}
	}
	if(i == flight_count)
	{
		cout<<"There is no such a flight"<<endl;
		return ;
	}
	cout<<"How Many Tickets you want to buy"<<endl;
	cin>>num;
	total = flights[i].BuyFirstTicket(num);
    if(total == 0){return;}
    else{
    	cout<<"The clients should pay"<<total<<endl;
    }
}

void FlightManager::BuySecondTicket()
{
	int num,total;
	string no;
	int i;
	cout<<"Please enter the flight's No"<<endl;
	cin>>no;
	for(i = 0; i < flight_count;i++)
	{
		if(no == flights[i].GetNo()){ break;}
	}
	if(i == flight_count)
	{
		cout<<"There is no such a flight"<<endl;
		return ;
	}
	cout<<"How Many Tickets you want to buy"<<endl;
	cin>>num;
	total = flights[i].BuySecondTicket(num);
    if(total == 0){return;}
    else{
    	cout<<"The clients should pay"<<total<<endl;
    }
}

void FlightManager::Display()
{
	int i;
	for(i = 0;i < flight_count;i++)
	{
		cout<<i+1<<":"<<endl;
		flights[i].print();
		cout<<"\n\n";
	}
}

int main()
{
	FlightManager m;
	cout<<"���Ӻ���"<<endl;
	for(int i = 0;i < 5;i++)
	{
		m.AddFlight();
	}
	system("cls");
	m.Display();
	system("pause");
	system("cls");
	cout<<"ɾ������"<<endl;
	for(int i = 0;i < 2;i++)
	{
		m.DeleteFlight();
		cout<<"\n\n";
	}
	system("pause");
	m.Display();
	system("pause");
	system("cls");
	cout<<"�ı亽����Ϣ"<<endl;
	for(int i = 0;i < 3;i++)
	{
		m.ChangeFlight();
		cout<<"\n\n";
	}
	system("pause");
	m.Display();
	system("pause");
	system("cls");
	cout<<"����ͷ�Ȳյ���Ʊ"<<endl;
	for(int i = 0;i < 4;i++)
	{
		m.BuyFirstTicket();
		cout<<"\n\n";
	}
	system("pause");
	m.Display();
	system("pause");
	system("cls");
    cout<<"���򾭼òյ���Ʊ"<<endl;
	for(int i = 0;i < 4;i++)
	{
		m.BuySecondTicket();
		cout<<"\n\n";
	}
	system("pause");
	m.Display();
	system("pause");
	system("cls");
	return 0;
}
/*��������� AddFlight();
1
�Ͼ�
�Ϻ�
30/3/2019
12.00
13.50
30
800
100
400
2
����
��ɳ
5/7/2019
14.00
15.40
10
1080
90
480
3
��ɳ
�Ͼ�
9/8/2019
23.00
00.10
20
700
90
265
4
֣��
�ɶ�
2/12/2019
17.55
18.45
30
900
50
600
5
����
�ɶ�
3/12/2019
12.55
14.10
12
800
46
500 

ѡ��ɾ������:
2
6

�ı亽����Ϣ:
3
EndCity
����

6
//6������಻����
 
4
FirstTicket
20 

����ͷ�ȲյĻ�Ʊ
5   //����Ϊ���ٵ� 
3   //������ 
1   //����Ϊ���ٵ� 
2   //������ 
4   //����Ϊ���ٵ� 
10  //������
2  //��ʱ��ŵ�"2"�ĺ��಻���� 

���򾭼òյĻ�Ʊ
4
20
5
48  //������ʾ��Ϣ 
1
5
5
2
*/
