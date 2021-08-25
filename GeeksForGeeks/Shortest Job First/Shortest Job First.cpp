#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int arrival;
    int burst;
};

static int compareArrival(Process a, Process b)
{
    if (a.arrival == b.arrival)
    {
        if (a.burst == b.burst)
            return a.id < b.id;
        else
            return a.burst < b.burst;
    }
    return a.arrival < b.arrival;
}

struct compareBurst
{
    bool operator()(Process a, Process b)
    {
        return a.arrival < b.arrival;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<Process> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].id;
        cin >> A[i].arrival;
        cin >> A[i].burst;
    }
    sort(A.begin(), A.end(), compareArrival);
    priority_queue<Process, vector<Process>, compareBurst> pq;
    pq.push(A[0]);
    vector<int> res;
    int i = 1;
    int time = 0;
    while (!pq.empty())
    {
        Process p = pq.top();
        pq.pop();
        res.push_back(p.id);
        time += p.burst;
        while (i < n && A[i].arrival <= time)
            pq.push(A[i++]);
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}