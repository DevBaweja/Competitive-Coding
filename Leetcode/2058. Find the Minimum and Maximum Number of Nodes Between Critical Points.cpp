#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
        return {-1, -1};

    int prev = head->val;
    head = head->next;
    int cur = head->val;

    vector<int> critical;
    int count = 1;
    while (head->next)
    {
        int next = head->next->val;

        if ((prev < cur && cur > next) || (cur < prev && next > cur))
            critical.push_back(count);

        count++;
        prev = cur;
        cur = next;
        head = head->next;
    }

    int k = critical.size();
    if (k <= 1)
        return {-1, -1};

    int mini = INT_MAX;
    for (int i = 1; i < k; i++)
        mini = min(mini, critical[i] - critical[i - 1]);
    int maxi = critical[k - 1] - critical[0];
    return {mini, maxi};
}