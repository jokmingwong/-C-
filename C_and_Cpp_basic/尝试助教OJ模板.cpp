#include<iostream>
using namespace std;
int main()
{
	int test;
	cout<<"Input the times of the test"<<endl;
	cin>>test;
	while(test--)
	{
		int a,b,sum;
		cin>>a>>b;
		sum=a+b;
		cout<<sum<<endl;
	}
	return 0;
}
