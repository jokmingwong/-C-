#include<stdio.h>
int main()
{
	int a1;
	float b1;
	char a2,b2;
	scanf("<%d><%c>",&a1,&a2);
	if(a2=='C')
 	{
	 b1=9*a1/5.0+32;
	 b2='F';
    }
	else if(a2=='F')
	{
	 b1=(a1-32)*5/9.0;
	 b2='C';
    }
    printf("<%d><%c>=<%.1f><%c>",a1,a2,b1,b2);
    return 0;
}
