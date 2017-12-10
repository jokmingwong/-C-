/***************************
题目描述

给出一个数字 nn，将 1∼n(n+1)21∼n(n+1)2 填入指定结构的等腰直角三角形。详细要求请观察样例。

输入

多组数据，第一行一个整数 T(0<T≤100)T(0<T≤100)，表示数据组数。
接下来 TT 行，每行一个 n(1≤n≤100)n(1≤n≤100)。

输出
对于每个输入，输出一个等腰直角三角形，每行的多个数字用空格隔开，行末空格不影响评测。
两组输入之间不需要多余的空行。

输入样例
2
5
3
输出样例

1 3 4 10 11
2 5 9 12
6 8 13
7 14
15

1 3 4
2 5
6
***************************/
#include<iostream>
using namespace std;

void showTriangle(int q){
    int track=1;
    int A[q][q];
    A[0][0]=1;
    //填表
    if(q==1){
        cout<<A[0][0]<<endl;
        return;
    }
    else{
        track++;
        for(int rowNumber=1;rowNumber<q;rowNumber++){
            //奇数列
            if((rowNumber+2)%2==1){
                for(int i=0;i<=rowNumber;i++){
                    A[rowNumber-i][i]=track++;
                }
            }
            //偶数列
            else{
                for(int i=0;i<=rowNumber;i++){
                    A[i][rowNumber-i]=track++;
                }
            }
        }
    }
    //展示
    for(int i=0;i<q;i++){
        for(int j=0;j<q-i;j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }

}

int main(){
    int dataNum;
    cin>>dataNum;
    while(dataNum--){
        int q;
        cin>>q;
        showTriangle(q);
    }
    return 0;
}