#include<bits/stdc++.h>
using namespace std;

// Count Method
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int res = 0;
    int size = 32;
    for(int p=0; p<size; p++){
        int mask = (1<<p);
        int count = 0;
        for(int el: v)
            if(el & mask)
                count++;
        if(count%3)
            res |= mask;
    }
    cout << res;
}

// 3n, 3n+1, 3n+2 place Method
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int pa=INT_MAX, pb=0, pc=0;
    for(int el: v){
        int ca = el & pa;
        int cb = el & pb;
        int cc = el & pc;
        int na = pa & (~ca);
        int nb = pb & (~cb);
        int nc = pc & (~cc);
        na |= cc;
        nb |= ca;
        nc |= cb;
        pa = na;
        pb = nb;
        pc = nc;
    }
    
    cout << pb;
}

// Represent Count and Transition Function

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int pt = 0, po = 0;
    for(int el: v){
        int nt = (pt & (~po) & (~el)) | ((~pt) & po & el); 
        int no = ((~pt) & po & (~el)) | ((~pt) & (~po) & el);
        pt = nt;
        po = no;
    }
    cout << po;
}