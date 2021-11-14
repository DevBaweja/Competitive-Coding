#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int res = 0;
    for(int el: v)
        res ^= el;
    for(int el=1; el<=n; el++)
        res ^= el;
    
    int rsb = res & -res;
    int a = 0, b = 0;
    for(int el: v){
        if(rsb & el)
            a ^= el;
        else
            b ^= el;
    }
    for(int el=1; el<=n; el++){
        if(rsb & el)
            a ^= el;
        else
            b ^= el;
    }
    
    for(int el: v){
        if(el == a){
            swap(a,b);
            break;
        }
    }
    
    cout << "Missing Number" << " -> " << a << "\n";
    cout << "Repeating Number" << " -> " << b << "\n";
    return 0;
}