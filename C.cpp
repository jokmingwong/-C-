#include<iostream>
using namespace std;
int main(){
int len;
cin>>len;
int A[len],C[len];
for(int i=0;i<len;i++){
	cin>>A[i];
}
int number;
cin>>number;
number=number%len;
for(int j=0,i=number;j<len;j++,i++){
	if(i==len){
		i=0;
	}
	C[i]=A[j];
}
for(int i=0;i<len;i++)cout<<C[i]<<" ";
cout<<endl;
return 0;
}
