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

// Reverse
bool isPalindrome(ListNode *head)
{
    string s = "";
    while (head)
    {
        s += head->val;
        head = head->next;
    }
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}
// Slow Fast Pointer and Split
ListNode *reverse(ListNode *root)
{
    if (!root)
        return NULL;
    ListNode *prev = NULL, *cur = root;
    while (cur)
    {
        ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
bool isPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *root = slow->next;
    slow->next = NULL;
    root = reverse(root);

    while (root)
    {
        if (root->val != head->val)
            return false;
        root = root->next;
        head = head->next;
    }
    return true;
}
// TODO Recursion