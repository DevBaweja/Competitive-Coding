#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    if (n == 1 && m == 1)
        return matrix[0][0] == target;
    int l1 = 0, h1 = n - 1;
    int c = 0;
    while (l1 <= h1)
    {
        int m1 = l1 + (h1 - l1) / 2;
        if (matrix[m1][c] <= target)
            l1 = m1 + 1;
        else
            h1 = m1 - 1;
    }
    int r = h1;
    if (r < 0)
        return false;
    int l2 = 0, h2 = m - 1;
    while (l2 <= h2)
    {
        int m2 = l2 + (h2 - l2) / 2;
        if (matrix[r][m2] == target)
            return true;
        if (matrix[r][m2] < target)
            l2 = m2 + 1;
        else
            h2 = m2 - 1;
    }
    return false;
}

// Two Pointers
// Time - O(n+m)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[n-1].size();
    int l = n-1, r = 0;
    while(l >= 0 && r < m) {
        if(target == matrix[l][r])
            return true;
        if(target < matrix[l][r]) {
            l--;
        }
        else {
            r++;
        }
    }
    return false;
}

// Binary Search
// Time - O(log(n) + log(m))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[n-1].size();
    int l = 0, h = n-1;
    while(l<=h) {
        int m = (h-l)/2 + l;
        if(matrix[m][0] == target)
            return true;
        if(matrix[m][0] > target)
            h = m - 1;
        else 
            l = m + 1;        
    }
    if(h == -1)
        return false;
    int ll = 0, hh = m-1;
    while(ll <= hh) {
        int mm = (hh-ll)/2 + ll;
        if(matrix[h][mm] == target)
            return true;
        if(matrix[h][mm] > target)
            hh = mm-1;
        else
            ll = mm+1;
    }
    return false;
}

// Flatten
// Time - O(log(n*m))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[n-1].size();
    int l = 0, h = m*n - 1;
    while(l<=h) {
        int mid = (h-l)/2+l;
        // hypothetical flatten 1 D array
        int el = matrix[mid/m][mid%m];
        if(el == target)
            return true;
        if(el < target)
            l = mid+1;
        else
            h = mid-1;
    }
    return false;
}