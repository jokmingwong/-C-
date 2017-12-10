#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    if(n%10!=0)
        cout<<n%10<<(n-n%10)/10%10<<n/100<<endl;
    else cout<<n/10<<n/100<<endl;
    return 0;
}
