#include<iostream>
using namespace std;
//深知蔡勒公式的伟大
int main()
{
	int zeller(int,int,int);
	int data_num;
	cin>>data_num;
	int a[data_num],result[data_num];
	for(int i=0;i<data_num;i++)
	{
	 int year,month,day;
	 cin>>year>>month>>day;
	 result[i]=zeller(year,month,day);
	}
	for(int m=0;m<data_num;m++)
	{
	 cout<<result[m]<<endl;
	}
	return 0;
}

int zeller(int year,int month, int day)//蔡勒公式
{
	if(month==1||month==2)
	{
		month+=12;
		year-=1;
	}
	int w,y=year%100,c=year/100;
	w=(y+y/4+c/4-2*c+26*(month+1)/10+day-1)%7;
	if(w==0)return 7;
	else if(w<0) return ((w%7+7)%7);
	else return w;
}
	
	
