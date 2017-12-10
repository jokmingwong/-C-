#include <iostream>  
#include<set>
#include<algorithm>
using namespace std;
set<int>result;  
int main(){
	int n,m;
	cin>>n>>m;
	int A[n],B[m];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<m;i++){
		cin>>B[i];
	}
	sort(A,A+n);
	sort(B,B+m);
	for(int i=0,j=0;i<n&&j<m;){
		if(A[i]>B[j]){
			j++;
		}
		else if(A[i]<B[j]){
			i++;
		}
		else{
			result.insert(A[i]);
			i++;
			j++;
		}
	}
	if(result.empty()){
		cout<<"Intersection set empty!"<<endl;
	}
	else{
		for(set<int>::iterator it=result.begin();it!=result.end();++it){
			cout<<*it<<' ';
		}
	}
	return 0;
} 
