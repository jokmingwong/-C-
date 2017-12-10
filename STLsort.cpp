#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A;
int main(){
	int number;
	while(cin>>number){
		A.push_back(number);
	}
	sort(A,A+4);
	for(){
		cout<<A[i]<<endl;
	}
	return 0;
}
