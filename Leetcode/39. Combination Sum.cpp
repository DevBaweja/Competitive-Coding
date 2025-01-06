// Recursion and Backtracking
// target/ min(n) cis max value that can be repeated - tree height
// n - tree width
// Time - O((n^(target/min(n))))
// target/min(n) - space for recursive calls
// Space - O(k*l)
// where k is # of valid combination
// and l is max size of each combination with will be target/min(n)
void combinationSumUtil(int idx, int &n, vector<int> cur, 
vector<vector<int>>& res, vector<int>& candidates, int target) {
    if(target < 0)
        return;
    if(!target) {
        res.push_back(cur);
        return;
    }
    for(int index=idx; index<n; index++) {
        cur.push_back(candidates[index]);
        target -= candidates[index];
        combinationSumUtil(index, n, cur, res, candidates, target);
        target += candidates[index];
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    vector<int> cur;
    vector<vector<int>> res;
    combinationSumUtil(0, n, cur, res, candidates, target);
    return res;
}