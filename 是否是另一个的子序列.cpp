#include<iostream>
using namespace std;
int main(){
	int lenA,lenB;
	cin>>lenA>>lenB;
	int flag=0;
	bool judge=true;
	int A[lenA],B[lenB];
	for(int i=0;i<lenA;i++){
		cin>>A[i];
	}
	for(int j=0;j<lenB;j++){
		cin>>B[j];
	}
	for(int j=0;j<lenB;j++){
		if(judge) 
		{
			for(int i=flag; i<lenA ;i++){
				if(B[j]==A[i]){
					flag=i;
					break;
				}
				else if(i==lenA-1&&B[j]!=A[i]){
					judge=false;
					break;
				}
			}
		}
	}
	if(judge)cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
	
	return 0;
	
} 
