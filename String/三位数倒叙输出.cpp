#include<iostream>
#include<cstring>
using namespace std;

int reverse(int a){
	int col[3];
 	col[0]=a%10;
 	col[1]=(a%100)/10;
 	col[2]=a/100;
    int result=100*col[0]+10*col[1]+col[2];
	return result;
}

int main(){
	int n,i=0;
	while(cin>>n) {
		cout<<reverse(n)<<endl;
	}	
	return 0;
}


