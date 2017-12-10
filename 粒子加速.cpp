#include<math.h>
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		float y=asin(x/(1.0+x))*2.33+pow(x+2,3);
		printf("%.2f",y);
	}
	return 0;
}
 
