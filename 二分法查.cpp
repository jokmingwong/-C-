#include<iostream>
using namespace std;
int binSearch(int srcArray[], int n,int key) {  
        int mid = n/ 2;  
        if (key == srcArray[mid]) {  
            return mid;  
        }  
        int start = 0;  
        int end = n - 1;  
        while (start <= end) {  
            mid = (end - start) / 2 + start;  
            if (key < srcArray[mid]) {  
                end = mid - 1;  
            } else if (key > srcArray[mid]) {  
                start = mid + 1;  
            } else {  
                return mid;  
            }  
        }  
        return -1;  
}  

int main(){
	int n,q;
	cin>>n>>q;
	int A[n];
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	while(q--){
		int number;
		cin>>number;
		if(binSearch(A,n,number)!=-1)cout<<binSearch(A,n,number)+1<<endl;
		else cout<<"tan90"<<endl;
	}
	return 0;
}

