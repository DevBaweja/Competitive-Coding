#include <bits/stdc++.h>
using namespace std;

// It doesn't give all as low will be updated
// However, Longest k unique can be founded
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();

    unordered_map<char, int> m;
    int low = 0, mid = 0;
    int res = 0;

    for (int high = 0; high < n; high++)
    {
        char acquire = s[high];
        m[acquire]++;
        while (m.size() > k)
        {
            char release = s[mid];
            m[release]--;
            if (!m[release])
                m.erase(release);
            mid++;
        }
        if (m.size() == k)
            res += mid - low;
        low = mid;
    }
    cout << res << endl;
}

// Double Hashmap
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();

    if (k == 1)
    {
        unordered_map<char, int> m;
        int low = 0, mid = 0;
        int res = 0;
        for (int high = 0; high < n; high++)
        {
            char acquire = s[high];
            m[acquire]++;
            while (m.size() > k)
            {
                char release = s[mid++];
                m[release]--;
                if (!m[release])
                    m.erase(release);
            }
            if (m.size() == k)
                res += mid - low + 1;
            low = mid;
        }
        cout << res << endl;
        return 0;
    }

    unordered_map<char, int> mleft, mright;
    int highleft = 0, highright = 0;
    int low = 0;
    int res = 0;

    while (true)
    {
        while (highright < n)
        {
            char acquireright = s[highright++];
            mright[acquireright]++;

            if (mright.size() > k)
            {
                mright.erase(acquireright);
                highright--;
                break;
            }
        }

        if (mright.size() != k)
            break;

        while (highleft < highright)
        {
            char acquireleft = s[highleft++];
            mleft[acquireleft]++;
            if (mleft.size() > k - 1)
            {
                mleft.erase(acquireleft);
                highleft--;
                break;
            }
        }

        if (mleft.size() != k - 1)
            break;

        while (mleft.size() == k - 1 && mright.size() == k)
        {
            res += highright - highleft;
            char release = s[low++];
            mleft[release]--;
            mright[release]--;
            if (!mleft[release])
                mleft.erase(release);
            if (!mright[release])
                mright.erase(release);
        }
    }
    cout << res << endl;
    return 0;
}

// TODO
// AtMost(k) - AtMost(k-1)