#include<iostream>

#define MAXN (20)

using namespace std;

int det(int a[][MAXN], int n){
    if(n == 1){
        return a[0][0];
    }
    int ret = 0, now = 1, i, j, k;
    int b[MAXN][MAXN];
    //按第 0 行展开，我们枚举这一行的元素 a[0][k]
    for(k = 0; k < n; ++ k){
    //将删除掉第 0 行，第 k 列之后的矩阵存入 b[][] 中
    for(i = 1; i < n; ++ i){
        int sit = 0;
        for(j = 0; j < n; ++ j){
            if(j == k) continue;
            b[i - 1][sit ++] = a[i][j];
        }
    }
    //计算元素 a[0][k] 的贡献
    ret += now * a[0][k] * det(b, n - 1);
    now *= -1;
    }
    return ret;
}
int main(){
    int n, i, j;
    int a[MAXN][MAXN];
    cin>>n;
    for(i = 0; i < n; ++ i){
        for(j = 0; j < n; ++ j){
            cin>>a[i][j];
            }
        }
    cout<<det(a, n)<<endl;
    return 0;
}
