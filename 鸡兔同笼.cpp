#include<iostream>
using namespace std;

class Solution{
    public:
    void findResult(int m,int n){
        int i,j;
        i = (n -2*m)/2;
        j = (4*m -n)/2;
        if(m<0||n<0||n<2*m||i<0||j<0||(n-2*m)%2!=0||(4*m-n)%1!=0){
            cout << "Wrong number" <<endl;
        }
        else{
            cout << j <<' '<<i <<endl;
        }
    }
};
int main(){
    int m,n;
    cin>> m >> n;
    Solution A;
    A.findResult(m,n);
    return 0;
}