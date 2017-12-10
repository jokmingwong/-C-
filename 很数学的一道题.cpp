#include<stdio.h>
#include<cmath>
double factorial(int n){
	if(n==1||n==0)return 1;
	else return n*factorial(n-1);
}

void f(double n){
	double result=0.0000000;
	for(int i=1;i<3000;i++){
		result+=pow(-1,i+1)*double(pow(n,2*i-1))/double((2*i-1)*factorial(2*i-1)); 
	}
	printf("%.3f",result);
}

int main(){
	double n;
	scanf("%lf",&n);
	f(n);
	return 0;
}
