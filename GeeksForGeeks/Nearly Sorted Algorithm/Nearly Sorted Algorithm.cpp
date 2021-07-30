#include <bits/stdc++.h>
using namespace std;

// Set
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> res;
        set<pair<int, int>> s;
        for (int i = 0; i < k; i++)
            s.insert({v[i], i});
        for (int i = k; i < n; i++)
        {
            pair<int, int> el = *(s.begin());
            res.push_back(el.first);
            s.erase(s.begin());
            s.insert({v[i], i});
        }
        while (!s.empty())
        {
            pair<int, int> el = *(s.begin());
            res.push_back(el.first);
            s.erase(s.begin());
        }

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// Priority Queue
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < k; i++)
            pq.push({v[i], i});
        for (int i = k; i < n; i++)
        {
            pair<int, int> el = pq.top();
            pq.pop();
            res.push_back(el.first);
            pq.push({v[i], i});
        }
        // Remaining elements
        while (!pq.empty())
        {
            pair<int, int> el = pq.top();
            pq.pop();
            res.push_back(el.first);
        }

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}