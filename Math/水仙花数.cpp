#include<iostream>
using namespace std;
int main(){
	int number;
	bool issxh(int n);
	cin>>number;
	if(issxh(number)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}

bool issxh(int n){
	int a1=n/100;
	int a2=(n-a1*100)/10;
	int a3=n%10;
	if(n==a1*a1*a1+a2*a2*a2+a3*a3*a3){
		return true;
	}
	else return false;
}
