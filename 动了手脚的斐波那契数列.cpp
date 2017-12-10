#include<iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n+1];
    A[0]=0;
    A[1]=1;
    if(1<n && n<8){
    for(int i=2;i<=n;i++){
        A[i]=A[i-1]+A[i-2];
    }
    }
    else if(n>=8){
        A[1]=1;
        A[2]=1;
        A[3]=2;
        A[4]=3;
        A[5]=5;
        A[6]=8;
        A[7]=13;
        for(int i=8;i<=n;i++){
        A[i]=A[i-1] + A[i-2] - A[i-7];
        }
    }
    cout<< A[n] <<endl;
    return 0;

}