#include<bits/stdc++.h>
using namespace std;

int minOperation(int n)
{
    if(n==1 || n==2) return n;
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        if(i%2)
            dp[i] = dp[i-1];
        else
            dp[i] = min(dp[i-1], dp[i/2]);
        dp[i]++;
    }
    return dp[n];
}

    int minOperation(int n)
{
    int count = 0;
    while(n){
        if(n%2)
            n--;
        else
            n /= 2;
        count++;
    }
    return count;
}