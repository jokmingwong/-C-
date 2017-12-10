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

    //�����������ⳤ���ַ���
    string str1,str2;
    cin>>str1>>str2;

    //ȥ����λ�ո�
    str1 = trim(str1);
    str2 = trim(str2);
    //��ȡÿ���ַ����ĳ���
    int len1 = str1.length();
    int len2 = str2.length();
    int total = len1 + len2;

    //���ַ�������
    string num1(str1.rbegin(), str1.rend());
    string num2(str2.rbegin(), str2.rend());



    //��̬�������Ŀռ��ַ�����һ��nλ������mλ�����Ϊn+mλ��
    char *result;
    result = (char*)malloc(len1 + len2);

    //��ʼ�����ȫΪ'0'
    int i,j;
    for(i = 0;i < len1 + len2;i++){
        result[i] = '0';
    }

    //����һ�����ֵ�ÿһλ���Եڶ������ֵ�ÿһλ
    for(i = 0;i < len1;i++){

        for(j = 0;j < len2;j++){
            //����洢λ��
            int pos = i + j;
            //��һ�������ĵ�iλ�͵ڶ������ĵ�jλ�˻��ټ���posλ�õ���ֵ
            int tmp = (num1[i] - '0') * (num2[j] - '0') + (result[i + j] - '0');
            //���Ϊ��ֵ��10������
            result[i + j] = tmp % 10 + '0';
            //�����Ľ�λ
            int carry = tmp / 10;

            //����λ����0,�������һλ��һֱ���£�ֱ����λΪ0
            while(carry > 0){
                //��һ��λ�õ�����ֵ���Ͻ�λ�õ�tmp
                tmp = result[pos + 1] - '0' + carry;
                //��һ��λ�õ���tmp��10������
                result[pos + 1] = tmp % 10 + '0';
                //�����λ
                carry = tmp / 10;
                //�ƶ�λ��
                pos++;
            }

        }
    }

    //������������������洢�����ԴӺ�����ǰ�����
    //���ʱ������������0������ʼ������Ժ��������
    //��0���0����Ч
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
