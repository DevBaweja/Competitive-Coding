#include <bits/stdc++.h>
using namespace std;

// Time O(n^2) Space O(n)
/*
    bool find3Numbers(int A[], int n, int x)
    {
        for(int i=0;i<n;i++){
            int sum = x-A[i];
            unordered_set<int> s;
            for(int j=i+1;j<n;j++){
                if(s.find(sum-A[j]) != s.end())
                    return 1;
                s.insert(A[j]);
            }
        }
        return 0;
    }
*/

// Time O(n^2) Space O(1)
bool find3Numbers(int A[], int n, int x)
{
    sort(A, A + n);
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int cursum = A[i] + A[l] + A[r];
            if (cursum == x)
                return 1;
            if (cursum < x)
                l++;
            else
                r--;
        }
    }
    return 0;
}