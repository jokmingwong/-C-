#include<iostream>

#define MAXN (20)

using namespace std;

int det(int a[][MAXN], int n){
    if(n == 1){
        return a[0][0];
    }
    int ret = 0, now = 1, i, j, k;
    int b[MAXN][MAXN];
    //���� 0 ��չ��������ö����һ�е�Ԫ�� a[0][k]
    for(k = 0; k < n; ++ k){
    //��ɾ������ 0 �У��� k ��֮��ľ������ b[][] ��
    for(i = 1; i < n; ++ i){
        int sit = 0;
        for(j = 0; j < n; ++ j){
            if(j == k) continue;
            b[i - 1][sit ++] = a[i][j];
        }
    }
    //����Ԫ�� a[0][k] �Ĺ���
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
