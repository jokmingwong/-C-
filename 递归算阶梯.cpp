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

//µÝ¹éËã·¨
int getJumpMethod(int n){
	if(n>3)return (getJumpMethod(n-1)+getJumpMethod(n-2)+getJumpMethod(n-3));
	else if(n==3)return 4;
	else if(n==2)return 2;
	else if(n==1)return 1;
}
