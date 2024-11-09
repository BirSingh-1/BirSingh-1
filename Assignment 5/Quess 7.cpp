//	Display all the node values in a circular linked list, repeating value of head node at the 
//	end too. For example, if elements present in the circular linked list starting from head 
//	are 20 ? 100 ? 40 ? 80 ? 60, then output should be displayed as 20 100 40 80 60 20.

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
		void display(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
			}
			else{
				node *temp=head;
				do{
					cout<<temp->data<<"->";
					temp=temp->next;
				}while(temp!=head);
				cout<<head->data<<endl;
			}
		}
};
int main(){
	circularlist ll;
	cout<<"Menu:\npress 1: adding element\npress 2: displaying\npress 0: to exit\n";
	int val;
	cin>>val;
	do{
		switch(val){
			case 1:
				cout<<"enter the no. you want to insert: ";
				int x;
				cin>>x;
				ll.add(x);
				break;
			case 2:
				ll.display();
				break;
		}
		cin>>val;
	}while(val!=0);
}
