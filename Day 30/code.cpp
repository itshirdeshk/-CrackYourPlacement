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

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Q1. Add Two Numbers II.
ListNode *rev(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *fut = NULL;
    while (curr != NULL)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    return prev;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    l1 = rev(l1);
    l2 = rev(l2);

    int carry = 0;
    ListNode *head = new ListNode(0);
    ListNode *temp = head;

    while (l1 && l2)
    {
        int num = l1->val + l2->val + carry;
        temp->next = new ListNode(num % 10);
        temp = temp->next;
        carry = num / 10;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1)
    {
        int num = l1->val + carry;
        temp->next = new ListNode(num % 10);
        temp = temp->next;
        carry = num / 10;
        l1 = l1->next;
    }
    while (l2)
    {
        int num = l2->val + carry;
        temp->next = new ListNode(num % 10);
        temp = temp->next;
        carry = num / 10;
        l2 = l2->next;
    }

    if (carry)
    {
        temp->next = new ListNode(carry);
    }

    head = rev(head->next);

    return head;
}

// Q2. Reverse Linked List II.
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || !head->next)
        return head;
    if (left == right)
        return head;
    int count = 1;
    ListNode *curr = head, *prev = NULL, *fut = NULL;
    while (count < left)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    ListNode *temp1 = prev, *temp2 = curr;

    while (count <= right)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
        count++;
    }

    if (!curr && !temp1)
    {
        head = prev;
        return head;
    }
    if (curr && !temp1)
    {
        head = prev;
    }

    if (temp1)
        temp1->next = prev;
    if (temp2)
        temp2->next = curr;

    return head;
}

// Q3. Remove Nth Node From End of List.
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;
    while (n--)
        fast = fast->next; // iterate first n nodes using fast
    if (!fast)
        return head->next; // if fast is already null, it means we have to delete
                           // head itself. So, just return next of head
    while (fast->next)     // iterate till fast reaches the last node of list
        fast = fast->next, slow = slow->next;
    slow->next = slow->next->next; // remove the nth node from last
    return head;
}

// Q4. Reorder List.
void reorderList(ListNode *head)
{
    if (!head->next || !head->next->next)
        return;
    int count = 0;
    ListNode *curr = head;
    while (curr)
    {
        count++;
        curr = curr->next;
    }

    count++;
    count /= 2;
    curr = head;
    ListNode *prev = NULL;

    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    prev = NULL;
    ListNode *fut = NULL;
    while (curr)
    {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }

    ListNode *curr1 = head, *curr2 = prev;

    while (curr1 && curr2)
    {
        fut = curr1->next;
        curr1->next = curr2;
        prev = curr2->next;
        curr2->next = fut;
        curr1 = fut;
        curr2 = prev;
    }
}

// Q5. Partition List.
ListNode *partition(ListNode *head, int x)
{
    if (!head || !head->next)
        return head;
    ListNode *head1 = new ListNode(0);
    ListNode *head2 = new ListNode(0);
    ListNode *temp2 = head1, *curr = head, *temp1 = head2;
    ListNode *fut = NULL;
    while (curr != NULL)
    {
        if (curr->val >= x)
        {
            fut = curr->next;
            temp2->next = curr;
            temp2 = temp2->next;
            curr = fut;
        }
        else
        {
            fut = curr->next;
            temp1->next = curr;
            temp1 = temp1->next;
            curr = fut;
        }
    }
    temp2->next = NULL;
    temp1->next = head1->next;
    return head2->next;
}

// Q6. Linked List in Zig-Zag fashion.
Node *zigZag(Node *head)
{
    // your code goes here
    if (!head->next)
        return head;
    Node *curr = head, *fut = head->next;
    bool check = 0;
    while (fut)
    {
        if (check == 0)
        {
            if (curr->data > fut->data)
            {
                swap(curr->data, fut->data);
            }
            curr = fut;
            fut = fut->next;
            check = 1;
        }
        else
        {
            if (curr->data < fut->data)
            {
                swap(curr->data, fut->data);
            }
            curr = fut;
            fut = fut->next;
            check = 0;
        }
    }

    return head;
}

// Q7. Sort List.
ListNode *middle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *temp = dummyHead;

    while (head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }
    }

    while (head1)
    {
        temp->next = head1;
        temp = temp->next;
        head1 = head1->next;
    }
    while (head2)
    {
        temp->next = head2;
        temp = temp->next;
        head2 = head2->next;
    }

    return dummyHead->next;
}

ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *mid = middle(head);
    ListNode *head2 = mid->next;
    mid->next = NULL;
    ListNode *finalHead = merge(sortList(head), sortList(head2));
    return finalHead;
}

// Q8. Segregate even and odd nodes in a Linked List.
Node *divide(Node *head)
{
    // code hereif(!head || !head -> next) return head;
    Node *head1 = new Node(0);
    Node *head2 = new Node(0);
    Node *temp2 = head1, *curr = head, *temp1 = head2;
    Node *fut = NULL;
    while (curr != NULL)
    {
        if (curr->data % 2 != 0)
        {
            fut = curr->next;
            temp2->next = curr;
            temp2 = temp2->next;
            curr = fut;
        }
        else
        {
            fut = curr->next;
            temp1->next = curr;
            temp1 = temp1->next;
            curr = fut;
        }
    }
    temp2->next = NULL;
    temp1->next = head1->next;
    return head2->next;
}

// Q9. Rearrange a linked list.
void rearrangeEvenOdd(Node *head)
{
    // Your Code here
    Node *head1 = new Node(0);
    Node *head2 = new Node(0);
    Node *temp2 = head1, *curr = head, *temp1 = head2;
    Node *fut = NULL;
    int count = 1;
    while (curr != NULL)
    {
        if (count % 2 == 0)
        {
            fut = curr->next;
            temp2->next = curr;
            temp2 = temp2->next;
            curr = fut;
        }
        else
        {
            fut = curr->next;
            temp1->next = curr;
            temp1 = temp1->next;
            curr = fut;
        }
        count++;
    }
    temp2->next = NULL;
    temp1->next = head1->next;
    head = head2->next;
}

// Q10. Merge k Sorted Lists.
// Method 1:
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy, *temp;
    dummy = new ListNode(0);
    temp = dummy;

    // when both list1 and list2 isn't empty
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // we reached at the end of one of the list
    if (list1)
        temp->next = list1;
    if (list2)
        temp->next = list2;

    return dummy->next;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    if (lists.size() == 1)
        return lists[0];

    ListNode *temp1 = lists[0];

    for (int i = 1; i < lists.size(); i++)
    {
        temp1 = mergeTwoLists(temp1, lists[i]);
    }

    return temp1;
}

// Method 2:
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy, *temp;
    dummy = new ListNode(0);
    temp = dummy;

    // when both list1 and list2 isn't empty
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // we reached at the end of one of the list
    if (list1)
        temp->next = list1;
    if (list2)
        temp->next = list2;

    return dummy->next;
}

void mergeSort(vector<ListNode *> &lists, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(lists, start, mid);
    mergeSort(lists, mid + 1, end);
    lists[start] = mergeTwoLists(lists[start], lists[mid + 1]);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    if (lists.size() == 1)
        return lists[0];

    mergeSort(lists, 0, lists.size() - 1);

    return lists[0];
}

// Q11. Flattening a Linked List.
Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *dummy, *temp;
    dummy = new Node(0);
    temp = dummy;

    // when both list1 and list2 isn't empty
    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            temp->bottom = list1;
            list1 = list1->bottom;
        }
        else
        {
            temp->bottom = list2;
            list2 = list2->bottom;
        }
        temp = temp->bottom;
    }

    // we reached at the end of one of the list
    if (list1)
        temp->bottom = list1;
    if (list2)
        temp->bottom = list2;

    return dummy->bottom;
}
// Function which returns the  root of the flattened linked list.
Node *flatten(Node *root)
{
    // Your code here
    if (!root || !root->next)
        return root;
    Node *temp1 = root, *temp2 = root->next, *temp3 = NULL;
    while (temp2)
    {
        temp1 = mergeTwoLists(temp1, temp2);
        temp2 = temp2->next;
    }
    return temp1;
}

int main() {}