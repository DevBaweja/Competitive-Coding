// Time - O(2n)
// Since k is large, mod need to be done first
// IF k<number of nodes, then we could use slow n fast pointer
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !k) return head;
    ListNode *temp = head;
    int c = 0;
    while(temp) {
        temp = temp->next;
        c++;
    }
    int km = k%c;
    if(!km)
        return head;
    // last nth node
    int last = c-km-1;
    ListNode *cur = head;
    while(last--) {
        cur = cur->next;
    }
    ListNode *node = cur->next;
    cur->next = NULL;
    ListNode *tnode = node;
    while(tnode->next) {
        tnode = tnode->next;
    }
    tnode->next = head;
    return node;
}

// Slow n Fast Pointer
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !k) return head;
    ListNode *temp = head;
    int c = 0;
    while(temp) {
        temp = temp->next;
        c++;
    }
    int km = k%c;
    if(!km)
        return head;

    // If k < n
    ListNode *slow = head, *fast = head;
    while(km--) {
        fast = fast->next;
    }
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* node = slow->next;
    slow->next = NULL;
    fast->next = head;
    return node;
}