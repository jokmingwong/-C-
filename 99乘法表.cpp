#include<stdio.h>
#include<time.h> 
int main(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=i;j++){
			printf("%d*%d=%d ",j,i,i*j);
		}
		printf("\n");
		printf("Time used:%.2f",double(clock())/CLOCKS_PER_SEC);
	}
	return 0;
} 
