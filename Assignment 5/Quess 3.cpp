//	Write a program to find the middle of a linked list.

#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node(int value){
			data =value;
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
		void middle(){
			if(head==NULL){
				cout<<"List is empty"<<endl;
				return;
			}
			else{
				node *temp=head;
				node *pre=head;
				while(temp->next!=NULL && temp->next->next!=NULL){
					temp=temp->next->next;
					pre=pre->next;
				}
				cout<<"mid element is: "<<pre->data;
			}
		}
};
int main(){
	linklist ll;
	cout<<"Menu:\npress 1: insertion at begining\npress 2: insertion at end\npress 3: display\n"
	<<"press 4: to find mid element\npress 0: exit\n";
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
				ll.middle();
				break;
		}
		cin>>val;
	}while(val!=0);
	return 0;
}
