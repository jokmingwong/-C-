#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main(){
	int number;
	cin>>number;
	while(number--){
		int n,m;
		cin>>n,m;
		int A[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cin>>A[i][j];
		}
		while(m--){
		string temp;
		cin>>temp;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int H;
		if(temp=="display"){
			cout<<"#"<<int16_t(H)<<endl;
		}
		else if(temp=="getH"){
			H=(pow(x,2)+233)%1773;
		}
		else if(temp=="normalize"){
			if(H!=0)
			
		}
	}
	}
	
}
