//	Write a program to reverse a linked list.
//	new way of thinking
#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node(int value){
			data=value;
			next=NULL;
		}
};
class linklist{
	node *head;
	public:
		linklist(){
			head=NULL;
	}
	void add_begin(int value){
			node *x=new node(value);
			x->next=head;
			head=x;
		}
		void add_end(int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
				return;
			}
			else{
				 node *temp=head;
				 while(temp->next!=NULL){
				 	temp=temp->next;
				 }
				 temp->next=x;
			}
		}
		void display(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
			}
			else{
				node *temp=head;
				while(temp!=NULL){
					cout<<temp->data<<"->";
					temp=temp->next;
				}
				cout<<"NULL"<<endl;
			}
		}
		void reverse(){
			if(head==NULL){
				cout<<"list is empty: "<<endl;
			}
			else{
				node *prev=NULL;
				node *temp=head;
				node *next=NULL;
				while(temp!=NULL){
					next=temp->next;
					temp->next=prev;
					prev=temp;
					temp=next;
				}
				head=prev;
			}
		}
};
int main(){
	linklist ll;
	cout<<"Menu:\npress 1: insertion at begining\npress 2: insertion at end\npress 3: display\n"
	<<"press 4: to reverse the list\npress 0: exit\n";
	int val;
	cin>>val;
	do{
		switch(val){
			case 1:
				cout<<"enter the no. you want to insert: ";
				int x;
				cin>>x;
				ll.add_begin(x);
				break;
			case 2:
				cout<<"enter the no. you want to insert: ";
				cin>>x;
				ll.add_end(x);
				break;
			case 3:
				ll.display();
				break;
			case 4:
				ll.reverse();
				break;
		}
		cin>>val;
	}while(val!=0);
	return 0;
}
