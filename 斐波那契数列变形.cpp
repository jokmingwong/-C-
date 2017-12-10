#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	double A[101];
	A[1] = 1;
	A[2] = 1;
	A[3] = 1;
	A[4] = 1;
	A[5] = 2;
	A[6] = 3;
	int i;
	for (i = 7;i < 101; i++){
		A[i] = A[i - 3] + A[i - 4] + A[i - 5] + A[i - 6];
	}
	cin>>n;
	cout<< result <<endl;
    return 0;
}
