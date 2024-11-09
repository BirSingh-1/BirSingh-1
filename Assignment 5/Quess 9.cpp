//	Write a program to check if a linked list is Circular Linked List or not.

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
bool circular(node *head){
	if(!head){
		return true;
	}
	else{
		node *temp=head;
		while(temp && temp->next!=head){
			temp=temp->next;
		}
		if(!temp){
			return false;
		}
		else{
			return true;
		}
	}
}
int main(){
	node *head=new node(1);
	head->next=new node(3);
	head->next=new node(4);
	head->next=new node(5);
	circular(head)? cout<<"Yes"<<endl : cout<<"No"<<endl;
	head->next=head;
	circular(head)? cout<<"Yes"<<endl : cout<<"No"<<endl;
}
