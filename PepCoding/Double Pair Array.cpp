#include<bits/stdc++.h>
using namespace std;

// Sorting and Hashing 
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    unordered_map<int, int> m;
    int count = 0;
    for(int el: v){
        m[el]++;
        if(el > 0){
            if(el%2==0 && m.find(el/2) != m.end()){
                count++;
                m[el/2]--;
                if(!m[el/2])
                    m.erase(el/2);
                m[el]--;
                if(!m[el])
                    m.erase(el);
            }
        }
        else{
            if(m.find(2*el) != m.end()){
                count++;
                m[2*el]--;
                if(!m[2*el])
                    m.erase(2*el);
                m[el]--;
                if(!m[el])
                    m.erase(el);
            }
        }
    }
    
    cout << (count == n/2 ? "true": "false");
    return 0;
}