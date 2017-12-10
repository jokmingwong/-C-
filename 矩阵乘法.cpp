#include <iostream>  
using namespace std;    

int main(){
	int a,b,c,d;
	int a1,b1,c1,d1;
	cin>>a>>b>>c>>d;
	cin>>a1>>b1>>c1>>d1;
	int a2=a*a1+b*c1;
	int b2=b1*a+b*d1;
	int c2=a1*c+c1*d;
	int d2=b1*c+d1*d;
	cout<<a2<<' '<<b2<<' '<<c2<<' '<<d2<<endl;
	return 0;
}
