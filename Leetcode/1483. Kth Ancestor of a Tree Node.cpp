#include <bits/stdc++.h>
using namespace std;

// Brute Force
class TreeAncestor
{
public:
    int n;
    vector<int> parent;
    TreeAncestor(int n, vector<int> &parent)
    {
        this->n = n;
        this->parent = parent;
    }

    int getKthAncestor(int node, int k)
    {
        int cur = node;
        while (cur && k)
        {
            cur = parent[cur];
            k--;
        }
        if (k)
            return -1;
        return cur;
    }
};

// Binary Lifting
class TreeAncestor
{
public:
    int n;
    vector<int> parent;
    int steps;
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int> &parent)
    {
        this->n = n;
        this->parent = parent;
        this->steps = 18;

        vector<vector<int>> dp(n, vector<int>(steps));

        for (int node = 0; node < n; node++)
            dp[node][0] = parent[node];

        for (int step = 1; step < this->steps; step++)
        {
            for (int node = 0; node < n; node++)
            {
                if (dp[node][step - 1] == -1)
                    dp[node][step] = -1;
                else
                    dp[node][step] = dp[dp[node][step - 1]][step - 1];
            }
        }
        this->dp = dp;
    }

    int getKthAncestor(int node, int k)
    {
        for (int step = 0; step < this->steps; step++)
        {
            if (k & (1 << step))
            {
                node = dp[node][step];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
