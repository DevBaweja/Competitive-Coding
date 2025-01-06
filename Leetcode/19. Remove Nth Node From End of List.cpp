// Two Iteration
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* shead = head;
    int size = 0;
    while(shead) {
        shead = shead->next;
        size++;
    }
    int iter = size-n-1;
    ListNode* rhead = head;
    if(iter < -1)
        return NULL;
    if(iter == -1)
        return head->next;
    while(iter--) {
        rhead = rhead->next;
    }
    if(rhead->next)
        rhead->next = rhead->next->next;
    return head;
}

// One Iteration
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *fast = head, *slow = head;
    while(n--) {
        fast = fast->next;
    }
    if(!fast) return head->next;
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    if(slow->next)
        slow->next = slow->next->next;
    return head;
}