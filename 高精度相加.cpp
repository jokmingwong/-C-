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
	    int a1Len,b1Len,lenc,i,x;       
	    cin>>a1;   
	    cin>>b1;   
	    a1Len=a1.length();   
	    b1Len=b1.length();   
	   
	    for(i=0;i<=a1Len-1;i++){  
	        a[a1Len-i]=a1[i]-48; ¡¡  
	    }        
	    for (i=0;i<=b1Len-1;i++){  
	        b[b1Len-i]=b1[i]-48;   
	    }   
	    lenc =1;   
	    x=0;   
	      
	   while(lenc <=a1Len || lenc <=b1Len){   
	        c[lenc]=a[lenc]+b[lenc]+x;   
	        x=c[lenc]/10;   
	        c[lenc]=c[lenc]%10;      
	        lenc++;      
	    }  
	      
	    c[lenc]=x;  
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

