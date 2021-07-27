#include <bits/stdc++.h>
using namespace std;

int numTeams(vector<int> &rating)
{
    int n = rating.size();
    int total = 0;
    for (int middle = 1; middle < n - 1; middle++)
    {
        int less_left = 0;
        int more_left = 0;
        int less_right = 0;
        int more_right = 0;

        for (int left = 0; left < middle; left++)
        {
            if (rating[left] < rating[middle])
                less_left++;
            if (rating[left] > rating[middle])
                more_left++;
        }
        for (int right = middle + 1; right < n; right++)
        {
            if (rating[right] < rating[middle])
                less_right++;
            if (rating[right] > rating[middle])
                more_right++;
        }
        total += less_left * more_right + more_left * less_right;
    }
    return total;
}