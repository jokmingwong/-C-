#include<stdio.h>
int main()
{
	int day[]={31,28,31,30,31,30,31,31,30,31,30,31};	//һ��ÿ������
	int i,j,k,year,week;

	printf("\n\t��������ݣ�");
	scanf("%6d",&year);			//�������
	printf("\n");

	if((year%4==0&&year%100!=0)||(year%400==0))	//����������2�¼�1��
		day[1]++;

	week  =   (year+year/4-year/100+year/400)%7;		//�������ڣ����޸ĵģ�

	for(i=0;i<12;i++)	//12����
	{
		printf(" ---------%3d�� ----------\n\n",i+1);	//�����ӡ�·�
		printf(" һ  ��  ��  ��  ��  ��  ��\n");		//�����ӡ����

		for(k=1;k<week;k++)		//��ӡÿ��1��ǰ��Ŀո�
			printf("    ");

		for(j=1;j<=day[i];j++)	//��ʼ��ӡ����
		{
			printf("%3d ",j);
			if(++week>=8)		//��7����
			{
				printf("\n");
				week=week%7;	//һ�ܴ��¼���
			}
		}
		printf("\n\n");
	}
}

