#include <bits/stdc++.h> 
typedef long long ll;


void merge(ll *nums, ll l1, ll h1, ll l2, ll h2, ll &inv) {
    ll n = h1-l1+1; ll m = h2-l2+1;
    vector<ll> a(n), b(m);
    for(ll i=l1; i<=h1; i++)
        a[i-l1] = nums[i];
    for(ll j=l2; j<=h2; j++)
        b[j-l2] = nums[j];
    
    vector<ll> res(n+m);
    ll i = 0, j = 0, k = 0;
    while(i<n && j<m) {
        if(a[i] <= b[j]) {
            res[k++] = a[i++];
        }
        else {
            inv += n-i;
            res[k++] = b[j++];
        }
    }
    while(i<n) {
        res[k++] = a[i++];
    }
    while(j<m) {
        res[k++] = b[j++];
    }

    for(ll idx=0; idx<res.size(); idx++) {
        nums[idx+l1] = res[idx];
    }
}

void mergeSort(ll *nums, ll l, ll h, ll &inv) {
    if(l >= h)
        return;
    ll m = (l+h)/2;
    mergeSort(nums, l, m, inv);
    mergeSort(nums, m+1, h, inv);
    merge(nums, l, m, m+1, h, inv);
}


ll getInversions(ll *arr, int n){
    ll inv = 0;
    mergeSort(arr, 0, n-1, inv);
    return inv;
}