

#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
vector<int>A;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int>::iterator L=A.begin();
	for(int i=0;i<pow(2,k)-1;i++){
		A.push_back(2*n);
		A.push_back(3*n+1);
		n=A[i];
	}
	sort(A.begin(),A.end());
	int ans=unique(A.begin(),A.end())-A.begin();
	for(int t=0;t<ans;t++){
		cout<<A[t]<<" ";
	}
	return 0;
}
