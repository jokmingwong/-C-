#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
class Point{
	public:
		double x;
		double y;
};
int main(){
	double getSquare(Point,Point,Point);
	int test;
	cin>>test;
	Point data[test];
	double result=0;
	for(int i=0;i<test;i++){
		cin>>data[i].x>>data[i].y;
		if(i>=2){
			result+=getSquare(data[0],data[i-1],data[i]);
		}
	}
	printf("%.3f\n",result);

	return 0;
}

double getSquare(Point a,Point b,Point c){//利用海伦公式
	double L1=sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
	double L2=sqrt((c.x-a.x)*(c.x-a.x)+(c.y-a.y)*(c.y-a.y));
	double L3=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
	double s=(L1+L2+L3)/2.000;
	double A=sqrt(s*(s-L1)*(s-L2)*(s-L3));
	return A;
}
