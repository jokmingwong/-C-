#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	char c[1000];
	cin.getline(c,1000);
	int temp;
	for(int i=0;;i++){
		if(c[i]=='*'){
			temp=i-1;
			break;
		}
	}
	for(int i=temp;i>=0;i--){
		printf("%c",c[i]);
	}
	return 0;
} 
