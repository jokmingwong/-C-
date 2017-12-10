#include<iostream>
using namespace std;
int main(){
	void getSimple(int,int);
	int a,b,i;
	long long p;
	cin>>a>>b>>p;
	getSimple(a,b);
	for(i=1;i<=b&&i<=a;i++){
		if(b*i%p==1){
			break;
		}
	}
	cout<<a*i%p<<endl;
	return 0;
}

void getSimple(int t1,int t2){
	int MaxCommon=1;
	if(t1>t2){
		for(int t=2;t<=t2;t++){
			if(t1%t==0&&t2%t==0)MaxCommon=t;
		}
		t1/=MaxCommon;t2/=MaxCommon;
	}
	else if(t1<t2){
		for(int t=2;t<=t1;t++){
			if(t1%t==0&&t2%t==0)MaxCommon=t;
		}
		t1/=MaxCommon;t2/=MaxCommon;
	}
	else{
		t1=1;
		t2=1;
	}
}
