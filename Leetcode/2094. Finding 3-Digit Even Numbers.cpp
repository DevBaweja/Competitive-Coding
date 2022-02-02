#include <bits/stdc++.h>
using namespace std;

// Brute Force
vector<int> findEvenNumbers(vector<int> &digits)
{
    int n = digits.size();
    unordered_map<int, int> m;
    for (int el : digits)
        m[el]++;

    vector<int> res;
    for (int i = 0; i < 10; i += 2)
    {
        if (m.find(i) != m.end() && m[i] >= 1)
        {
            for (int j = 0; j < 10; j++)
            {
                if (m.find(j) != m.end() && (i != j || m[j] >= 2))
                {
                    for (int k = 1; k < 10; k++)
                    {
                        if (m.find(k) != m.end() &&
                            ((k != i && k != j) ||
                             ((k != i || k != j) && m[k] >= 2) ||
                             m[k] >= 3))
                            res.push_back(i + 10 * j + 100 * k);
                    }
                }
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

// Brute Force
vector<int> findEvenNumbers(vector<int> &digits)
{
    int n = digits.size();
    unordered_map<int, int> m;
    for (int el : digits)
        m[el]++;

    vector<int> res;
    for (int i = 0; i < 10; i += 2)
    {
        if (m.find(i) != m.end())
        {
            m[i]--;
            if (!m[i])
                m.erase(i);
            for (int j = 0; j < 10; j++)
            {
                if (m.find(j) != m.end())
                {
                    m[j]--;
                    if (!m[j])
                        m.erase(j);
                    for (int k = 1; k < 10; k++)
                    {
                        if (m.find(k) != m.end())
                            res.push_back(i + 10 * j + 100 * k);
                    }
                    m[j]++;
                }
            }
            m[i]++;
        }
    }
    sort(res.begin(), res.end());
    return res;
}

// Brute Force
vector<int> findEvenNumbers(vector<int> &digits)
{
    int n = digits.size();
    vector<int> count(10, 0);
    for (int el : digits)
        count[el]++;

    vector<int> res;
    for (int i = 0; i < 10; i += 2)
    {
        if (count[i])
        {
            count[i]--;
            for (int j = 0; j < 10; j++)
            {
                if (count[j])
                {
                    count[j]--;
                    for (int k = 1; k < 10; k++)
                    {
                        if (count[k])
                            res.push_back(i + 10 * j + 100 * k);
                    }
                    count[j]++;
                }
            }
            count[i]++;
        }
    }
    sort(res.begin(), res.end());
    return res;
}