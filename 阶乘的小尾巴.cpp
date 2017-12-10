//此题没有好的思路，按照题解的思路默写了一遍
#include<iostream>
#include<stdint.h>
#include<stdio.h>
#define mod (1000000000011)
using namespace std;
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int64_t ret=1;
		int cnt2=0,cnt5=0;
		for(int i=0;i<=n;++i)
		{
			int x=i;
			while(!(x&1))
			{
				++ cnt2;
				x>>=1;
			}
			while(!(x&5))
			{
				++ cnt5;
				x/=5;
			}
			ret=ret*x%mod;
		}
		for(int t=cnt5;t<cnt2;++t)ret=ret*2%mod;
		printf("%01011d\n",ret);
	}
	return 0;
}
