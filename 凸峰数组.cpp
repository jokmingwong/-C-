#include<iostream>
using namespace std;
int main(){
	void getMountain(int A[],int);
	int num;
	cin>>num;
	int A[num];
	for(int t=0;t<num;t++){
		cin>>A[t];
	}
	getMountain(A,num);
	return 0;
}

void getMountain(int A[],int n){
	int t=0,moutain=0;
	for(int i=t;i<(t+3)&&(t+2)<n;i++,t++){
		if(A[t]<A[t+1]&&A[t+1]>A[t+2]){
			moutain++;
			cout<<A[t]<<' '<<A[t+1]<<' '<<A[t+2]<<endl;
		}
	}
	if(moutain==0){cout<<"tan90"<<endl;
 	}
}

