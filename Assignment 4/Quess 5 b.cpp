//	Write a program to implement a queue using (a) Two Stack.

#include<iostream>
#include<stack>
using namespace std;

class queuetwostack{
	stack<int> s1,s2;
	public:
		void enqueue(int x){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			s1.push(x);
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}
		}
		void dequeue(){
			s1.pop();
		}
		void front(){
			cout<<s1.top()<<endl;
		}
		void size(){
			cout<<s1.size()<<endl; 
		}
		bool empty(){
			return s1.empty();
		}
};
int main(){
	queuetwostack q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.size();
	q.dequeue();
	q.front();
}
