//	Addition of two sparse matrices

#include<iostream>
using namespace std;
int main(){
    // Sparse Matrix A in triplet form (row, col, value)
    int A[5][3] = {
        {3, 3, 4},  // 3x3 matrix with 4 non-zero elements
        {0, 0, 1},
        {0, 2, 2},
        {1, 1, 3},
        {2, 0, 4}
    };

    // Sparse Matrix B in triplet form (row, col, value)
    int B[5][3] = {
        {3, 3, 4},  // 3x3 matrix with 4 non-zero elements
        {0, 1, 5},
        {0, 2, 2},
        {2, 0, 7},
        {2, 2, 8}
    };

    // Resultant Sparse Matrix C (maximum size is A's non-zero elements + B's non-zero elements)
    int C[10][3];
    int k = 1;  // Index for C

    // Initialize metadata for C (number of rows and columns)
    C[0][0] = A[0][0];  // Rows of C = Rows of A (same as B)
    C[0][1] = A[0][1];  // Columns of C = Columns of A (same as B)

    int i = 1, j = 1;

    // Process the non-zero elements of both matrices
    while (i <= A[0][2] && j <= B[0][2]) {
        // Compare row and column indices of current elements in A and B
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            // A[i] comes before B[j], copy A[i] to C
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
            k++;
        } else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            // B[j] comes before A[i], copy B[j] to C
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
            k++;
        } else {
            // A[i] and B[j] are in the same position (same row and column)
            int sum = A[i][2] + B[j][2];
            if (sum != 0) {
                C[k][0] = A[i][0];
                C[k][1] = A[i][1];
                C[k][2] = sum;
                k++;
            }
            i++;
            j++;
        }
    }

    // If any elements are left in A, copy them to C
    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++;
        k++;
    }

    // If any elements are left in B, copy them to C
    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++;
        k++;
    }

    // Set the number of non-zero elements in C
    C[0][2] = k - 1;

    // Output the result matrix C in triplet form
    printf("Resultant Sparse Matrix C (triplet form):\n");
    printf("Row\tCol\tValue\n");
    for (int z = 0; z <= C[0][2]; z++) {
        printf("%d\t%d\t%d\n", C[z][0], C[z][1], C[z][2]);
    }

    return 0;
}

