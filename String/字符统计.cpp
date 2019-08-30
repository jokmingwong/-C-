#include<iostream>
#include<string> 
using namespace std;
int main(){
	char A[1000]={};
	while(cin>>A){
		int number[10]={0}; 
		int low[26]={0};
		int capital[26]={0}; 
		for(int i=0;A[i]!='\0';i++){
			if('0'<=A[i]&&A[i]<='9'){
				number[A[i]-'0']++;
			}
			else if('a'<=A[i]&&A[i]<='z'){
				low[A[i]-'a']++;
			}
			else if('A'<=A[i]&&A[i]<='Z'){
				capital[A[i]-'A']++;
			}
		}
		for(int i=0;i<10;i++)cout<<number[i]<<' ';
		cout<<endl;
		for(int i=0;i<26;i++)cout<<low[i]<<' ';
		cout<<endl;
		for(int i=0;i<26;i++)cout<<capital[i]<<' ';
		cout<<endl;
	}
	return 0;
}
