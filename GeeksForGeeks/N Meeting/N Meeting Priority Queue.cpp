#include <bits/stdc++.h>
using namespace std;

/*
    int maxMeetings(int start[], int end[], int n)
    {
        set<pair<int,int>> s;
        for(int i=0;i<n;i++)
            s.insert({end[i], start[i]});
        int count = 1;
        pair<int,int> prev = *(s.begin());
        s.erase(s.begin());
        while(!s.empty()){
            pair<int,int> next = *(s.begin());
            s.erase(s.begin());
            if(prev.first < next.second){
                count++;
                prev = next;
            }
        }
        return count;
    }
*/

int maxMeetings(int start[], int end[], int n)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    for (int i = 0; i < n; i++)
        pq.push({end[i], start[i]});
    int count = 1;
    pair<int, int> prev = pq.top();
    pq.pop();
    while (!pq.empty())
    {
        pair<int, int> next = pq.top();
        pq.pop();
        if (prev.first < next.second)
        {
            count++;
            prev = next;
        }
    }
    return count;
}