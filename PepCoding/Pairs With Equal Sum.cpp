#include<bits/stdc++.h>
using namespace std;

// Hashing
bool getPairSum(vector<int> &v, int n){
    unordered_set<int> m;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(m.find(v[i]+v[j]) != m.end())
                return true;
            m.insert(v[i]+v[j]);
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    cout << (getPairSum(v,n)? "true":"false");
    
}