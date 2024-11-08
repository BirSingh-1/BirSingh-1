//	Write a program to count the total number of distinct elements in an array of length n. 

#include<iostream>
using namespace std;
int main(){
	int a[]={1,3,4,5,2,6,3,1,7,4,8,0,9,6,8,10,7,3};
//	let n be the no of elements in the above arr
	int n=sizeof(a)/sizeof(a[0]);
	int i,j,count=0;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(a[j]==a[i]){
				if(j==i)
				count++;
				else break;
			}
		}
	}
	cout<<"no.of distinct elements are: "<<count;
}
