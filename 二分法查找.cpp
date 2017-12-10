#include<iostream>
using namespace std;
void searchIndex(int A[],int begin,int end,int goal){
		if(begin<=end){
			int temp=(begin+end)/2;
			if(A[temp]>goal){
				begin=temp;
				searchIndex(A,begin,end,goal);
			}
			else if(A[temp]<goal){
				end=temp;
				searchIndex(A,begin,end,goal);
			}
			else{
				cout<<temp<<endl;
			}
		}
		else{
		cout<<"tan90"<<endl;
	}
}
int main(){
	int n,q;
	cin>>n>>q;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	while(q--){
		int number;
		cin>>number;
		searchIndex(A,0,n,number);
	}
	return 0;

} 
