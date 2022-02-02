#include <bits/stdc++.h>
using namespace std;

// Frequency
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int size = 26;
    vector<int> count(size, 0);
    for (int el : s1)
        count[el - 'a']++;
    for (int el : s2)
        count[el - 'a']--;

    bool res = true;
    for (int i = 0; i < size; i++)
        if (count[i])
            res = false;
    cout << (res ? "true" : "false");
    return 0;
}

// Hashing
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, int> m;
    for (int el : s1)
        m[el]++;
    for (int el : s2)
    {
        m[el]--;
        if (!m[el])
            m.erase(el);
    }
    cout << (!m.size() ? "true" : "false");
    return 0;
}

// XOR
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int x = 0;
    for (int el : s1)
        x ^= el - 'a';
    for (int el : s2)
        x ^= el - 'a';
    cout << (!x ? "true" : "false");
    return 0;
}