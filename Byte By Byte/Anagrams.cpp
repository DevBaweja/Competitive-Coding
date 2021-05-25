#include <bits/stdc++.h>
using namespace std;
// Sorting
/*
bool isAnagrams(string s1, string s2){
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1!=n2)
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
   
    for(int i=0;i<n1;i++)
        if(s1[i] != s2[i])
            return false;
    return true;
}
*/
// Time - O(n*log(n))

// Count Frequency
/*
bool isAnagrams(string s1, string s2){
    // char 8 bits = 256
    int n = 256;
    vector<int> count1(n), count2(n);
    int n1 = s1.length();
    int n2 = s2.length();
    if(n1!=n2)
        return false;
       
    for(int i=0; i<n1; i++){
        count1[s1[i]]++;
        count2[s2[i]]++;
    }
   
    for(int i=0;i<n;i++)
        if(count1[i] != count2[i])
            return false;
    return true;
}
*/
// Time - O(n)

bool isAnagrams(string s1, string s2)
{
    // char 8 bits = 256
    int n = 256;
    vector<int> count(n);
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 != n2)
        return false;

    for (int i = 0; i < n1; i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    for (int i = 0; i < n; i++)
        if (count[i])
            return false;
    return true;
}
// Time - O(n)

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << isAnagrams(s1, s2);
    return 0;
}
