#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int low = 0, high = n - 1;
    // wrap
    if (target >= letters[high])
        return letters[low];
    int res = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (letters[mid] > target)
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return letters[res];
}