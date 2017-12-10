#include<iostream>
using namespace std;
int main()
{
	int *FindMaximunSubbray(int A[],int,int,int);
	int num;
	cout<<"The num of this array"<<endl;
	cin>>num;
	int A[num];//Create a new array
	for(int i=0;i<n;i++)
	cin>>A[i];
	cout<<FindMaximunSubbray(A,0,n/2,n);
}

int *FindMaxCrossingSubbray(int A[],int low,int mid,int top)
{
	int left_sum=-10000;//Set the number very low
	int sum1=0,flag1;
	for(int i=mid;i>0;i--)
	{
		sum1+=A[i];
		if(sum1>left_sum)
		{
			left_sum=sum1;
			flag1=i;
		}
	}
	
	int right_sum=-10000;//Set the number very low
	int sum2=0,flag2;
	for(int j=0;j<top;j++)
	{
		sum2+=A[j];
		if(sum2right_sum)
		{
			sum2=right_sum;
			flag2=j;
		}
	}
	return ;//Return a point to a new array
}


