/*****************************
题目描述
给定 n,mn,m，输出从 1∼n1∼n 中选择 mm 个数的所有排列。
要求按照字典序输出。

输入:单组数据。

一行，两个空格分隔的整数，分别表示 n,m(1≤m≤n≤8)n,m(1≤m≤n≤8)。

输出:输出若干行，表示答案。

输入样例:3 2
输出样例:
1 2
1 3
2 1
2 3
3 1
3 2

************************************/
#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 110;
int n,m;
int a[MAXN], vis[MAXN];
void dfs(int x){
    if(x==m){
        for(int i = 0;i < m; ++i){
            cout<<a[i]+1<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i = 0;i < n; i++){
        if(vis[i])continue;
        vis[i] = 1;
        a[x] = i;
        dfs(x + 1);
        vis[i] = 0;
    }

}
int main(){
    cin>>n>>m;
    dfs(0);
    return 0;

}