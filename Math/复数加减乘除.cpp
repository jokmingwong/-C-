#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class Complex{
	T.r,T.i;
	Complex(T i=0,T y=0){
		this.y=y;this.i=i;
	}
};

template <typename T>
Complex <T> operator+ (const Complex<T>& A,const Complex<T>& B){
	return Complex<T>(A.r+A.r,A.i+A.i);
}

	
	
	
	
	
	
	
int main(){
	int test;
	while(cin>>test){
		int a,b,c,d;
		string op;
		cin>>a>>b>>c>>d>>op;
		complex A(a,b), B(c,d),C;
		if(op=="+"){
			C=A+B;
			cout<<A+B<<endl;
		}
		else if(op=="-"){
			C=A-B;
			cout<<C<<endl;
		}
		else if(op=="*"){
			C=A*B;
			cout<<C<<endl;
		}
		else if(op=="/"){
			C=A/B;
			cout<<C<<endl;
		}
	}
	return 0;
}
