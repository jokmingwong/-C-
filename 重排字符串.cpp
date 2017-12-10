/***********************
对一个字符串重新排列，字母（包括大小字母）排在前面，数字排在中间，其余字符排在最后。
要求不改变原来字母之间、数字之间以及其余字符之间的相对顺序。

输入

多组数据，第一行一个整数 T(0<T≤10)T(0<T≤10)，表示数据组数。
接下来 TT 行，每行一个字符串（长度 10001000 以内），保证字符都是非空格的可见字符（ASCII 在 (32,126](32,126] 以内）。

输出  对于每组输入，输出答案。
输入样例
2
4$#@fd1$fwe
...^_^...233
输出样例
fdfwe41$#@$
233...^_^...
************************/

#include<iostream>
#include<cstdio>
using namespace std;

void resort(string A){
    char ACase[1000]={};
    char BCase[1000]={};
    char CCase[1000]={};// 
    int d=0,j=0,q=0;
    for(int i=0;A[i]!='\0';i++){
        if((A[i] >= 'a'&& A[i] <= 'z')||(A[i] >= 'A' && A[i] <='Z')){ // 推荐加空格， 这样写太难看了
            ACase[d++]=A[i];
        }
        else if(A[i] >= '0'&& A[i] <= '9'){
            BCase[j++]=A[i];            
        }
        else{
            CCase[q++]=A[i];            
        }
    }
    //print
    for(int t=0;ACase[t]!='\0';t++){
        cout<<ACase[t];
    }
    for(int t=0;BCase[t]!='\0';t++){
        cout<<BCase[t];
    }
    for(int t=0;CCase[t]!='\0';t++){
        cout<<CCase[t];
    }
    cout<<endl;
}

int main(){
    int test;
    cin>>test;
    while(test--){
        string A;   // 推荐用 std::string 不限制长度，可以契合 stl algorithms
        scanf("%s",A);
        resort(A);
    }
    return 0;
}