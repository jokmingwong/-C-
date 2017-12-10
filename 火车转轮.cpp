#include<iostream>
using namespace std;
int main()
{
    char Clockwise[9]={'<','^','>','v','<','^','>','v'};
    char CounterClockwise[9]={'<','v','>','^','<','v','>','^'};
    char begin,end;
    int number;
    cin>>begin>>end;
    cin>>number;
    int flag1=0,flag2=0;
    if(number>4)
    {
        number=number%4;
    }
    for(int i=0;i<4;i++)
    {
        if(begin==Clockwise[i]&&end==Clockwise[i+number])
        {
            flag1=1;
        }
        if(begin==CounterClockwise[i]&&end==CounterClockwise[i+number])
        {
            flag2=1;
        }
    }
    if(flag1==1&&flag2!=1)
    {
        cout<<"cw"<<endl;
    }
    else if(flag1!=1&&flag2==1)
    {
        cout<<"ccw"<<endl;
    }
    else
    {
        cout<<"sleepy jyb"<<endl;
    }
    return 0;
}
