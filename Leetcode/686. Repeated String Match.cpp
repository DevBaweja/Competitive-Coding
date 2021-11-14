#include <bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string a, string b)
{
    int n = a.size();
    int m = b.size();

    if (n > m)
    {
        for (int k = 0; k < n; k++)
        {
            int i = k, j = 0;
            bool flag = true;
            int count = 1;
            while (j < m)
            {
                flag &= (a[i++] == b[j++]);
                if (j < m && i == n)
                    count++;
                i %= n;
            }
            if (flag)
                return count;
        }
        return -1;
    }

    for (int k = 0; k < n; k++)
    {
        int i = k, j = 0;
        bool flag = true;
        int count = 0;
        while (j < m)
        {

            flag &= (a[i++] == b[j++]);
            if (!flag)
                break;
            if (j < m && i == n)
                count++;
            i %= n;
        }
        if (flag)
        {
            if (n == 1)
                return m;
            return count + 1;
        }
    }
    return -1;
}

// Repeating
int repeatedStringMatch(string a, string b)
{
    int n = a.size();
    int m = b.size();
    string temp = "";
    int count = 0;
    for (int r = 1; r <= m / n + 2; r++)
    {
        temp += a;
        if (temp.find(b) != string::npos)
            return r;
    }
    return -1;
}