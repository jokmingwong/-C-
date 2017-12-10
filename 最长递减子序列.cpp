#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int test;
	cin>>test;
	int Func(int A[],int B[],int n);
	int PrintMaxSubsequence(int A[],int B[],int,int);
	int A[test],B[test];
	for(int i=0;i<test;i++){
		cin>>A[i];
		B[i]=1;
	}
	int nMaxLen=Func(A,B,test);
	PrintMaxSubsequence(A,B,nMaxLen,test);
	return 0;
}


int Func(int aIn[],int TempTable[],int nLen)
{
    int nMaxLen = 0;
    for(int i = nLen-1; i >= 0; --i) {
        int nMax = 0;
        for(int j = i+1; j < nLen; ++j) {
            if(aIn[j] < aIn[i]) {
                nMax = nMax < TempTable[j] ? TempTable[j] : nMax;
            }
        }
        TempTable[i] = 1+nMax;
        nMaxLen = nMaxLen<TempTable[i] ? TempTable[i] : nMaxLen;
    }

    return nMaxLen;
}

void PrintMaxSubsequence(int aIn[], int TempTable[], int nMaxLen, int nLen)
{
	int result=0;
    for(int i = 0,j=0; i < nLen; ++i) {
        if(TempTable[i] == nMaxLen){
            result++;
            nMaxLen--;
        }
    }
    cout << result<<endl;
}
