#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
 	   int getJumpMethod(int);
 	   int t;
 	   cin>>t;
 	   cout<<getJumpMethod(t)<<endl;
 	   }
	return 0;
}

//·ÇµÝ¹éËã·¨
int getJumpMethod(int n){
	int array[n];
	array[0]=1;
	array[1]=2;
	array[2]=4;
	if(n>3){
		for(int i=3;i<n;i++){
			array[i]=array[i-3]+array[i-2]+array[i-1];
		}
	}
	return (array[n-1]);
}
