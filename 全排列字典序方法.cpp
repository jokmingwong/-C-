#include<iostream>
#include<algorithm>
using namespace std;

void PermutationWithDictionary(int chs[],int n)
{
        sort(chs,chs+n);
        //先对数组的元素进行依次排序
        while(true)
        {
           cout<<chs<<endl;
            int j=n-1;
            int index=0;
            for(j=n-2;j>=0;j--)
            {
                if(chs[j]<chs[j+1])
                {
                    index=j;
                    break;
                    //从右向左找到第一个非递增的元素
                }
                else if(j==0){
                    return;
                }
            }           

            for(j=n-1;j>=0;j--){
                if(chs[j]>chs[index])
                    break;
                    //从右向左找到第一个比非递增元素大的元素
            }
                swap(chs,index,j);
                //交换找到的两个元素
                reverse(chs,index+1);
                //对非递增元素位置后面的数组进行逆序排列
        }       
    }
    void reverse(char chs[],int i){
        int k=i,j=n-1;
        while(k<j){
            swap(chs[k],,chs[j]);
            k++;
            j--;
        }
    }

int main()
{
    int n,m;
    cin>>n>>m;
    int A[n];
    for(int i=1;i<=m;i++)
        A[i-1]=i;
    PermutationWithDictionary(A,n);
    return 0;
}

 