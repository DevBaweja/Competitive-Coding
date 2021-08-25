#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int sum = 0, diff = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        sum += p[i].petrol - p[i].distance;
        if (sum < 0)
        {
            start = i + 1;
            diff += sum;
            sum = 0;
        }
    }
    if (sum + diff < 0)
        return -1;
    return start;
}