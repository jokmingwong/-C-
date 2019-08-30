/******************
输入一个十进制整数，将其转为二进制表示。

输入

多组数据，第一行一个整数 T(0<T≤1000)T(0<T≤1000)，表示数据组数。

接下来 TT 行，每行一个十进制整数 x(x∈[0,231−1])x(x∈[0,231−1])。

输出

对于每个输入，输出一行，表示对应的二进制表示。

输入样例：
3
8
1
3
输出样例

1000
1
11
*********************/


#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int x;
        cin>>x;

        if(!x){
            puts("0");
            continue;
        }
        string A;
        int i = 0;
        while(x){
            A[i++] = (x & 1)+'0';
            x >>= 1;
        }
        for(-- i; i >= 0; -- i){
            putchar(A[i]);
        }
        puts("");
    }
    return 0;
}