#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#define mod 1000000007
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Node
{
    int data;
    Node *next;
    struct Node *bottom;
    struct Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
        random = NULL;
    }
};

// Q1. Reverse Nodes in k-Group.
int length(ListNode *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head->next)
        return head;
    int len = length(head);
    ListNode *first = new ListNode(0);
    first->next = head;
    head = first;
    int x;
    ListNode *second, *prev, *curr, *fut;

    while (len >= k && first->next)
    {
        x = k;
        second = first->next;
        prev = first;
        curr = second;

        while (x && curr)
        {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
            x--;
        }

        first->next = prev;
        second->next = curr;
        first = second;
        len -= k;
    }

    return head->next;
}

// Q2. Copy List with Random Pointer.
Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    while (temp)
    {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    temp = head;

    Node *curr1 = head, *curr2 = headCopy, *front1, *front2;
    while (curr1)
    {
        front1 = curr1->next;
        front2 = curr2->next;

        curr1->next = curr2;
        curr2->next = front1;

        curr1 = front1;
        curr2 = front2;
    }

    curr1 = head;
    while (curr1)
    {
        curr2 = curr1->next;
        if (curr1->random)
        {
            curr2->random = curr1->random->next;
        }
        curr1 = curr2->next;
    }

    curr1 = head;
    while (curr1->next)
    {
        front1 = curr1->next;
        curr1->next = front1->next;
        curr1 = front1;
    }

    return headCopy;
}