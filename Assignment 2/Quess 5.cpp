//	Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion 
//	if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the 
//	number of inversions in an array.


#include <iostream>
using namespace std;
int main() {
    int a[15]={1,8,4,7,5,1,2,14,7,8,6,1,9,10,7};
    int i,j,count=0;
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            if(i<j && a[i]>a[j])
            count++;
		}
	}
    cout<<"no. of inversions are: "<<count;
    return 0;
	}

