// Using Greedy
static bool compare(pair<int,int> &a, pair<int,int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int maxMeetings(int n, int start[], int end[]) {
    if(!n) return n;
    vector<pair<int,int>> meetings(n);
    for(int i=0; i<n; i++) {
        meetings[i] = {start[i], end[i]};
    }
    sort(meetings.begin(), meetings.end(), compare);
    
    vector<pair<int,int>> res;
    
    int cur = 0;
    int ans = 1;
    res.push_back(meetings[cur]);
    for(int next=1; next<n; next++) {
        if(meetings[cur].second < meetings[next].first) {
            cur = next;
            res.push_back(meetings[cur]);
            ans++;
        }
            
    }
    return ans;
}

// Using Priority Queue
// Min Heap
struct compare {
    // Min Heap (Logix is opposite to vector compare)
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        if(a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

int maxMeetings(int n, int start[], int end[]) {
    if(!n) return n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
    for(int i=0; i<n; i++) {
        pq.push({start[i], end[i]});
    }
    
    vector<pair<int,int>> res;
    
    int ans = 1;
    pair<int, int> cur = pq.top();
    pq.pop();
    res.push_back(cur);
    while(!pq.empty()) {
        if(cur.second < pq.top().first) {
            cur = pq.top();
            res.push_back(cur);
            ans++;
        }
        pq.pop();
    }
    
    return ans;
}