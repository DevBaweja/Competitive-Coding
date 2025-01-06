#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    int size = 1;
    vector<vector<int>> res;
    while(size <= numRows) {
        vector<int> temp(size, 1);
        for(int i=1; i<size-1; i++){
            temp[i] = res[res.size()-1][i-1] + res[res.size()-1][i];
        }
        res.push_back(temp);
        size++;
    }
    return res;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> dp(numRows);
    dp[0].push_back(1);
    for (int i = 1; i < numRows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!j)
                dp[i].push_back(dp[i - 1][j]);
            else if (i == j)
                dp[i].push_back(dp[i - 1][j - 1]);
            else
                dp[i].push_back(dp[i - 1][j - 1] + dp[i - 1][j]);
        }
    }
    return dp;
}

vector<vector<int>> generate(int numRows) {        
    vector<vector<int>> dp(numRows);
    dp[0].push_back(1);
    for(int i=1; i<numRows; i++) {
        dp[i].push_back(1);
        for(int j=1; j<i; j++) {
            dp[i].push_back(dp[i-1][j-1] + dp[i-1][j]);
        }
        dp[i].push_back(1);
    }
    
    return dp;
}
