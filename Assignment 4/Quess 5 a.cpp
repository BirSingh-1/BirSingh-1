//	Write a program to implement a queue using (a) One Stack.

#include<iostream>
#include<stack>
using namespace std;

class queueonestack{
	stack<int> s;
	public:
		void enqueue(int x){
			s.push(x);
			s.push(s.top());
			s.pop();
		}
		void dequeue(){
			s.pop();
		}
		void front(){
			cout<<s.top()<<endl;
		}
		void size(){
			cout<<s.size()<<endl; 
		}
		bool empty(){
			return s.empty();
		}
};
int main(){
	queueonestack q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.size();
	q.dequeue();
	q.front();
}
