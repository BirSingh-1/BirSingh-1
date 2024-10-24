// Write a program to convert an Infix expression into a Postfix expression.
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int prec(char x){
	if (x=='+'|| x=='-')
 		return 1;
 	else if (x=='*'||x=='/')
 		return 2;
 	else if (x=='^')
 		return 3;
 		return 0;
	}
int main(){
	stack<char> s;
	string a;
	cout<<"enter the expression: "<<endl;
	cin>>a;
	a+=')';
	s.push('(');
	for(int i=0;i<a.length();i++){
		char ch=a[i];
		
		if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || 
		(ch>='0'&& ch<='9'))
			cout<<ch<<" ";
		else if(ch=='(')
			s.push(ch);
		else if(ch==')'){
			while(s.top()!='('){
				cout<<s.top()<<" ";
				s.pop();
			}
			s.pop();
		}
		else{
			while(!s.empty() && prec(s.top())>=prec(ch)){
				cout<<s.top()<<" ";
				s.pop();
			}
			s.push(ch);
		}
	}
}
