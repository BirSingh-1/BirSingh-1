// Write a program to convert uppercase character to lowercase and vice versa in an array
#include <iostream>
using namespace std;
int main(){
    char a[]={"abCdEfghIJkL"};
//	let n be the no of characters in the above array
	int n=sizeof(a)/sizeof(a[0])-1;
	char x;
	for(int i=0;i<n;i++){
		if('A'<=a[i] && a[i]<='Z'){
			x=a[i]+32;
			cout<<x<<"\t";
		}
		else{
			x=a[i]-32;
			cout<<x<<"\t";
		}
	}
}
