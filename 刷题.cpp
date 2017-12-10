#include<iostream>
using namespace std;
int main()
{
    long int q,temp;
	int data_num;
	cin>>data_num;
	long int data[data_num],result[data_num];
	for(int i=0;i<data_num;i++)
	{
		int sum=0;//内部变量
		cin >> data[i];
		do
		{
	        temp=data[i]%10;
	        q= (data[i]-temp)/10;
	        sum+=temp;
	        if (q==0)break;
         	data[i]= q;
	    }
	    while(true);
	    result[i]=sum;
	}
	for(int m=0;m<data_num;m++)
	{
		cout<<result[m]<<endl;
	}
    return 0;
}
