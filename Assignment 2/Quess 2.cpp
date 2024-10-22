// Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent 
// elements if they are in wrong order. Code the Bubble sort with the following elements: 
// 64  34  25  12  22  11  90

#include<iostream>
using namespace std;
int main(){
	int arr[]={64,34,25,12,22,11,90};
//	let n be the no. of elements of above array
	int n=sizeof(arr)/sizeof(arr[0]);
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
}
