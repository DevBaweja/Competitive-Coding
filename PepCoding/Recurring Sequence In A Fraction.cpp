#include<bits/stdc++.h>
using namespace std;

// Hashing Remainder
string recurring(int a, int b){
    string res = "";
    int q = a/b;
    int r = a%b;
    res += to_string(q);
    if(!r)
        return res;
    res += '.';
    
    unordered_map<int,int> m;
    m[r] = res.size();
    while(r){
        r *= 10;
        q = r/b;
        r = r%b;
        res += to_string(q);
        if(m.find(r) != m.end())
            return res.substr(0, m[r]) + 
            "(" + res.substr(m[r], res.size() - m[r]) + ")";
        
        m[r] = res.size();
    }
    return res;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << recurring(a,b);
    return 0;
}