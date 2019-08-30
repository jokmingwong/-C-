/*  @author=黄钰铭 
 *	程序介绍：通过输入至少三个点的坐标求出由这些点所构成的最大凸边形面积 
 *	基本算法与数据结构：凸包问题的graham算法，求顺序多边形面积的算法，海伦公式，vector容器 
 */ 

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//定义向量 
class POINT { 
public:
	int x; 
	int y; 
	};
typedef vector<POINT> pointArray;

//判断两个点(或向量)是否相等
//const说明函数内不能修改参数 
bool operator==(const POINT &pt1, const POINT &pt2) {
    return (pt1.x == pt2.x && pt1.y == pt2.y);
}
// 比较两个向量pt1和pt2分别与x轴向量(1, 0)的夹角
bool CompareVector(const POINT &pt1, const POINT &pt2) {
    //求向量的模
    float m1 = sqrt((float)(pt1.x * pt1.x + pt1.y * pt1.y));
    float m2 = sqrt((float)(pt2.x * pt2.x + pt2.y * pt2.y));

    float cos1 = pt1.x / m1, cos2 = pt2.x / m2;
    return (cos1 > cos2 || (cos1 == cos2 && m1 < m2));
}
//计算凸包
void CalcConvexHull(pointArray &tempVec) {
    //点集中至少应有3个点，才能构成多边形
    if (tempVec.size() < 3) {
        return;
    }
    //查找基点
    POINT pointBase = tempVec.front(); //将第1个点预设为最小点
    for (pointArray::iterator i = tempVec.begin() + 1; i != tempVec.end(); ++i) {
        //如果当前点的y值小于最小点，或y值相等，x值较小
        if (i->y < pointBase.y || (i->y == pointBase.y && i->x > pointBase.x)) {
            //将当前点作为最小点
            pointBase = *i;
        }
    }
    //计算出各点与基点构成的向量
    for (pointArray::iterator i = tempVec.begin(); i != tempVec.end();) {
        //排除与基点相同的点，避免后面的排序计算中出现除0错误
        if (*i == pointBase) {
            i = tempVec.erase(i);//erase内的参数是迭代器 
        }
        else {
            //方向由基点到目标点，相当于把基点当作(0,0)将所有坐标更新 
            i->x -= pointBase.x, i->y -= pointBase.y;
            ++i;
        }
    }
    //按各向量与横坐标之间的夹角排序,sort()后参数可以加一个bool变量进行排序
    sort(tempVec.begin(), tempVec.end(), &CompareVector); 
    //删除相同的向量
    tempVec.erase(unique(tempVec.begin(), tempVec.end()), tempVec.end());
    //倒序计算更新首尾依次相联的向量
    for (pointArray::reverse_iterator ri = tempVec.rbegin();
        ri != tempVec.rend() - 1; ++ri) {
        pointArray::reverse_iterator riNext = ri + 1;
        //向量计算公式
        ri->x -= riNext->x, ri->y -= riNext->y;
    }
    //依次删除不在凸包上的向量
    //从基点的下一个点开始遍历 
    for (pointArray::iterator i = tempVec.begin() + 1; i != tempVec.end(); ++i) {
        //回溯删除旋转方向相反的向量，使用外积判断旋转方向
        for (pointArray::iterator iLast = i - 1; iLast != tempVec.begin();) {
            int v1 = i->x * iLast->y, v2 = i->y * iLast->x;
            //如果叉积小于0，则无没有逆向旋转
            //如果叉积等于0，还需判断方向是否相逆
            if (v1 < v2 || (v1 == v2 && i->x * iLast->x > 0 &&
                i->y * iLast->y > 0)) {
                    break;
            }
            //删除前一个向量后，需更新当前向量，与前面的向量首尾相连
            //向量三角形计算公式
            i->x += iLast->x, i->y += iLast->y;
            iLast = (i = tempVec.erase(iLast)) - 1;
        }
    }
    //将所有首尾相连的向量依次累加，换算成坐标
    tempVec.front().x += pointBase.x, tempVec.front().y += pointBase.y;
    for (pointArray::iterator i = tempVec.begin() + 1; i != tempVec.end(); ++i) {
        i->x += (i - 1)->x, i->y += (i - 1)->y;
    }
    //添加基点，全部的凸包计算完成
    tempVec.push_back(pointBase);
}

double CalSquare(pointArray &tempVec){
	double Square=0.0;
	for(pointArray::iterator it=tempVec.begin()+2;it!=tempVec.end();++it){
		//利用海伦公式
		double a=sqrt(pow((it-1)->x-(it-2)->x,2)+pow((it-1)->y-(it-2)->y,2));
		double b=sqrt(pow((it)->x-(it-1)->x,2)+pow((it)->y-(it-1)->y,2));
		double c=sqrt(pow((it)->x-(it-2)->x,2)+pow((it)->y-(it-2)->y,2));
		double s=(a+b+c)/2.0;
		Square+=sqrt(s*(s-a)*(s-b)*(s-c));
	}
	return Square;
}

int main() {
	int num;
    pointArray tempVec, vecCH;
    do{
    cout<<"Input the number of point you want:"<<endl;
    cin>>num;
	}while(num<3);
	string c;
    for (int i = 0; i < num; ++i) {
    	if(i==0)c="st";
    	else if(i==1)c=="nd";
    	else if(i==2)c=="rd";
    	else c=="th";
    	cout<<"Please input the "<<i+1<<c<<" value of point's x and y"<<endl; 
        POINT ptIn;
        cin>>ptIn.x>>ptIn.y;
        tempVec.push_back(ptIn);
        cout <<"("<<ptIn.x << "," << ptIn.y << ")has already been in."<<endl;
    }
    CalcConvexHull(tempVec);
    cout << "The point on convex hull："<<endl;
    for (pointArray::iterator i = tempVec.begin(); i != tempVec.end(); ++i) {
        cout << i->x << ", " << i->y << endl;
    }
    cout<<"The MaxSquare is:"<<CalSquare(tempVec)<<endl;
    return 0;
}

