//	Write a program to find size of  (i) Doubly Linked List.  (ii) Circular Linked List.

#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node *prev;
		node(int value){
			data =value;
			next=NULL;
			prev=NULL;
		}
};
class circularlist{
	node *head;
	public:
		circularlist(){
			head=NULL;
		}
		void add(int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
				x->next=head;
			}
			else{
				node *temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=x;
				x->next=head;
			}
		}
		void size(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
			}
			else{
				node *temp=head;
				int count1=0;
				do{
					count1++;
					temp=temp->next;
				}while(temp!=head);
				cout<<"size of doubly list is: "<<count1<<endl;
			}
		}
};
class doublylist{
	node *head;
	public:
		doublylist(){
			head=NULL;
		}
		void add(int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
			}
			else{
				node *temp=head;
				node *pre=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=x;
				x->prev=temp;
			}
		}
		void size(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
			}
			else{
				node *temp=head;
				int count=0;
				do{
					count++;
					temp=temp->next;
				}while(temp!=NULL);
				cout<<"size of doubly list is: "<<count<<endl;
			}
		}
};
int main(){
	cout<<"Menu:\npress 1: doubly linklist\npress 2: circular list\n";
	int x;
	cin>>x;
	switch(x){
		case 1:{
			doublylist ll;
			cout<<"Menu:\npress 1: to add element\npress 2: to check size\npress 0: to exit\n";
			int val;
			cin>>val;
			do{
				switch(val){
					case 1:
					cout<<"enter the no. you want to insert: ";
						int a;
						cin>>a;
						ll.add(a);
						break;
					case 2:
						ll.size();
						break;
				}
				cin>>val;
			}while(val!=0);
			break;
		}
		case 2:{
			circularlist ls;
			cout<<"Menu:\npress 1: to add element\npress 2: to check size\npress 0: to exit\n";
			int val;
			cin>>val;
			do{
				switch(val){
					case 1:
						cout<<"enter the no. you want to insert: ";
						int a;
						cin>>a;
						ls.add(a);
						break;
					case 2:
						ls.size();
						break;
				}
				cin>>val;
			}while(val!=0);
			break;
		}
	}
}
