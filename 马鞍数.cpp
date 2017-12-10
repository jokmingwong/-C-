#include<iostream>  
using namespace std;
int main(){  
    int n, l, k,minn, maxx;
	bool flag;  
    cin>>n;
    int A[n][n]; 
    for(int i=0; i<n; i++)  
        for(int j=0; j<n; j++)  
            cin>>A[i][j];  
    flag=false;
    for(int i=0; i<n; i++){  
        for( int j = 0; j <n; j++){  
            minn = A[i][j];  
            for(k = 0 ; k < n; k++){  
                if( minn > A[i][k])  
                    break;  
            }  
            if( k==n){  
                maxx=A[i][j];  
                for(l=0; l<n; l++){  
                    if(maxx<A[l][j])  
                        break;  
                }  
                if(l==n){  
                    cout<<i+1<<" "<<j+1<<" "<<A[i][j]<<endl;  
                    flag=true;  
                }  
            }  
        }  
    }  
    if(!flag)cout<<"NIE"<<endl;  
    return 0;  
}  
