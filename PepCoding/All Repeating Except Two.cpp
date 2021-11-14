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
    
    int rsb = res & -res;
    
    int a = 0, b = 0;
    for(int el: v){
        if(el & rsb) 
            a ^= el;
        else
            b ^= el;
    }
    if(a > b)
        swap(a,b);
    cout << a << "\n" << b << "\n";
    return 0;
}