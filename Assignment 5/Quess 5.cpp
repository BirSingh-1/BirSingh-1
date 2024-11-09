//	Develop a menu driven program for the following operations of on a DOUBLY Linked List. 
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
		node *prev;
		node(int value){
			data=value;
			next=NULL;
			prev=NULL;
		}
};
class doublylist{
	node *head;
	public:
		doublylist(){
			head=NULL;
		}
		void add_begin(int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
			}
			else{
				x->next=head;
				head->prev=x;
				head=x;
			}
		}
		void add_end(int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
			}
			else{
				node *temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=x;
				x->prev=temp;
			}
		}
		void delbeg(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else{
				node *temp=head;
				head=head->next;
				delete temp;
				temp=NULL;
			}
		}
		void delend(){
			if(head==NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else if(head->next==NULL){
				delete head;
				head=NULL;
			}
			else{
				node *temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->prev->next=NULL;
				delete temp;
				temp=NULL;
			}
		}
		void aftervalue(int a, int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
				return;
			}
			else{
				node *temp=head;
				while(temp!=NULL && temp->data!=a){
					temp=temp->next;
				}
				if(temp==NULL){
					cout<<"node "<<a<<" is not present"<<endl;
				}
				else if(temp->next==NULL){
					temp->next=x;
					x->prev=temp;
				}
				else{
					x->next=temp->next;
					temp->next->prev=x;
					temp->next=x;
					x->prev=temp;
				}
			}
		}
		void beforevalue(int a, int value){
			node *x=new node(value);
			if(head==NULL){
				head=x;
			}
			else if(head->data==a){
				x->next=head;
				head->prev=x;
				head=x;
			}
			else{
				node *temp=head;
				while(temp!=NULL && temp->data!=a){
					temp=temp->next;
				}
				if(temp==NULL){
					cout<<"node "<<a<<" is not present"<<endl;
				}
				else{
					temp->prev->next=x;
					x->prev=temp->prev;
					temp->prev=x;
					x->next=temp;
				}
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
		void delany(int a){
			node *temp=head;
			if(head==NULL){
				cout<<"list is empty"<<endl;
				return;
		 	}
		 	else if(head->data==a){
		 		head=head->next;
		 		delete temp;
		 		temp=NULL;
		 		return;
			 }
			 else{
			 	while(temp!=NULL && temp->data!=a){
			 		temp=temp->next;
				 }
				 if(temp->next==NULL){
				 	temp->prev->next=NULL;
				 	delete temp;
				 	temp=NULL;
				 }
				 else{
				 	temp->prev->next=temp->next;
				 	temp->next->prev=temp->prev;
				 	delete temp;
				 	temp=NULL;
				 }
			 }
		}
		void search(int a){
			int count;
			if(head==NULL){
				cout<<"list is empty"<<endl;
				return;
			}
			else{
				node *temp=head;
				int count;
				while(temp!=NULL && temp->data!=a){
					temp=temp->next;
					count++;
				}
				if(temp==NULL){
					cout<<"no. not present"<<endl;
				}
				else{
					cout<<"no. found at position: "<<count+1<<endl;
				}
			}
		}
};
int main(){
	doublylist ll;
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
