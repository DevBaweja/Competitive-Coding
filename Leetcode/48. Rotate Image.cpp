#include <bits/stdc++.h>
using namespace std;

// TODO
// Figure Out this approach
48. Rotate Image

void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size();
    for(int i=0, j=m-1; i<j ; i++, j--) {
        for(int k=i; k < j; k++) {
            int temp = matrix[i][i+k];
            matrix[i][i+k] = matrix[j-k][i];
            matrix[j-k][i] = matrix[j][j-k];
            matrix[j][j-k] = matrix[i+k][j];
            matrix[i+k][j] = temp;
        }
    }

    // int temp = matrix[0][1];
    // matrix[0][1] = matrix[n-1][0];
    // matrix[n-1][0] = matrix[n][n-1];
    // matrix[n][n-1] = matrix[1][n];
    // matrix[1][n] = temp;

}