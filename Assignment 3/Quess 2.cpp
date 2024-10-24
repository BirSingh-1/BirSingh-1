//	Given a string, reverse it using STACK. For example “DataStructure” should be output
//	as “erutcurtSataD.”

#include<iostream>
#include<stack>
using namespace std;
int main(){
	char arr[]={"DataStructure"};
	int n=sizeof(arr)/sizeof(arr[0])-1;
	cout<<n<<endl;
	stack<char> s;
	int i;
	for(i=0;i<n;i++){
		s.push(arr[i]);
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}
