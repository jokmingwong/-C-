/*****************
 * STL排序算法的应用
 * 
 *****************/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int num;
	cin>>num;
	int a[num];
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
	sort(a,a+num);
	for(int i=num-1;i>=0;i--){
		cout<<a[i]<<' ';
	}
	return 0;
}
