#include <bits/stdc++.h>
using namespace std;

// Binary Search
vector<int> find(int arr[], int n, int x)
{
    int left, right;
    left = 0;
    right = n - 1;
    pair<int, int> res = make_pair(-1, -1);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (x == arr[mid])
        {
            res.first = mid;
            right = mid - 1;
        }
        else if (x > arr[mid])
            left = mid + 1;
        else if (x < arr[mid])
            right = mid - 1;
    }
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (x == arr[mid])
        {
            res.second = mid;
            left = mid + 1;
        }
        else if (x > arr[mid])
            left = mid + 1;
        else if (x < arr[mid])
            right = mid - 1;
    }
    return {res.first, res.second};
}

// Binary Search
vector<int> find(int arr[], int n, int x)
{
    int left, right;
    left = 0;
    right = n - 1;
    pair<int, int> res = make_pair(-1, -1);
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && x == arr[mid])
        {
            res.first = mid;
            break;
        }
        else if (x > arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    left = 0;
    right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && x == arr[mid])
        {
            res.second = mid;
            break;
        }
        else if (x < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return {res.first, res.second};
}
