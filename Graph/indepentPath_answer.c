#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 1005
#define N 1005
int n,m,ans[M],tot=0,head[N];
int vis[N];
struct Node{
	int to,next,id;
}e[M];
struct node{
	int x,y,id;
}a[M],tmp;
void add(int x,int y,int id){
	e[++tot].to=y;e[tot].next=head[x];e[tot].id=id;head[x]=tot;
	e[++tot].to=x;e[tot].next=head[y];e[tot].id=id;head[y]=tot; 
} 
void dfs(int x,int num){
	int i;
//	printf("&&& %d\n",x);
//	for(i=1;i<num;i++)printf("%d ",ans[i]);
//		printf("%d\n",ans[num]);
	if(x==n){
		for(i=1;i<num;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[num]);
		return;
	}
	for(i=head[x];i;i=e[i].next)if(!vis[e[i].to]){
		ans[num+1]=e[i].id;vis[e[i].to]=1;dfs(e[i].to,num+1);vis[e[i].to]=0;
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++)scanf("%d%d%d",&a[i].id,&a[i].x,&a[i].y);
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++){
			if(a[i].id<a[j].id){
				tmp.id=a[i].id;tmp.x=a[i].x;tmp.y=a[i].y;
				a[i].id=a[j].id;a[i].x=a[j].x;a[i].y=a[j].y;
				a[j].id=tmp.id;a[j].x=tmp.x;a[j].y=tmp.y; 
			}
		}
	for(i=1;i<=m;i++){
		add(a[i].x+1,a[i].y+1,a[i].id);
	}
	vis[1]=1;
	dfs(1,0);
	return 0;
}

