/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.

You have to form a team of 3 soldiers amongst them under the following rules:

Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
A team is valid if:  (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

 

Example 1:

Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
Example 2:

Input: rating = [2,1,3]
Output: 0
Explanation: We can't form any team given the conditions.
Example 3:

Input: rating = [1,2,3,4]
Output: 4
 

Constraints:

n == rating.length
1 <= n <= 200
1 <= rating[i] <= 10^5
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int count = 0;
        for (int i = 0; i < rating.size(); i++)
            for (int j = i + 1; j < rating.size(); j++)
                for (int k = j + 1; k < rating.size(); k++)
                    if (((rating[i] < rating[j]) && (rating[j] < rating[k])) || (rating[i] > rating[j]) && (rating[j] > rating[k]))
                        count++;

        return count;
    }
};

class Solution
{
public:
    int numTeams(vector<int> &rating)
    {
        int total = 0;
        for (int middle = 1; middle < rating.size() - 1; middle++)
        {
            int less_left = 0;
            int more_left = 0;
            int less_right = 0;
            int more_right = 0;

            for (int left = 0; left < middle; left++)
            {
                if (rating[left] < rating[middle])
                    less_left++;
                if (rating[left] > rating[middle])
                    more_left++;
            }
            for (int right = middle + 1; right < rating.size(); right++)
            {
                if (rating[right] < rating[middle])
                    less_right++;
                if (rating[right] > rating[middle])
                    more_right++;
            }
            total += less_left * more_right + more_left * less_right;
        }
        return total;
    }
};