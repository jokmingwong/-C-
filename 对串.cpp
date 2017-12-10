#include<iostream>
#include<string>
using namespace std;
int main(){
	string A;
	cin>>A;
	int j;
	for(j=0;j<=A.length()/2-1;j++){
		if(A[j]!=A[A.length()/2+j]){
			cout<<"NO"<<endl;
			break;
		}
	}
	if(j==A.length()/2){
		cout<<"YES"<<endl;
	}

return 0;
}
