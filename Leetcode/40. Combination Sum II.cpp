// Recursion and Backtracking
void combinationSumUtil(int idx, int &n, vector<int> cur, 
vector<vector<int>>& res, vector<int>& candidates, int target) {
    if(target < 0)
        return;
    if(!target) {
        res.push_back(cur);
        return;
    }
    for(int index=idx; index<n; index++) {
        if(index != idx && candidates[index-1] == candidates[index]) continue;
        cur.push_back(candidates[index]);
        target -= candidates[index];
        combinationSumUtil(index+1, n, cur, res, candidates, target);
        target += candidates[index];
        cur.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n = candidates.size();
    sort(candidates.begin(), candidates.end());
    vector<int> cur;
    vector<vector<int>> res;
    combinationSumUtil(0, n, cur, res, candidates, target);
    return res;
}