#include<bits/stdc++.h>
using namespace std;

// Count Prefix Sum and Hashing
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
        
    int zeros = 0 , ones = 0 , twos = 0;
    unordered_map<string, int> m;
    m[to_string(0)+"#"+to_string(0)] = -1;
    int res = INT_MIN;
    for(int i=0; i<n; i++){
        int el = v[i];
        zeros += (v[i] == 0);
        ones += (v[i] == 1);
        twos += (v[i] == 2);
        int doz = ones-zeros;
        int dto = twos-ones;
        string key = to_string(doz) + "#" + to_string(dto);
        if(m.find(key) != m.end())
            res = max(res, i - m[key]);
        else
            m[key] = i;
    }
    if(res == INT_MIN) res = 0;
    cout << res;
    return 0;
}