// Greedy don't work
int minCoins(vector<int> &coins, int sum) {
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