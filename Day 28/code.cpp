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

// Q1. Smallest Positive Missing.
int missingNumber(int arr[], int n)
{
    // Your code here
    for (int i = 0; i < n; i++)
    {

        // Loop to check boundary
        // condition and for swapping
        while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // Checking any element which
    // is not equal to i+1
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }

    // Nothing is present return last index
    return n + 1;
}

// Q2. Linked List Cycle.
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

// Q3. Reverse Linked List.
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *fut = NULL;
    while (curr != NULL)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    return prev;
}

// Q4. Palindrome Linked List.
bool isPalindrome(ListNode *head)
{

    if (head == NULL || head->next == NULL)
        return 1;

    // Count the number of Nodes
    int count = 0;
    ListNode *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count /= 2;

    ListNode *curr = head, *prev = NULL;
    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    ListNode *front = NULL;
    prev = NULL;

    while (curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }

    ListNode *head1 = head, *head2 = prev;
    while (head1)
    {
        if (head1->val != head2->val)
            return 0;
        head1 = head1->next;
        head2 = head2->next;
    }

    return 1;
}

// Q5. Intersection of Two Linked Lists.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == headB)
        return headA;
    int count1 = 0, count2 = 0;
    ListNode *curr1 = headA, *curr2 = headB;
    while (curr1->next != NULL)
    {
        count1++;
        curr1 = curr1->next;
    }

    while (curr2->next != NULL)
    {
        count2++;
        curr2 = curr2->next;
    }

    if (curr1 != curr2)
        return NULL;

    if (count1 - count2 > 0)
    {
        count1 = count1 - count2;
        count2 = 0;
    }
    else
    {
        count2 = count2 - count1;
        count1 = 0;
    }

    ListNode *newCurr1 = headA, *newCurr2 = headB;
    if (count1)
    {
        while (count1--)
            newCurr1 = newCurr1->next;
    }
    else
    {
        while (count2--)
            newCurr2 = newCurr2->next;
    }

    if (newCurr1 == newCurr2)
        return newCurr1;

    while (newCurr1->next != NULL && newCurr2->next != NULL)
    {
        newCurr1 = newCurr1->next;
        newCurr2 = newCurr2->next;

        if (newCurr1 == newCurr2)
            return newCurr1;
    }

    return NULL;
}

// Method 2:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return NULL;
    ListNode *a = headA, *b = headB;

    while (a != b)
    {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }

    return a;
}


int main() {}