//	Write a program interleave the first half of the queue with second half.
//	Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
#include<iostream>
#include<queue>

using namespace std;

void interleave(queue<int> q){
	int half=q.size()/2;
	queue<int> q1;
	for(int i=0;i<half;i++){
		q1.push(q.front());
		q.pop();
	}
	queue<int> q2;
	while(!q.empty() && !q1.empty()){
		q2.push(q1.front());
		q1.pop();
		q2.push(q.front());
		q.pop();
	}
	
	while(!q2.empty()){
		cout<<q2.front()<<"\t";
		q2.pop();
	}
}

int main(){
	queue<int> q;
	q.push(4);
	q.push(7);
	q.push(11);
	q.push(20);
	q.push(5);
	q.push(9);
	interleave(q);
}
