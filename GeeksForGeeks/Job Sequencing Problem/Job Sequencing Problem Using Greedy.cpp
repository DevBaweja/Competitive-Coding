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



// Incorrect
static bool compare(Job &a, Job &b) {
    if(a.profit == b.profit)    
        return a.dead < b.dead;
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    if(!n) return {0,0};
    sort(arr, arr+n, compare);
    int res = 0;
    int profit = 0;
    for(int i=0; i<n; i++){
        // Can lead to multiple job scheduled to same slot
        if(arr[i].dead >= res+1) {
            profit += arr[i].profit;
            res++;
        }
    }
    return {res, profit};
} 

// Time - O(n*log(n) + n*d)
// Do the most profitable job
static bool compare(Job &a, Job &b) {
    if(a.profit == b.profit)    
        return a.dead < b.dead;
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job arr[], int n) 
{ 
    if(!n) return {0,0};
    sort(arr, arr+n, compare);
    int deadline = 0;
    for(int i=0; i<n; i++)
        deadline = max(deadline, arr[i].dead);
    // Delay the jobs
    vector<int> slots(deadline, 0);
    int res = 0;
    int profit = 0;
    for(int i=0; i<n; i++){
        for(int j=min(deadline-1, arr[i].dead-1); j>=0; j--){
            if(!slots[j]) {
                profit += arr[i].profit;
                res++;
                slots[j] = 1;
                break;
            }
        }
    }
    return {res, profit};
} 

// TODO
// Inner Loop can be optimized using Disjoint Set Union