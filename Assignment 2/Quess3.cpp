// Design the Logic to Find a Missing Number in a Sorted Array.

#include<iostream>
using namespace std;
int main(){
//	considering the foll array
	int arr[]={1,2,3,4,5,7,8,9,10};
//	let n be the no of elements
	int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==i+1)
		continue;
		else if(arr[i]!=i+1){
			cout<<i+1<<" is missing";
			break;
		}
	}
}
