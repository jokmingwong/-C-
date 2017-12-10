#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int A[3];
	cin>>A[0]>>A[1]>>A[2];
		if(A[0]==A[1]&&A[1]==A[2]){
			cout<<"equilateral triangle!"<<endl;
		} 
		else if(A[0]==A[1]||A[1]==A[2]){
			cout<<"isosceles triangle!"<<endl;
		}
		else if((A[0]+A[1])>A[2]){
			cout<<"regular triangle!"<<endl;
		}
		else{
			cout<<"not a triangle!"<<endl;
		}
	return 0;
}
