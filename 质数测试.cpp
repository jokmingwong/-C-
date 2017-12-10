#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int is_prime(long long int);
	int data_num;
	cin>>data_num;
	long long a[data_num];
	for(int i=0;i<data_num;i++)
	{
	 cin>>a[i];
	}
	for(int m=0;m<data_num;m++)
	{
	 if(is_prime(a[m]))cout<<"Yes"<<endl;
	 else cout<<"No"<<endl;
	}
	return 0;
}

int is_prime(long long int n)
{
	if(n==1)return 0;
	else if(n==2)return 1;
	for(int t=2;t<sqrt(n);t++)
	{
		if(n%t==0)return 0;
	}
	return 1;
}
