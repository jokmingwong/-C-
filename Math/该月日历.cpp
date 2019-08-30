#include<stdio.h>
int main()
{
	int day[]={31,28,31,30,31,30,31,31,30,31,30,31};	//一年每月天数
	int i,j,k,year,week;

	printf("\n\t请输入年份：");
	scanf("%6d",&year);			//输入年份
	printf("\n");

	if((year%4==0&&year%100!=0)||(year%400==0))	//若是闰年则2月加1天
		day[1]++;

	week  =   (year+year/4-year/100+year/400)%7;		//计算星期（我修改的）

	for(i=0;i<12;i++)	//12个月
	{
		printf(" ---------%3d月 ----------\n\n",i+1);	//输出打印月份
		printf(" 一  二  三  四  五  六  日\n");		//输出打印星期

		for(k=1;k<week;k++)		//打印每月1日前面的空格
			printf("    ");

		for(j=1;j<=day[i];j++)	//开始打印日期
		{
			printf("%3d ",j);
			if(++week>=8)		//逢7换行
			{
				printf("\n");
				week=week%7;	//一周从新计数
			}
		}
		printf("\n\n");
	}
}

