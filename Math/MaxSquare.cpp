/*  @author=������ 
 *	������ܣ�ͨ����������������������������Щ�������ɵ����͹������� 
 *	�����㷨�����ݽṹ��͹�������graham�㷨����˳������������㷨�����׹�ʽ��vector���� 
 */ 

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
//�������� 
class POINT { 
public:
	int x; 
	int y; 
	};
typedef vector<POINT> pointArray;

//�ж�������(������)�Ƿ����
//const˵�������ڲ����޸Ĳ��� 
bool operator==(const POINT &pt1, const POINT &pt2) {
    return (pt1.x == pt2.x && pt1.y == pt2.y);
}
// �Ƚ���������pt1��pt2�ֱ���x������(1, 0)�ļн�
bool CompareVector(const POINT &pt1, const POINT &pt2) {
    //��������ģ
    float m1 = sqrt((float)(pt1.x * pt1.x + pt1.y * pt1.y));
    float m2 = sqrt((float)(pt2.x * pt2.x + pt2.y * pt2.y));

    float cos1 = pt1.x / m1, cos2 = pt2.x / m2;
    return (cos1 > cos2 || (cos1 == cos2 && m1 < m2));
}
//����͹��
void CalcConvexHull(pointArray &tempVec) {
    //�㼯������Ӧ��3���㣬���ܹ��ɶ����
    if (tempVec.size() < 3) {
        return;
    }
    //���һ���
    POINT pointBase = tempVec.front(); //����1����Ԥ��Ϊ��С��
    for (pointArray::iterator i = tempVec.begin() + 1; i != tempVec.end(); ++i) {
        //�����ǰ���yֵС����С�㣬��yֵ��ȣ�xֵ��С
        if (i->y < pointBase.y || (i->y == pointBase.y && i->x > pointBase.x)) {
            //����ǰ����Ϊ��С��
            pointBase = *i;
        }
    }
    //�������������㹹�ɵ�����
    for (pointArray::iterator i = tempVec.begin(); i != tempVec.end();) {
        //�ų��������ͬ�ĵ㣬����������������г��ֳ�0����
        if (*i == pointBase) {
            i = tempVec.erase(i);//erase�ڵĲ����ǵ����� 
        }
        else {
            //�����ɻ��㵽Ŀ��㣬�൱�ڰѻ��㵱��(0,0)������������� 
            i->x -= pointBase.x, i->y -= pointBase.y;
            ++i;
        }
    }
    //���������������֮��ļн�����,sort()��������Լ�һ��bool������������
    sort(tempVec.begin(), tempVec.end(), &CompareVector); 
    //ɾ����ͬ������
    tempVec.erase(unique(tempVec.begin(), tempVec.end()), tempVec.end());
    //������������β��������������
    for (pointArray::reverse_iterator ri = tempVec.rbegin();
        ri != tempVec.rend() - 1; ++ri) {
        pointArray::reverse_iterator riNext = ri + 1;
        //�������㹫ʽ
        ri->x -= riNext->x, ri->y -= riNext->y;
    }
    //����ɾ������͹���ϵ�����
    //�ӻ������һ���㿪ʼ���� 
    for (pointArray::iterator i = tempVec.begin() + 1; i != tempVec.end(); ++i) {
        //����ɾ����ת�����෴��������ʹ������ж���ת����
        for (pointArray::iterator iLast = i - 1; iLast != tempVec.begin();) {
            int v1 = i->x * iLast->y, v2 = i->y * iLast->x;
            //������С��0������û��������ת
            //����������0�������жϷ����Ƿ�����
            if (v1 < v2 || (v1 == v2 && i->x * iLast->x > 0 &&
                i->y * iLast->y > 0)) {
                    break;
            }
            //ɾ��ǰһ������������µ�ǰ��������ǰ���������β����
            //���������μ��㹫ʽ
            i->x += iLast->x, i->y += iLast->y;
            iLast = (i = tempVec.erase(iLast)) - 1;
        }
    }
    //��������β���������������ۼӣ����������
    tempVec.front().x += pointBase.x, tempVec.front().y += pointBase.y;
    for (pointArray::iterator i = tempVec.begin() + 1; i != tempVec.end(); ++i) {
        i->x += (i - 1)->x, i->y += (i - 1)->y;
    }
    //��ӻ��㣬ȫ����͹���������
    tempVec.push_back(pointBase);
}

double CalSquare(pointArray &tempVec){
	double Square=0.0;
	for(pointArray::iterator it=tempVec.begin()+2;it!=tempVec.end();++it){
		//���ú��׹�ʽ
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
    cout << "The point on convex hull��"<<endl;
    for (pointArray::iterator i = tempVec.begin(); i != tempVec.end(); ++i) {
        cout << i->x << ", " << i->y << endl;
    }
    cout<<"The MaxSquare is:"<<CalSquare(tempVec)<<endl;
    return 0;
}

