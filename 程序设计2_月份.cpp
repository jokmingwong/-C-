#include<iostream>
using namespace std;
int main()
{
	int m,n,j,t;
	cin>>m>>n;//j+t=m;2j+4t=n;
	t=(n-2*m)/2;
	j=m-t;
	if(t<0||j<0)cout<<"Wrong number"<<endl;
	else cout<<j<<' '<<t<<endl;
	return 0;
}

