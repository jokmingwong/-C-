#include<iostream>
#include<string>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int a,b,c;
        char op1,op2;
        cin>> a >> op1 >> b >> op2 >>c;
        if(op1 == '*'){
            if(op2 == '+'){
                cout<<(a*b+c)<<endl;
            }
            else cout<<(a*b*c)<<endl;
        }
        else{
            if(op2 == '+'){
                    cout<<(a+b+c)<<endl;
                }
                else cout<<(a+b*c)<<endl;
        }
    }
    return 0;
}