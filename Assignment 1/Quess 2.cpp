// Design the logic to remove the duplicate elements from an Array
// and after the deletion the array should contain the unique elements.

#include<iostream>
using namespace std;
int main(){
	int a[15]={3,8,6,1,2,9,4,3,6,5,2,7,9,10,1};
	// let no. of elements be n
	int n=15;
	int i,j;
	cout<<"original array is:"<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<"\t";
	}
	cout<<endl<<"new array is:"<<endl;
	for(i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if(a[i]==a[j]){
				if(j==i)
				cout<<a[j]<<"\t";
				else break;
			}
		}
	}
}
