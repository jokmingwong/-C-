#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
vector <long long> A;

int main(){
    long long S;
    cin>>S;
    for(long long i=1;i<=sqrt(S);i++){
        if(S % i ==0){
            A.push_back(2*(i+(S/i)));
        }
    }
    sort(A.begin(),A.end());
    cout<< *(A.begin())<<endl;
    return 0;
}