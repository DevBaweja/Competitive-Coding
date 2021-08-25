#include <bits/stdc++.h>
using namespace std;

// Using Map Sort
struct compareStruct
{
    unordered_map<char, int> m;

    compareStruct(unordered_map<char, int> m)
    {
        this->m = m;
    }

    bool operator()(char a, char b)
    {
        return m[a] > m[b];
    }
};

string frequencySort(string s)
{
    unordered_map<char, int> m;
    for (int el : s)
        m[el]++;

    sort(s.begin(), s.end(), compareStruct(m));

    return s;
}

// Using Vector Sort
static bool compare(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

string frequencySort(string s)
{
    unordered_map<char, int> m;
    for (int el : s)
        m[el]++;

    vector<pair<char, int>> v;

    for (pair<char, int> el : m)
        v.push_back(el);

    sort(v.begin(), v.end(), compare);

    string res = "";
    for (int i = 0; i < v.size(); i++)
    {
        int count = v[i].second;
        while (count--)
            res += v[i].first;
    }

    return res;
}
