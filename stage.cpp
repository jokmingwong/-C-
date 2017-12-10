#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int StageSum(int stage);
	int StageDay(int);
	int day;
	cin>>day;
	int stage=int(sqrt(2*day+0.25)-0.5);
	int result=StageSum(stage)+(day-StageDay(stage))*(stage+1);
	cout<<result<<endl;
	
	return 0;
}
int StageSum(int stage){
	int sum=0;
	for(int i=1,n=1;n<=stage;n++,i++){
		sum+=i*n;
	}
	return sum;
}

int StageDay(int stage){
	int stageDay=stage*(1+stage)/2;
	return stageDay;
}
