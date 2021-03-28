#include <iostream>
#include <vector>
using namespace std;
#define SIZE 26

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> lfreq(SIZE), rfreq(SIZE);
        for (int i = 0; i < s.length() / 2; i++)
            lfreq[s[i] - 'a']++;
        for (int i = (s.length() + 1) / 2; i < s.length(); i++)
            rfreq[s[i] - 'a']++;

        bool same = true;
        for (int i = 0; i < SIZE; i++)
            if (lfreq[i] != rfreq[i])
            {
                same = false;
                break;
            }
        if (same)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
