#include <bits/stdc++.h>
using namespace std;

// Recursion
int countVowelStringsUtil(int n, string s, vector<char> &v, unordered_map<char, int> &m)
{
    int k = s.size();
    if (k == n)
        return 1;

    int count = 0;

    int ch = s[k - 1];
    int start = m[ch];

    for (int index = start; index < v.size(); index++)
        count += countVowelStringsUtil(n, s + v[index], v, m);

    return count;
}

int countVowelStrings(int n)
{
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> m = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    int count = 0;
    string s = "";
    for (char el : v)
        count += countVowelStringsUtil(n, s + el, v, m);
    return count;
}

// DP Space Optimization
int countVowelStrings(int n)
{
    int pa = 1, pe = 1, pi = 1, po = 1, pu = 1;
    n--;
    while (n--)
    {
        int na = pa;
        int ne = pa + pe;
        int ni = pa + pe + pi;
        int no = pa + pe + pi + po;
        int nu = pa + pe + pi + po + pu;
        pa = na;
        pe = ne;
        pi = ni;
        po = no;
        pu = nu;
    }
    return pa + pe + pi + po + pu;
}
// DP Space Optimization and Logic
int countVowelStrings(int n)
{
    int pa = 1, pe = 1, pi = 1, po = 1, pu = 1;
    n--;
    while (n--)
    {
        int na = pa;
        int ne = na + pe;
        int ni = ne + pi;
        int no = ni + po;
        int nu = no + pu;
        pa = na;
        pe = ne;
        pi = ni;
        po = no;
        pu = nu;
    }
    return pa + pe + pi + po + pu;
}

// Another way of DP
int countVowelStrings(int n)
{
    int count = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        int sum = 0;
        for (int j = 1; j <= i; j++)
        {
            sum += j;
            count += sum;
        }
    }
    return count;
}

// BFS Queue
int countVowelStrings(int n)
{
    vector<string> v{"a", "e", "i", "o", "u"};

    unordered_map<char, int> m = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    queue<string> q;

    for (string el : v)
        q.push(el);

    for (int count = 1; count < n; count++)
    {
        int size = q.size();
        while (size--)
        {
            string temp = q.front();
            q.pop();

            int k = temp.size();
            char end = temp[k - 1];

            int start = m[end];
            for (int index = start; index < v.size(); index++)
                q.push(temp + v[index]);
        }
    }
    return q.size();
}