//	Develop a menu driven program demonstrating the following operations on a Stack using array:
//	(i) push(), (ii) pop(), (iii) isEmpty(), (iv) isFull(), (v) display(), and (vi) peek().

#include<iostream>
using namespace std;
#define max 15
typedef struct{
	int a[max];
	int top;
}stack;
stack init(){
	stack s;
	s.top=-1;
	return s;
}
int isempty(stack s){
	return(s.top==-1);
}
int isfull(stack s){
	return(s.top==max-1);
}
int peek(stack s){
	if (isempty(s))
	cout<<"stack is empty"<<endl;
	else
	return(s.a[s.top]);
}
stack push(stack s, int x){
	if(isfull(s))
	cout<<"stack is full"<<endl;
	else{
		++s.top;
		s.a[s.top]=x;
	}
	return s;
}
stack pop(stack s){
	if (isempty(s))
	cout<<"stack is empty"<<endl;
	else{
		cout<<"popped element is: "<<s.a[s.top]<<endl;
		--s.top;
	}
	return s;
}
void display(stack s){
	int i;
	for(i=s.top;i>=0;i--){
		cout<<s.a[i]<<"\t";
	}
}
int main(){
	stack s;
	s=init();
	int x;
    cout<<"Menu:\n"<<"Press 1: push()\n"<<"Press 2: pop()\n"<<
	"Press 3: isEmpty()\n"<<"Press 4: isFull()\n"<<"Press 5: display()\n"<<
	"Press 6: peek()\n"<<"Press 0: Exit\n";
    cin>>x;
	do{
		switch(x){
			case 1:
				cout<<"enter the value you want to insert: ";
				int value;
				cin>>value;
				s=push(s,value);
				break;
			case 2:
				s=pop(s);
				break;
			case 3:
				if(isempty(s))
				cout<<"stack is empty"<<endl;
				else 
				cout<<"stack is not empty"<<endl;
				break;
			case 4:
				if(isfull(s))
				cout<<"stack is full"<<endl;
				else 
				cout<<"stack is not full"<<endl;
				break;
			case 5:
				if(!isempty(s)){
					cout<<"your stack is: ";
					display(s);
				}
				else
				cout<<"stack is empty"<<endl;
				break;
			case 6:
				cout<<"top element is: ";
				peek(s);
				break;
		}
		cin>>x;
	}while(x!=0);
	return 0;
}
