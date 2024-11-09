//	Develop a menu driven program for the following operations of on a CIRCULAR Linked List. 
//	(a) Insertion at the beginning.		(b) Insertion at the end. 
//	(c) Insertion in before or after a node having a specific value. (d) Deletion from the beginning. 
//	(e) Deletion from the end. 		(f) Deletion of a specific node. 
//	(g) Search for a node and display its position from head.  (h) Display all the node values.

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
class circularlist{
	node *head;
	public:
		circularlist(){
			head=NULL;
		}
		void add_begin(int value){
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
				head=x;
			}
		}
		void add_end(int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
				head->next=head;
				return;
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
		void delbeg(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
			}
			else if(head->next==head){
				delete head;
				head=NULL;
			}
			else{
				node *temp=head;
				node*temp1=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=head->next;
				head=head->next;
				delete temp1;
				temp1=NULL;
			}
		}
		void delend(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
			}
			else if(head->next==head){
				delete head;
				head=NULL;
			}
			else{
				node *temp=head;
				node *pre=NULL;
				while(temp->next!=head){
					pre=temp;
					temp=temp->next;
				}
				pre->next=head;
				delete temp;
				
			}
		}
		void aftervalue(int a,int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
				x->next=head;
				return;
			}
			else{
				node *temp=head;
				while(temp->next!=head && temp->data!=a){
					temp=temp->next;
				}
				if(temp==head && temp->data!=a){
					cout<<"node "<<a<<" is not present"<<endl;
				}
				else{
					x->next=temp->next;
					temp->next=x;
				}
			}
		}
		void beforevalue(int a,int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
				x->next=head;
				return;
			}
			else if(head->data==a){
				node *temp=head;
				while(temp->next!=head){
					temp=temp->next;
				}
				temp->next=x;
				x->next=head;
				head=x;
			}
			else{
				node *temp=head;
				node *pre=NULL;
				while(temp->next!=head && temp->data!=a){
					pre=temp;
					temp=temp->next;
				}
				if(temp->next==head && temp->data!=a){
					cout<<"node "<<a<<" is not present"<<endl;
				}
				else{
					x->next=pre->next;
					pre->next=x;
				}
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
				cout<<"NULL"<<endl;
			}
		}
		void delany(int a){
			node *temp=head;
			node *pre=NULL;
			if(head==NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else if(head->data==a){
				delbeg();
				return;
			}
			else{
				
				do{
					pre=temp;
					temp=temp->next;
				}while(temp!=head && temp->data!=a);
				if(temp==head && temp->data!=a){
					cout<<"node is not present"<<endl;
				}
				else if(temp->data==a){
					pre->next=temp->next;
					delete temp;
					temp=NULL;
				}
			}
		}
		void search(int a){
			if(head==NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else{
				node *temp=head;
				int count=0;
				do{
					if(temp->data==a){
						cout<<"no. found at position: "<<count+1<<endl;
						return;
					}
					temp=temp->next;
					count++;
				}while(temp!=head);
					cout<<"no. not present"<<endl;
			}
		}
};
int main(){
	circularlist ll;
	cout<<"Menu:\npress 1: insertion at begining\npress 2: insertion at end\npress 3: insertion after value\n"
	    <<"press 4: insertion before value\npress 5: deletion from begining\npress 6: deletion from end\n"
		<<"press 7: delete a value\npress 8: to search and get position\npress 9: display\npress 0: exit\n";
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
				cout<<"enter the no. you want to insert and after which no. resp: ";
				int a;
				cin>>x>>a;
				ll.aftervalue(a,x);
				break;
			case 4:
				cout<<"enter the no. you want to insert and before which no. resp: ";
				cin>>x>>a;	
				ll.beforevalue(a,x);
				break;
			case 5:
				ll.delbeg();
				break;
			case 6:
				ll.delend();
				break;
			case 7:
				cout<<"enter the no. you want to delete: ";
				cin>>x;
				ll.delany(x);
				break;
			case 8:
				cout<<"enter the no. you want to search: ";
				cin>>x;
				ll.search(x);
				break;
			case 9:
				ll.display();
				break;
		}
		cin>>val;
	}while(val!=0);
	return 0;
}
