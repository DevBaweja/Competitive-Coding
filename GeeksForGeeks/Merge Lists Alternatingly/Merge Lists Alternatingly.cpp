#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void mergeList(struct Node **p, struct Node **q)
{
    Node *pc = *p, *qc = *q;
    Node *pn, *qn;
    Node *prev;
    while (pc && qc)
    {
        pn = pc->next;
        qn = qc->next;

        qc->next = pn;
        pc->next = qc;

        prev = pc;
        pc = pn;
        qc = qn;
    }
    // if(!pc)
    // prev->next = qc;
    // *q = NULL;
    *q = qc;
}