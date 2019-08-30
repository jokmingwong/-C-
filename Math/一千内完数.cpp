#include<iostream>
using namespace std;
int main()
{
	for(int i=1;i<1000;i++)
	{
		int sum=0;
		for(int t=1;t<i;t++)
		{
			if(i%t==0)sum+=t;
		}
		if(sum==i)cout<<i<<endl;
	}
	return 0;
}
