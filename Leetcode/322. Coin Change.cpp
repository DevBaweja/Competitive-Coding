// Greedy don't work
int coinChange(vector<int>& coins, int sum) {
    int n = coins.size();
    if(!sum) return sum;
    sort(coins.begin(), coins.end());
    int res = 0;
    for(int i=n-1; i>=0; i--) {
        while(sum >= coins[i]) {
            sum -= coins[i];
            res++;
        }
    }
    if(sum) return -1;
    return res;
}

// Greedy don't work
// Removed inner while loop
int coinChange(vector<int>& coins, int sum) {
    int n = coins.size();
    if(!sum) return sum;
    sort(coins.begin(), coins.end());
    int res = 0;
    for(int i=n-1; i>=0; i--) {
        if(sum >= coins[i]) {
            int val = sum / coins[i];
            sum -= val*coins[i];
            res += val;
        }
    }
    if(sum) return -1;
    return res;
}

// Greedy don't work
// Using binary search to get next biggest to avoid looping from end
int coinChange(vector<int>& coins, int sum) {
    int n = coins.size();
    if(!sum) return sum;
    sort(coins.begin(), coins.end());
    int res = 0;
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (high-low)/2 + low;
        if(coins[mid] >= sum)
            high = mid-1;
        else
            low = mid+1;
    }
    if(low == n) {
        low = n-1;
    }
    for(int i=low; i>=0; i--) {
        if(sum >= coins[i]) {
            int val = sum / coins[i];
            sum -= val*coins[i];
            res += val;
        }
    }
    if(sum) return -1;
    return res;
}