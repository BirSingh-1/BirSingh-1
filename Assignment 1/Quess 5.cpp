// Write a program to find sum of every row and every column in a two-dimensional array.

#include<iostream>
using namespace std;
int main(){
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int i,j;
	cout<<"original matrix is:"<<endl;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"sum of each row are as follows: ";
	for(i=0;i<3;i++){
		int sum=0;
		for(j=0;j<3;j++){
			sum=sum+a[i][j];
		}
		cout<<sum<<"\t";
	}
	cout<<endl<<"sum of each row are as follows: ";
	for(i=0;i<3;i++){
		int sum=0;
		for(j=0;j<3;j++){
			sum=sum+a[j][i];
		}
		cout<<sum<<"\t";
	}
} 
