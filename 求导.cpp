#include<iostream>
#include<cmath>
using namespace std;
void fun(int x1, int x2, int x3, int x4) { 
	if(x4==0){ 
	cout<<(int)(x1*pow(x3, x2))<<endl; 
	} 
	else fun(x1*x2, x2-1, x3, x4-1);
}

int main() { 
	int m, n, p, q; 
	cin>>m>>n>>p>>q; 
	if(q>n) cout<<"0"; 
	else fun(m, n, p, q); 
	return 0; 
} 


