//	Write a program to count the number of occurrences of a given key in a singly linked list and then 
//	delete all the 0ccurrences. For example, if given linked list is 1->2->1->2->1->3->1 and given key 
//	is 1, then output should be 4. After deletion of all the occurrences of 1, the linked list is 2->2->3.

#include<iostream>
#include<iterator>  // new concept of iterators
#include<list>
using namespace std;

int main(){
	list<int> ls;
	int count=0;
	ls.push_front(1);
	ls.push_back(2);
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(1);
	ls.push_back(3);
	ls.push_back(1);
	cout<<"your list: "<<endl;
	list<int>::iterator itr;
	for(itr=ls.begin();itr!=ls.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl<<"enter the value for which you want to find the no. of occurrence and delete it: ";
	int x;
	cin>>x;
	cout<<endl<<"your new list is: "<<endl;
	for(itr=ls.begin();itr!=ls.end();itr++){
		if(*itr==x){
			count++;
		}
		else{
			cout<<*itr<<" ";
		}
	}
	cout<<endl<<"no of "<<x<<"'s are: "<<count;
}
