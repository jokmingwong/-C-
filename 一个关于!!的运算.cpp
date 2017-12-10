#include<iostream>
using namespace std;
int main(){
	int f(int,int);
	int n,m;
	cin>>n>>m;
	cout<<f(n,m)<<endl;
	return 0;
}


int f(int a,int b){
	int A[a],B[b];
	long long resultA=1,resultB=1,sumA=0,sumB=0;
	for(int i=1;i<a+1;i++){
		A[i-1]=2*i+1;
		resultA*=A[i-1];
		sumA+=resultA;
	}
	for(int j=1;j<b+1;j++){
		B[j-1]=2*j;
		resultB*=B[j-1];
		sumB+=resultB;
	}
	long long result=(sumA-sumB)%10007;
	if(result < 0)result=((result-sumA+sumB)%10007+10007)%10007;
	return result;
}
