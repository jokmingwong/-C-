#include<iostream>
using namespace std;
int main(){
    //cout<<"Input the circle:"<<endl;
    int num;
    cin>>num;
    int a[num][num];
    int track=1;
    for(int i=0;i<num/2;i++){
        for(int j=i;j<num-i-1;j++)
            a[j][num-i-1]=track++;
        for(int j=num-i-1;j>i;j--)
            a[num-i-1][j]=track++;
        for(int j=num-1-i;j>i;j--)
            a[j][i]=track++;
        for(int j=i;j<=num-i-2;j++)
            a[i][j]=track++;
    }
    if(num%2==1)
        a[num/2][num/2]=track;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
