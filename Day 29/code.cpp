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

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Q1. Multiply two linked lists.
long long multiplyTwoLists(Node *l1, Node *l2)
{
    // code here
    long long num1 = 0, num2 = 0;
    Node *temp1 = l1, *temp2 = l2;
    while (temp1)
    {
        num1 = ((num1 * 10) + temp1->data) % mod;
        temp1 = temp1->next;
    }

    while (temp2)
    {
        num2 = ((num2 * 10) + temp2->data) % mod;
        temp2 = temp2->next;
    }

    long long ans = (num1 * num2) % mod;

    return ans;
}

// Q2. Sort a linked list of 0s, 1s and 2s.
Node *sortList(Node *head)
{
    if (!head || !(head->next))
        return head;

    // Create three dummy nodes to point to beginning of
    // three linked lists. These dummy nodes are created to
    // avoid null checks.
    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);

    // Initialize current pointers for three
    // lists
    Node *zero = zeroD, *one = oneD, *two = twoD;

    // Traverse list
    Node *curr = head;
    while (curr)
    {
        if (curr->data == 0)
        {

            // If the data of current node is 0,
            // append it to pointer zero and update zero
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {

            // If the data of current node is 1,
            // append it to pointer one and update one
            one->next = curr;
            one = one->next;
        }
        else
        {
            // If the data of current node is 2,
            // append it to pointer two and update two
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    // Combine the three lists
    zero->next = (oneD->next) ? (oneD->next) : (twoD->next);
    one->next = twoD->next;
    two->next = NULL;

    // Updated head
    head = zeroD->next;

    // Delete dummy nodes
    delete zeroD;
    delete oneD;
    delete twoD;

    return head;
}

// Q3. Convert Binary Number in a Linked List to Integer.
int getDecimalValue(ListNode *head)
{
    int count = 0;
    ListNode *curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    count--;
    curr = head;
    int ans = 0;
    while (curr != NULL)
    {
        ans += (curr->val * pow(2, count));
        count--;
        curr = curr->next;
    }
    return ans;
}

// Q4. Remove Duplicates from Sorted List.
ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *curr = head, *front = head->next;

    while (curr != NULL && front != NULL)
    {
        if (curr->val == front->val)
        {
            curr->next = front->next;
            front = front->next;
        }
        else
        {
            front = front->next;
            curr = curr->next;
        }
    }

    return head;
}

// Q5. Remove Linked List Elements.
ListNode *removeElements(ListNode *head, int val)
{
    if (!head)
        return head;

    while (head && head->val == val)
        head = head->next;
    if (!head || !head->next)
        return head;
    ListNode *curr = head, *front = head->next;

    while (curr != NULL && front != NULL)
    {
        if (front->val == val)
        {
            curr->next = front->next;
            front = front->next;
        }
        else
        {
            curr = curr->next;
            front = front->next;
        }
    }

    return head;
}

// Q6. Delete nodes having greater value on right.
Node *compute(Node *head)
{
    // your code goes here
    head = rev(head);
    int max = head->data;
    Node *curr = head->next;
    Node *prev = head;

    while (curr != NULL)
    {
        if (curr->data >= max)
        {
            prev = curr;      // deleting prev
            max = curr->data; // storing max val of curr in max then return maxval
        }
        else
        {
            prev->next = curr->next; // when curr data is < max make two jumps
        }
        curr = curr->next;
    }
    return rev(head);
}
Node *rev(Node *head)
{
    Node *curr = head;
    Node *prev = nullptr;
    Node *temp = nullptr;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

// Q7. Add Two Numbers.
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int c = 0;
    ListNode newHead(0);
    ListNode *t = &newHead;
    while (c || l1 || l2)
    {
        c += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        t->next = new ListNode(c % 10);
        t = t->next;
        c /= 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
    }
    return newHead.next;
}

int main() {}