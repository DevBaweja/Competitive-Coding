#include <bits/stdc++.h>
using namespace std;

int findZeroes(int A[], int n, int m)
{
    int low = 0, high = 0;
    int count = m;
    int maxLen = 0;
    int len = 0;
    while (high < n)
    {
        if (A[high])
        {
            len++;
            high++;
        }
        else
        {
            if (count)
            {
                count--;
                len++;
                high++;
            }
            else
            {
                if (A[low])
                    low++;
                else
                {
                    low++;
                    count++;
                }
                len--;
            }
        }
        maxLen = max(len, maxLen);
    }
    return maxLen;
}