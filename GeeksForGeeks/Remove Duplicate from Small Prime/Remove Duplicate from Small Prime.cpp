#include <bits/stdc++.h>
using namespace std;

/*
    vector<int> removeDuplicate(vector<int>& arr, int n){
      unordered_map<int,int> m;
      vector<int> res;
      for(int i=0;i<arr.size();i++){
            if(!m[arr[i]])
            {
                m[arr[i]] = 1;
                res.push_back(arr[i]);
            }
      }
      return res;
    }
*/

vector<int> removeDuplicate(vector<int> &arr, int n)
{
    vector<int> res;
    long long int p = arr[0];
    res.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (p % arr[i] != 0)
        {
            res.push_back(arr[i]);
            p *= arr[i];
        }
    }
    return res;
}

/*
    vector<int> removeDuplicate(vector<int>& arr, int n){
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> res;
        res.assign(s.begin(), s.end());
        reverse(res.begin(), res.end());
        return res;
    }
*/