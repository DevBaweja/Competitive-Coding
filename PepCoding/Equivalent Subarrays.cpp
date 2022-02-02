#include <bits/stdc++.h>
using namespace std;

// Exactly k Unique
// Sliding Window and Double Hashing
int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    unordered_set<int> st;
    for (int ch : s)
        st.insert(ch);

    int k = st.size();
    if (k == 1)
    {
        unordered_map<int, int> m;
        int low = 0, mid = 0;
        int res = 0;
        for (int high = 0; high < n; high++)
        {
            int acquire = s[high];
            m[acquire]++;
            while (m.size() > k)
            {
                int release = s[mid++];
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

    unordered_map<int, int> mleft, mright;
    int highleft = 0, highright = 0;
    int low = 0;
    int res = 0;

    while (true)
    {
        while (highright < n)
        {
            int acquireright = s[highright++];
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
            int acquireleft = s[highleft++];
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
            int release = s[low++];
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

// Sliding Window
// Single Hashing
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    unordered_set<int> st;
    for (int ch : s)
        st.insert(ch);

    int k = st.size();
    unordered_map<int, int> m;
    int low = 0;
    int res = 0;
    for (int high = 0; high < n; high++)
    {
        int acquire = s[high];
        m[acquire]++;
        while (m.size() == k)
        {
            res += n - high;
            int release = s[low++];
            m[release]--;
            if (!m[release])
                m.erase(release);
        }
    }
    cout << res << endl;
    return 0;
}