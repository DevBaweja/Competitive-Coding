#include <bits/stdc++.h>
using namespace std;

vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3)
{
    int size = 100;
    vector<bool> v1(size + 1, 0), v2(size + 1, 0), v3(size + 1, 0);
    for (int el : nums1)
        v1[el] = 1;
    for (int el : nums2)
        v2[el] = 1;
    for (int el : nums3)
        v3[el] = 1;
    vector<int> res;
    int req = 2;
    for (int i = 0; i <= size; i++)
    {
        if (v1[i] + v2[i] + v3[i] >= req)
            res.push_back(i);
    }
    return res;
}