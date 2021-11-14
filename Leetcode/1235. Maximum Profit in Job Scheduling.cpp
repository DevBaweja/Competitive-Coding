#include <bits/stdc++.h>
using namespace std;

// DP and Hashing
class Node
{
public:
    int arrival;
    int departure;
    int profit;
    Node(int arrival, int departure, int profit)
    {
        this->arrival = arrival;
        this->departure = departure;
        this->profit = profit;
    }
};

static bool compare(Node *a, Node *b)
{
    if (a->departure == b->departure)
        return a->arrival < b->arrival;
    return a->departure < b->departure;
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = profit.size();
    vector<Node *> v(n);
    for (int i = 0; i < n; i++)
        v[i] = new Node(startTime[i], endTime[i], profit[i]);
    sort(v.begin(), v.end(), compare);

    unordered_map<int, vector<Node *>> m;
    for (Node *node : v)
        m[node->departure].push_back(node);

    int index = 1;
    int k = v[n - 1]->departure;
    vector<int> dp(k + 1, 0);

    while (index <= k)
    {
        int maxi = dp[index - 1];
        if (m.find(index) != m.end())
        {
            vector<Node *> list = m[index];
            for (Node *node : list)
                maxi = max(maxi, node->profit + dp[node->arrival]);
        }
        dp[index++] = maxi;
    }
    return dp[k];
}

// TODO
// Suffix DP and Binary Search
