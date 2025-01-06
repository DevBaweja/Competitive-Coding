#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    double fvalue = 0;
    sort(arr, arr + n, cmp);
    double currWeight = 0;
    for (int i = 0; i < n; i++)
    {
        Item el = arr[i];
        if (currWeight + el.weight <= W)
        {
            currWeight += el.weight;
            fvalue += el.value;
        }
        else
        {
            double remain = W - currWeight;
            fvalue += ((double)el.value / (double)el.weight) * remain;
            break;
        }
    }
    return fvalue;
}

static bool compare(Item &a, Item &b) {
    return ((double)a.value/a.weight) > ((double)b.value/b.weight);
}
double fractionalKnapsack(int w, Item arr[], int n) {
    sort(arr, arr+n, compare);
    int cur = 0;
    double res = 0;
    while(cur < n && arr[cur].weight <= w) {
        res += arr[cur].value;
        w -= arr[cur].weight;
        cur++;
    }
    if(w && cur<n) {
        res += w*((double)arr[cur].value/arr[cur].weight);
    }
    return res;
}