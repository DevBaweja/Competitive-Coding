/*
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.  (Recall that a node is a leaf if and only if it has 0 children.)
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node.  It is guaranteed this sum fits into a 32-bit integer.

 

Example 1:

Input: arr = [6,2,4]
Output: 32
Explanation:
There are two possible trees.  The first has non-leaf node sum 36, and the second has non-leaf node sum 32.

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (ie. it is less than 2^31).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxi[41][41];
    int memo[41][41];
    int dp(int left, int right)
    {
        if (left == right)
            return 0;

        if (memo[left][right] != -1)
            return memo[left][right];

        int ans = 1 << 30;

        for (int i = left; i < right; i++)
            ans = min(ans, maxi[left][i] * maxi[i + 1][right] + dp(left, i) + dp(i + 1, right));

        memo[left][right] = ans;
        return ans;
    }
    int MinimumCostTreeFromLeafValues(vector<int> &arr)
    {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < arr.size(); i++)
        {
            maxi[i][i] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
                maxi[i][j] = max(maxi[i][j - 1], arr[j]);
        }

        return dp(0, arr.size() - 1);
    }
};
