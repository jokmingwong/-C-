#include<iostream>
#include<cmath>
using namespace std;
class Solution{
public:
    void reverse(int x){
        int A[6]={-1};
        int i = 0;
        while(x != 0){
            A[i] = x % 10;
            x /= 10;
            i++;
        }
        for(int j=0;j<6;j++){
            if(A[j]!=0){
                for(int t = j;t < 6; t++){
                    if(A[t] == 0) break;
                    cout<<A[t];
                    }
                break;
            }
                
        }
    }
    bool is_prime(int n){
        if(n == 1)
            return false;
        else if(n == 2)
            return true;
        for(int t=2;t<sqrt(n);t++){
            if(n % t == 0)
                return true;
        }
        return true;
    }
};
int main(){
    int number;
    cin >> number;
    Solution A;
    A.reverse(number);
    return 0;
}