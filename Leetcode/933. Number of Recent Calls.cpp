#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    vector<int> dp;
    RecentCounter()
    {
    }

    int ping(int time)
    {
        dp.push_back(time);

        int n = dp.size();
        int count = 0;
        for (int i = n - 1; i >= 0 && time - dp[i] <= 3000; i--)
            count++;
        return count;
    }
};