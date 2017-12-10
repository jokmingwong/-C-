#include <cstdio>
#define MAXN (20)
int n, ans;
int a[MAXN][MAXN];
int p[MAXN];
int vis[MAXN];
int tau(){
//计算 tau ，也即逆序对个数
    int ret = 0, i, j;
    for(i = 0; i < n; ++ i){
        for(j = 0; j < i; ++ j){
            ret += p[j] > p[i];
            }
        }
    return ret;
}

void solve(int step){
    int i;
    if(step == n){
    //计算这个排列的贡献
        int now = (tau() & 1) ? -1 : 1;
        int ret = 1;
        for(i = 0; i < n; ++ i){
            ret *= a[i][p[i]];
        }
        ans += now * ret;
        return;
    }
    for(i = 0; i < n; ++ i){
        if(vis[i]) continue;
        vis[i] = 1;
        p[step] = i;
        solve(step + 1);
        vis[i] = 0;
    }
}
int main(){
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i){
        for(j = 0; j < n; ++ j){
            scanf("%d", a[i] + j);
        }
    }
    solve(0);
    printf("%d\n", ans);
    return 0;
}