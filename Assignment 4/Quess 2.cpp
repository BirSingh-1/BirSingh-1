//	Develop a menu driven program demonstrating the following operations on Circular
//	Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().

#include<iostream>
using namespace std;
#define max 5
struct queue{
	int arr[max];
	int front,rear;
};
queue init(){
	queue Q;
	Q.front=Q.rear=-1;
	return Q;
}
int isempty(queue Q){
	return (Q.front==Q.rear && Q.rear==-1);
}
int isfull(queue Q){
	return (Q.front==(Q.rear+1)%max);
}
int peek(queue Q){
	return Q.arr[Q.front];
}
queue enqueue(queue Q,int x){
	if(isfull(Q))
	cout<<"queue is full";
	else if(isempty(Q)){
		Q.front=Q.rear=0;
		Q.arr[Q.rear]=x;
	}
	
	else{
		Q.rear=(Q.rear+1)%max;
		Q.arr[Q.rear]=x;
	}
	return Q;
}
queue dequeue(queue Q){
	if(isempty(Q))
	cout<<"queue is empty";
	else
	Q.front=(Q.front+1)%max;
	return Q;
}
void display(queue Q){
	void display(queue q) {
    if (isempty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue contents: ";
    int i = q.front;
    while (true) {
        cout << q.a[i] << " ";
        if (i == q.rear)
            break;
        i = (i + 1) % max;
    }
    cout << endl;
}
int main(){
	queue Q;
    Q=init();
    cout<<"Menu:\npress 1: enqueue()\npress 2: dequeue()\npress 3: isEmpty()\n"
	    <<"press 4: isFull()\npress 5: display()\npress 6: peek()\npress 0: exit\n";
	int val;
	cin>>val;
	do{
		switch(val){
			case 1:
				cout<<"enter the value you want to insert: ";
				int x;
				cin>>x;
				Q=enqueue(Q,x);
				break;
			case 2:
				Q=dequeue(Q);
				break;
			case 3:
				if(isempty(Q))
				cout<<"queue is empty"<<endl;
				else 
				cout<<"queue is not empty"<<endl;
				break;
			case 4:
				if(isfull(Q))
				cout<<"queue is full"<<endl;
				else 
				cout<<"queue is not full"<<endl;
				break;
			case 5:
				if(!isempty(Q)){
					cout<<"your queue is: ";
					display(Q);
				}
				else
				cout<<"queue is empty"<<endl;
				break;
			case 6:
				cout<<"front element is: ";
				cout<<peek(Q);
				break;
		}
		cin>>val;
	}while(val!=0);
}
