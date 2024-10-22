// Transpose of a sparse matrix

#include <iostream>
using namespace std;
int main(){
    int a[3][3]={2,0,0,5,0,1,0,3,0};
    int i,j;
    cout<<"initial matrix is:"<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int c=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]!=0)
            c++;
        }
    }
    cout<<"no. of non zero elements are: "<<c<<endl;
    int s[c+1][3];    //1st row for info    and 3 columns for row and colum no. and non zero value
    int k=1;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
                if(a[i][j]!=0){
                    s[k][0]=i;  // start writing row no. of non zero from 2nd row in sparse representation
                    s[k][1]=j; // start writing column no. of non zero from 2nd row in sparse representation
                    s[k][2]=a[i][j];  // non zero value
                    k++;
            }
        }
    }
    s[0][0]=3;  //rows of initial matrix 
    s[0][1]=3;  //colums of initial matrix
    s[0][2]=c;  //no. of non zero elements
//	all above three things are represented in first row in sparse representation


//	representation of sparse
	cout<<"sparse representation of above matrix is:"<<endl;
    for(i=0;i<=c;i++){
        for(j=0;j<3;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
//	transpose of sparse
    k=1;
    cout<<endl;
    int t[c+1][3];
    t[0][0]=s[0][1];    // in transpose total rows becomes total columns of sparse
    t[0][1]=s[0][0];   // in transpose total rows becomes total columns of sparse
    t[0][2]=s[0][2];  // no. of non zero elements remains same
    for(i=0;i<s[0][1];i++){
        for(j=1;j<=s[0][2];j++){
//			the above two for loops are imp 
            if(s[j][1]==i){
                t[k][0]=s[j][1];
		        t[k][1]=s[j][0];
		        t[k][2]=s[j][2];
		        k++;
            }
        }
    }
    
//	representation of transpose of sparse
	cout<<"transpose of above sparse matrix is:"<<endl;
    for(i=0;i<=c;i++){
        for(j=0;j<3;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
}
