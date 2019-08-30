#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1005
#define M 1005
struct node {
  int id, x, y, w;
} a[M];
int n, m, fa[N], ans = 0, vis[N];

int find(int x) {
  if (fa[x] == x)
    return x;
  else {
    int t = find(fa[x]);
    fa[x] = t;
    return t;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  int i, j;
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &a[i].id, &a[i].x, &a[i].y, &a[i].w);
    a[i].x += 1;
    a[i].y += 1;
  }
  //	for(i=1;i<=m;i++)printf("%d %d\n",a[i].x,a[i].y);
  for (i = 1; i <= m; i++)
    for (j = i + 1; j <= m; j++) {
      if (a[i].w > a[j].w) {
        struct node tmp;
        tmp.id = a[i].id;
        tmp.x = a[i].x;
        tmp.y = a[i].y;
        tmp.w = a[i].w;
        a[i].id = a[j].id;
        a[i].x = a[j].x;
        a[i].y = a[j].y;
        a[i].w = a[j].w;
        a[j].id = tmp.id;
        a[j].x = tmp.x;
        a[j].y = tmp.y;
        a[j].w = tmp.w;
      }
    }
  //	for(i=1;i<=m;i++)printf("%d %d\n",a[i].x,a[i].y);
  for (i = 1; i <= n; i++)
    fa[i] = i;
  for (i = 1; i <= m; i++) {
    int fx = find(a[i].x), fy = find(a[i].y);
    //		printf("%d %d %d %d\n",a[i].x,a[i].y,fx,fy);
    if (fx != fy)
      ans += a[i].w, fa[fx] = fy, vis[a[i].id] = 1;
  }
  printf("%d\n", ans);
  int ok = 0;
  for (i = 1; i <= m; i++)
    if (vis[i]) {
      if (!ok)
        printf("%d", i), ok = 1;
      else
        printf(" %d", i);
    }
  printf("\n");
  return 0;
}
