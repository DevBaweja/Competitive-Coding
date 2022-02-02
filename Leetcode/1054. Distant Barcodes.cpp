#include <bits/stdc++.h>
using namespace std;

// Backtracking
void rearrangeBarcodesUtil(vector<int> already, vector<int> remaining, vector<int> &res)
{
    if (res.size())
        return;
    int n = remaining.size();
    int k = already.size();

    if (!n)
    {
        res = already;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        vector<int> remainingUtil = remaining;
        vector<int> alreadUtil = already;
        int lastElement = alreadUtil[k - 1];

        int el = remainingUtil[i];
        if (el != lastElement)
        {
            alreadUtil.push_back(el);
            remainingUtil.erase(remainingUtil.begin() + i);
            rearrangeBarcodesUtil(alreadUtil, remainingUtil, res);
        }
        if (res.size())
            break;
    }
}

vector<int> rearrangeBarcodes(vector<int> &barcodes)
{
    int n = barcodes.size();
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        vector<int> barcodesUtil = barcodes;
        vector<int> already = {barcodesUtil[i]};
        barcodesUtil.erase(barcodesUtil.begin() + i);
        rearrangeBarcodesUtil(already, barcodesUtil, res);
        if (res.size())
            break;
    }
    return res;
}

// Doesn't work
vector<int> rearrangeBarcodes(vector<int> &barcodes)
{
    int n = barcodes.size();
    unordered_map<int, int> m;
    for (int el : barcodes)
        m[el]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (pair<int, int> p : m)
        pq.push({p.second, p.first});

    pair<int, int> first = pq.top();
    pq.pop();
    vector<int> res(n, -1);
    int index = 0;
    while (!pq.empty())
    {
        pair<int, int> second = pq.top();
        pq.pop();
        bool turn = false;
        while (first.first && second.first)
        {
            if (!turn)
            {
                res[index++] = first.second;
                first.first--;
            }
            if (turn)
            {
                res[index++] = second.second;
                second.first--;
            }
            turn = !turn;
        }

        if (second.first)
            first = second;
    }
    while (first.first)
    {
        res[index++] = first.second;
        first.first--;
    }
    return res;
}