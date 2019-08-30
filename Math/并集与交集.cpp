//This in an and-set and intersection algorithm
#include<iostream>
using namespace std;
int main(){
	void AndSet(int A[],int,int B[],int);
	int a,b,c,d;
	cout<<"Input the amount of data in the first set"<<endl;
	cin>>a;int A[a];
	cout<<"Now input the data"<<endl;
	for(int temp=0;temp<a;temp++){
		cin>>A[temp];
	}
	cout<<"Input the amount of data in the second set"<<endl;
	cin>>b;int B[b];
	cout<<"Input the data now"<<endl;
	for(int temp=0;temp<b;temp++){
		cin>>B[temp];
	}
	AndSet(A,a,B,b);
	return 0;
	
}

void AndSet(int A[],int SizeOfA,int B[],int SizeOfB){
	//void SORT(int A[],int,int);
	int sum=SizeOfA+SizeOfB;
	int AndSetOfAB[sum];
	for(int m=0;m<sum;m++)AndSetOfAB[m]=-1;//Set default value minus 1
	int i=0,j=0,t=0;
	//SORT(A,0,SizeOfA);
	//SORT(B,0,SizeOfB);
	while(i<SizeOfA||j<SizeOfB){
		if(A[i]>B[j]){
		AndSetOfAB[t]=B[j];
		j++;
		}
		else if(A[i]==B[j]){
		AndSetOfAB[t]=A[i];i++;j++;
		}
		else {
		AndSetOfAB[t]=A[i];
		i++;j++;
		}
		t++;
	}
	for(int temp=0;temp!=0&&temp<sum;t++){
		cout<<AndSetOfAB[t]<<" "<<endl;
	}
}
/*
void SORT(int t[],int p,int r){
	int PARTITION(int T[],int p,int r);
	int q=p+(p-r)/2;
	if(p<r){
		int p=PARTITION(t,p,r);
		SORT(t,p,q-1);
		SORT(t,q+1,r);
	}
}

int PARTITION(int T[],int p,int r){
	void EXCHANGE(int,int);
	int x=T[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(T[j]<x){
			i++;
			EXCHANGE(T[j],T[r]);
		}
	}
	return (i+1);
}

void EXCHANGE(int a,int b){
	int temp=a;
	a=b;
	b=temp;
}
*/
