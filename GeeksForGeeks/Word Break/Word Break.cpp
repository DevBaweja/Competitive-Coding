#include <bits/stdc++.h>
using namespace std;

// DP Suffix
/*
bool contains(vector<string> &B, string sub){
    bool flag = 0;
    int size = B.size();
    for(int i=0;i<size;i++)
        if(!B[i].compare(sub))
            return true;
    return false;
}

int wordBreakUtil(string A, vector<string> &B, unordered_map<string, int> &dp){
    int k = A.size();
    if(!k) return 1;
    if(dp[A] != 0) return dp[A];
    
    for(int i=1;i<=k;i++){
        string sub = A.substr(0,i);
        if(contains(B, sub) && 
        wordBreakUtil(A.substr(i, k-i), B, dp) == 1)
            return dp[A] = 1;
    }
    return dp[A] = 0;
}

int wordBreak(string A, vector<string> &B) {
    unordered_map<string,int> dp;
    return wordBreakUtil(A,B,dp);
}
*/

// Optimized Approach
int wordBreak(string A, vector<string> &B)
{
    int n = B.size();
    unordered_set<string> m;
    for (int i = 0; i < n; i++)
        m.insert(B[i]);

    int len = A.size();
    vector<bool> dp(len + 1, false);
    dp[0] = true;

    for (int i = 1; i <= len; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j] && m.find(A.substr(j, i - j)) != m.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}

// BFS
// Backtracking
// Trie