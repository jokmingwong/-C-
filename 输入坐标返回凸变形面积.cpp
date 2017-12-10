#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
class Point{
	public:
		float x;
		float y;
		float angle;
};
int main(){
	float getAreaOfPolygon(int,float x[],float y[]);
	void QuickSortRecursive(Point a[], int start, int end);//Decalre quick sort
	int count;
	cin>>count;//输入数据组数
	Point data[count];
	for(int i=0;i<count;i++){
		cin>>data[i].x>>data[i].y;
		data[i].angle=angleWithX(data[i].x,data[i].y);
	}
	QuickSortRecursive(Point a[], 0, count);
	printf("%.3f\n",getAreaOfPolygon(count,X,Y));
	return 0;
}

float angleWithX(float x2,float y2,float x1,float y1){
	return arccos((x2-x1)/sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

void QuickSortRecursive(Point a[], int start, int end) {
    if (start >= end)
        return;
    int mid = a[end].angle;
    int left = start, right = end - 1;
    while (left < right) {
        while (a[left].angle < mid && left < right)
            left++;
        while (a[right].angle >= mid && left < right)
            right--;
        swap(a[left], a[right]);
    }
    if (a[left].angle>= a[end].angle)
        swap(a[left], a[end]);
    else
        left++;
    QuickSortRecursive(a,start,left-1);
    QuickSortRecursive(a,left + 1, end);
}

void QuickSort(Point a[], int len) {
    QuickSortRecursive(a, 0, len - 1);
}





