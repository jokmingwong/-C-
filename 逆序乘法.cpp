#include<iostream>
using namespace std;
int getReverse(int n){
	int i,m,converse;
	i=n;converse=0;
	while(i>0){
	m=i%10;
	i/=10;
	converse=m+converse*10;
	}
	return converse;
}

int main(){
	int getReverse(int);
	int a,b;
	cin>>a>>b;
	cout<<getReverse(a)*getReverse(b)<<endl;
	return 0;
}

