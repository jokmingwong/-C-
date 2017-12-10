#include<iostream>  
#include<cstdio>  
#include<cstring>
#include<string>  
using namespace std;  
int main(){ 
	int number;
	cin>>number;  
	for(int temp=0;temp<number;temp++){
	    string a1,b1;  
	    int a[100]={0},b[100]={0},c[100]={0};  
	    int lenc,i,x;       
	    cin>>a1;   
	    cin>>b1;    
	   
	    for(int i=0;i<=a1.length()-1;i++){  
	        a[a1.length()-i]=a1[i]-48;
	    }        
	    for (int i=0;i<=b1.length()-1;i++){  
	        b[b1.length()-i]=b1[i]-48;   
	    }   
	    lenc =1;   
	      
	   while(lenc <=a1.length() || lenc <=b1.length())
	   {   
		    if(b[lenc] > a[lenc]){
				c[lenc]=10+b[lenc]-a[lenc];
				a[lenc+1] -= 1;
			}
			else{
				c[lenc]=a[lenc]-b[lenc];
			}
	        lenc++;      
	    }  
	       
	    if (c[lenc]==0){  
	        lenc--;   
	    }         
	    for (i=lenc;i>=1;i--){  
	        cout<<c[i];      
	    }  
	    cout<<endl;
	}
    return 0;  
}  