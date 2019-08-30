#include<iostream>
using namespace std;
class Animal
{
	public:
	void eat(void){cout<<"We can eat"<<endl;}
	void drink(void){cout<<"We can drink"<<endl;}
	void move(void){cout<<"We can move"<<endl;}
	protected:
		int height;
		int weight;
};

class Dog:public Animal
{
	public:
	void bake(void){cout<<"Dog can bake"<<endl;}
	void run(void){cout<<"Dog can run"<<endl;}
};

int main()
{
	Dog Mike;
	Mike.eat();
	Mike.run();
	Mike.drink();
	return 0;
}
