//	Write a program to implement a stack using (a) One Queue.
#include<iostream>
#include<queue>
using namespace std;

class stackonequeue{
	queue<int> q;
	public:
		void push(int x){
			q.push(x);
			for(int i=0;i<q.size()-1;i++){
				q.push(q.front());
				q.pop();
			}
		}
		void pop(){
			if(q.empty())
			cout<<"stack is empty"<<endl;
			else
			q.pop();
		}
		int top(){
			if (q.empty()){
				cout<<"empty stack"<<endl;
				return -1;
			}
			else return q.front();
		}
		int size(){
			return q.size();
		}
		bool empty(){
			return q.empty();
		}
};
int main(){
	stackonequeue s;
	s.push(5);
	s.push(3);
	s.push(1);
	s.push(2);
	s.push(4);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.size()<<endl;
	cout<<s.top()<<endl;
}
