#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node
{
public:
    int arrival;
    int departure;
    int tip;
    Node(int arrival, int departure, int tip)
    {
        this->arrival = arrival;
        this->departure = departure;
        this->tip = tip;
    }
};

static bool compare(Node *a, Node *b)
{
    if (a->departure == b->departure)
        return a->arrival < b->arrival;
    return a->departure < b->departure;
}

ll maxTaxiEarnings(int n, vector<vector<int>> &rides)
{

    vector<Node *> v;
    for (vector<int> t : rides)
    {
        Node *n = new Node(t[0], t[1], t[2]);
        v.push_back(n);
    }

    sort(v.begin(), v.end(), compare);

    int index = 1;

    vector<ll> dp(n + 1, 0);

    unordered_map<int, vector<Node *>> m;
    for (Node *t : v)
        m[t->departure].push_back(t);

    while (index <= n)
    {
        ll maxi = dp[index - 1];

        if (m.find(index) != m.end())
        {
            vector<Node *> list = m[index];
            for (Node *p : list)
                maxi = max(maxi, (p->departure - p->arrival + p->tip) + dp[p->arrival]);
        }

        dp[index] = maxi;
        index++;
    }

    return dp[n];
}