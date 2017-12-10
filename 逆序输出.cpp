#include<iostream>
using namespace std;
int main(){
	void printReverse(int A[],int );
	int num,temp=0;
	int store[10];
 	for(int i=0;i<10;i++)store[i]=-1;//DEFAULT VALUE 0
		cin>>num;
		while(num/10!=0){
			store[temp]=num%10;
			temp++;
			num=num/10;
		}
		store[temp]=num;//Input the last number
	printReverse(store,10);
	return 0;
}

void printReverse(int A[],int n){
	int t=0,result=0;
	while(A[t]==-1||A[t]==0)t++;
	for(;t>=0&&A[t]!=-1;t--){
		sum+=A[t]*10^;
	}
}
