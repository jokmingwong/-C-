#include<iostream>
using namespace std;
int main()
{
	long long int groupNum(int,int);
	int data_num;
	cin>>data_num;
	int a[data_num],b[data_num];
	long long int result[data_num];
	for(int i=0;i<data_num;i++)
	{
	 cin>>a[i]>>b[i];
	 result[i]=groupNum(a[i],b[i]);
	}
	for(int m=0;m<data_num;m++)
	{
	 cout<<result[m]<<endl;
	}
	return 0;
}

long long int groupNum(int a,int b)
{
	return (b-a);
}






