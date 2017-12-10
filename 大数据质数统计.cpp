/******************
 * 
统计不大于n的质数的数量。
输入
一个数n(1<=n<=10000000)

输出
输出一行，不大于n的质数的个数

输入样例
100
输出样例
25
**********************/
#include<iostream>
#include<vector>
using namespace std;

int countPrimes(int n) {
    vector<bool> numbers(n + 1, true);
    for (int i = 2; i * i <= n; i++) {
        if (numbers[i]) {
            for (int j = i + i; j <= n; j += i) {
                numbers[j] = false;
            }
        }
    }
    int result=0;
    for (int i = 2; i <= n; i++) {
        if (numbers[i]) {
            result++;
        }
    }
    return result;
}

int main(){
	long long n;
	cin>>n;
	cout<<countPrimes(n)<<endl;
	return 0;
}
