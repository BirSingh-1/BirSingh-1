//	Write a program that checks if an expression has balanced parentheses just for ( & )

#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<char> s;
	char a[50];
	cout<<"enter the expression: "<<endl;
	cin>>a;
	int i=0;
	bool flag=true;
	while(a[i]!='\0'){
		if(a[i]=='(')
		s.push(a[i]);
		else if(a[i]==')'){
			if(s.empty()){
				flag=false;
				break;
			}
			else{
				s.pop();
			}
		}
		i++;
	}
	if(!s.empty())
	flag=false;
	if (flag)
	cout<<"balanced parenthesis"<<endl;
	else
	cout<<"unbalanced parenthesis";
}
