#include<bits/stdc++.h>
using namespace std;

// Hashing and Counting
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    unordered_map<int, int> m;
    int count = 0;
    for(int el: v){
        if(m.find(el) == m.end())
            count += (el+1);
        else if(m[el] == el+1){
            count += m[el];
            m.erase(el);
        }
        m[el]++;
    }
    cout << count;
    return 0;
}

// Hashing and Dividing
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    unordered_map<int, int> m;
    int count = 0;
    for(int el: v)
        m[el]++;
        
    for(pair<int,int> p: m){
        p.first++;
        int rem = p.second % p.first;
        int quo = p.second / p.first;
        
        count += quo * p.first;
        if(rem)
            count  += p.first;
    }
    cout << count;
    return 0;
}