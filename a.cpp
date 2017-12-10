#include<iostream>
using namespace std;
int main(){
    int a=1;
    cout<<(a*=2)<<(a+=3)<<"a="<<a<<endl;
    return 0;
    //As you see the result:
    //You will find the calculation of value "a" is running from bottom to top
}