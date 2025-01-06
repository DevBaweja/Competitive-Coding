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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    vector<int> v1;
    while (l1)
    {
        v1.push_back(l1->val);
        l1 = l1->next;
    }
    vector<int> v2;
    while (l2)
    {
        v2.push_back(l2->val);
        l2 = l2->next;
    }

    int n = v1.size(), m = v2.size();
    int i = 0, j = 0;
    int k = 0;
    vector<int> v(n + m);
    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
            v[k++] = v1[i++];
        else
            v[k++] = v2[j++];
    }
    while (i < n)
        v[k++] = v1[i++];

    while (j < m)
        v[k++] = v2[j++];

    ListNode *dummy = new ListNode(-1);
    ListNode *root = dummy;
    for (int el : v)
    {
        dummy->next = new ListNode(el);
        dummy = dummy->next;
    }
    return root->next;
}

ListNode *mergeTwoLists(ListNode *head1, ListNode *head2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *root = dummy;

    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            dummy->next = head1;
            head1 = head1->next;
        }
        else
        {
            dummy->next = head2;
            head2 = head2->next;
        }
        dummy = dummy->next;
    }

    if (head1)
        dummy->next = head1;
    if (head2)
        dummy->next = head2;

    return root->next;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode();
    ListNode* thead = head;
    while(list1 && list2) {
        if(list1->val < list2->val) {
            head->next = list1;
            list1 = list1->next;
        } else {
            head->next = list2;
            list2 = list2->next;
        }
        head = head->next;
    }
    if(list1)
        head->next = list1;
    if(list2)
        head->next = list2;
    return thead->next;
}