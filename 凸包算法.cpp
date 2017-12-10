//写一个凸包算法玩一下吧 
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
using namespace std;
class point{
	public:
		double x;
		double y;
		double angle;
		void point(double x,double y){
			this->x=x;
			this->y=y;
			this->angle=acos(x/sqrt(pow(x,2)+pow(y,2)));
		}
};

vector<point> PointData;
stack<point> S;
int main(){
	point data;
	while(cin>>data.x>>data.y){
		point_data.push_back(data);
		sort(vector<point>::iterator it=PointData.begin(),vector<point>)end();point.angle);
	}
}
