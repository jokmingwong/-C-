/****************
 * 
对于一个字符串，定义如下debug行为：字符串中若先后出现'b'，'u'，'g'字符（不要求彼此相邻），则将这三个字符从字符串中删去。对于长度为n的字符串，从第一个字符开始依次赋予1,2,3...n的权值，
若存在多个"bug"时，优先de掉三个字母权值之和最大的"bug"，再de掉权值之和次之的"bug"，以此类推。
请你写出程序，实现如下功能：对给出的字符串，输出de完所有bug之后的结果。
输入
输入一行字符串，最大长度为100。
输出
输出de完所有"bug"之后的结果。
输入样例1
abcdefghiug
输出样例1
acdefghi
样例解释
debug过程如下：a b cdefghi ug → acdefghi（注：此处空格和黑体字仅帮助理解，非实际输出）
输入样例2
buzubugxgrg
输出样例1
uzgxr
*******************/
#include<iostream>
#include<string>
using namespace std;

int main(){
    string A;
    cin>>A;
    for(int i=0;i<=A.length();i++){
        if(A[i]=='b'){
            for(int j=i;j<=A.length();j++){
                if(A[j]=='u'){
                    for(int y=j;y <=A.length();y++){
                        if(A[y] == 'g'){
                            A[i]='!';
                            A[j]='!';
                            A[y]='!';
                            break;
                        }
                    }
                    break;
                }
            }
        }

    }
    for(int i=0;i<A.length();i++){
        if(A[i]!='!')cout<<A[i]<<endl;
    }
    return 0;
}