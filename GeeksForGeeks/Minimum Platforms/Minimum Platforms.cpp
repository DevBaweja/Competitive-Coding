#include <bits/stdc++.h>
using namespace std;

// Sort and Merge
// Time - O(2*nlog(n))
// Space - O(1)
int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0;
    int cur = 1, res = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            cur++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            cur--;
            j++;
        }
        res = max(res, cur);
    }
    return res;
}

// Looking from outside. Observing as trains arrives and departures
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    int cur = 0, res = 0;
    int i = 0, j = 0;
    while(i<n && j<n){
        if(arr[i] <= dep[j]) {
            cur++;
            i++;
        } else {
            cur--;
            j++;
        }
        res = max(res, cur);
    }
    return res;
}

// Time - O(2*nlog(n))
// Space - O(2*n)
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    // Merge two sorted array
    vector<pair<int, bool>> tim;
    int i = 0, j = 0;
    while(i<n && j<n) {
        if(arr[i] <= dep[j])
            tim.push_back({arr[i++], true});
        else 
            tim.push_back({dep[j++], false});
    }
    while(i<n) {
        tim.push_back({arr[i++], true});
    }
    while(j<n) {
        tim.push_back({dep[j++], false});
    }
    
    int cur = 0, res = 0;
    for(pair<int,int> el: tim){
        cur += el.second ? +1:-1;
        res = max(res, cur);
    }
    return res;
}

// Using Priority Queue
// Sort by departure time
struct comparePlatforms {
    // Min Heap (Logix is opposite to vector compare)
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

// Sort by arrival time
static bool compareTrains(pair<int,int> &a, pair<int,int> &b) {
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size();
    if(!n) return n;
    vector<pair<int,int>> trains(n);
    for(int i=0; i<n; i++) {
        trains[i] = {arr[i], dep[i]};
    }
    sort(trains.begin(), trains.end(), compareTrains);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, comparePlatforms> pq;
    int res = 1;
    pq.push(trains[0]);
    for(int next=1; next<n; next++) {
        while(!pq.empty() && pq.top().second < trains[next].first) {
            pq.pop();
        }
        pq.push(trains[next]);
        if(res < pq.size())
            res = pq.size();
    }
    
    return res;
}