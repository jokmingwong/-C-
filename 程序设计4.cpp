#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
string trim(string str){
    string buff(str);
    char space = ' ';
    str.assign(buff.begin() + buff.find_first_not_of(space),
            buff.begin() + buff.find_last_not_of(space) + 1);
    return str;
}
int main(){

    //输入两个随意长的字符串
    string str1,str2;
    cin>>str1>>str2;

    //去掉首位空格
    str1 = trim(str1);
    str2 = trim(str2);
    //获取每个字符串的长度
    int len1 = str1.length();
    int len2 = str2.length();
    int total = len1 + len2;

    //将字符串逆序
    string num1(str1.rbegin(), str1.rend());
    string num2(str2.rbegin(), str2.rend());



    //动态分配结果的空间字符串，一个n位数乘以m位数最多为n+m位数
    char *result;
    result = (char*)malloc(len1 + len2);

    //初始化结果全为'0'
    int i,j;
    for(i = 0;i < len1 + len2;i++){
        result[i] = '0';
    }

    //将第一个数字的每一位乘以第二个数字的每一位
    for(i = 0;i < len1;i++){

        for(j = 0;j < len2;j++){
            //结果存储位置
            int pos = i + j;
            //第一个个数的第i位和第二个数的第j位乘积再加上pos位置的真值
            int tmp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j] - '0');
            //结果为真值对10求余数
            result[i + j] = tmp % 10 + '0';
            //产生的进位
            int carry = tmp / 10;

            //当进位大于0,则更新下一位，一直更新，直到进位为0
            while(carry > 0){
                //下一个位置的数真值加上进位得到tmp
                tmp = result[pos + 1] - '0' + carry;
                //下一个位置等于tmp对10求余数
                result[pos + 1] = tmp % 10 + '0';
                //计算进位
                carry = tmp / 10;
                //移动位置
                pos++;
            }

        }
    }

    //输出结果，由于是逆序存储，所以从后面往前面输出
    //输出时，当遇见大于0的数开始输出，以后的数不管
    //是0或非0都有效
    int flag = 0;
    for(i = len1 + len2 - 1;i >= 0;i--){
        if(flag == 1){
            cout<<result[i];
        } else if (result[i] != '0'){
            flag = 1;
            cout<<result[i];
        }
    }
    cout<<endl;

    free(result);
    return 0;
}
