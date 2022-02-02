#include <bits/stdc++.h>
using namespace std;

// Doesn't works
// Contains Anagrams as substring with other characters
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    unordered_map<char, int> m1, m2;
    for (int el : s2)
        m2[el]++;

    int count = 0;
    int low = 0;
    int res;
    for (int high = 0; high < n1; high++)
    {
        char acquire = s1[high];
        m1[acquire]++;
        if (m2.find(acquire) != m2.end() && m2[acquire] == m1[acquire])
            count++;

        while (count > m2.size())
        {
            char release = s1[low++];
            if (m2.find(release) != m2.end() && m2[release] == m1[release])
                count--;
            m1[release]--;
            if (!m1[release])
                m1.erase(release);
        }

        if (count == m2.size())
            res++;
    }

    cout << res << endl;
    return 0;
}

// Contain only anagrams without other characters
#include <bits/stdc++.h>
using namespace std;

bool isSame(unordered_map<char, int> &m1, unordered_map<char, int> &m2)
{
    if (m1.size() != m2.size())
        return false;
    for (pair<char, int> p : m2)
        if (m1.find(p.first) == m1.end() ||
            m1[p.first] != p.second)
            return false;
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    unordered_map<char, int> m1, m2;
    int res = 0;
    vector<int> ans;
    for (int i = 0; i < n2; i++)
        m2[s2[i]]++;

    for (int i = 0; i < n2; i++)
        m1[s1[i]]++;

    if (isSame(m1, m2))
    {
        res++;
        ans.push_back(0);
    }
    for (int i = n2; i < n1; i++)
    {
        char acquire = s1[i];
        m1[acquire]++;
        char release = s1[i - n2];
        m1[release]--;
        if (!m1[release])
            m1.erase(release);
        if (isSame(m1, m2))
        {
            res++;
            ans.push_back(i - n2 + 1);
        }
    }

    cout << res << endl;
    for (int el : ans)
        cout << el << " ";
    return 0;
}