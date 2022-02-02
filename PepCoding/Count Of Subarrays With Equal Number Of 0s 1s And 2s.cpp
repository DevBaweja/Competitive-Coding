#include<bits/stdc++.h>
using namespace std;

// Count Prefix Sum and Hashing
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
        
    int zeros = 0, ones = 0, twos = 0;
    unordered_map<string, int> m;
    m[to_string(0)+"#"+to_string(0)] = 1;
    int count = 0;
    
    for(int i=0; i<n; i++){
        int el = v[i];
        zeros += (el==0);
        ones += (el==1);
        twos += (el==2);
        int doz = ones - zeros, dto = twos - ones;
        string key = to_string(doz) + "#" + to_string(dto);
        if(m.find(key) != m.end())
            count += m[key];
        m[key]++;
    }
    cout << count;
    return 0;
}