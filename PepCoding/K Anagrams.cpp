#include <bits/stdc++.h>
using namespace std;

// Hashing Count Difference
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    int k;
    cin >> k;
    if (n1 != n2)
    {
        cout << "false";
        return 0;
    }

    int size = 26;
    int res = 0;
    vector<int> count(size, 0);
    for (char el : s1)
        count[el - 'a']++;
    for (char el : s2)
        count[el - 'a']--;

    for (int i = 0; i < size; i++)
        res += abs(count[i]);

    cout << ((res <= 2 * k) ? "true" : "false");
    return 0;
}