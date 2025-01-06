// Recursion
// Time - O(2^n)
// Space - O(2^n + n (recursive stack))
void subsetSumsUtil(vector<int> &arr, int index, int &n, int cur, 
vector<int> &res) {
    if(index == n) {
        res.push_back(cur);
        return;
    }
    // It is like DFS, we are going deep into one side then to other side
    // Take Element
    subsetSumsUtil(arr, index+1, n, cur+arr[index], res);
    // Don't Take Element
    subsetSumsUtil(arr, index+1, n, cur, res);
}

vector<int> subsetSums(vector<int> &arr, int n) {
    if(!n) return {};
    int cur = 0; 
    vector<int> res;
    subsetSumsUtil(arr, 0, n, cur, res);
    return res;
}

// Recursion and Backtracking
// Time - O(2^n)
// Space - O(2^n)  
void subsetSumsUtil(vector<int> &arr, int index, int &n, int cur, 
vector<int> &res) {
    res.push_back(cur);
    // This is backtracking
    // It is like BFS, making multiple calls by adding element one by one
    // At each element it make sure subset of size 0,1,2... is created level by level wise
    for(int idx = index; idx < n; idx++){
        cur += arr[idx];  // Include arr[idx] in the current sum
        subsetSumsUtil(arr, idx + 1, n, cur, res);  // Recur with next index
        cur -= arr[idx];  // Backtrack by removing arr[idx]
    }
    // This is recursion
    // Take Element
    // subsetSumsUtil(arr, index+1, n, cur+arr[index], res);
    // Don't Take Element
    // subsetSumsUtil(arr, index+1, n, cur, res);
}

vector<int> subsetSums(vector<int> &arr, int n) {
    if(!n) return {};
    int cur = 0; 
    vector<int> res;
    subsetSumsUtil(arr, 0, n, cur, res);
    return res;
}

// Power Set
// Bit Manipulation
// Time - O((2^n) * n)
// Space - O(2^n)
vector<int> subsetSums(vector<int> &arr, int n) {
    if(!n) return {};
    int power = 1<<n;
    vector<int> res;
    for(int val=0; val < power; val++) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            if(val & 1<<i) 
                sum += arr[i];
        }
        res.push_back(sum);
    }
    return res;
}

// BFS Iterative
// Time - O(n*(2^n))
// Space - O(2*(2^n))
vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> cur;
    cur.push_back(0);
    for(int i=0; i<n; i++) {
        vector<int> n;
        for(int el: cur)
            n.push_back(el);
        for(int el: cur)
            n.push_back(el + arr[i]);
        cur = n;
    }
    return cur;
}