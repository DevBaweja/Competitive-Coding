#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

static int compare(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    vector<int> slots(n + 1, 0);
    int p = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead); j >= 1; j--)
        {
            if (!slots[j])
            {
                k += 1;
                p += arr[i].profit;
                slots[j] = 1;
                break;
            }
        }
    }

    return {k, p};
}