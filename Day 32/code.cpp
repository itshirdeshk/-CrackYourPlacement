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
    struct Node *child;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
        random = NULL;
        random = NULL;
        prev = NULL;
    }
};

// Q1. Subtraction in Linked List.
int length(Node *n)
{
    int ret = 0;
    while (n)
    {
        ret++;
        n = n->next;
    }
    return ret;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next; // storing next node
        current->next = prev; // linking current node to previous
        prev = current;       // updating prev
        current = next;       // updating current
    }
    return prev;
}

Node *subLinkedList(Node *l1, Node *l2)
{
    while (l1 != NULL && l1->data == 0)
    {
        l1 = l1->next;
        // removing trailing zeroes from l1
    }
    while (l2 != NULL && l2->data == 0)
    {
        l2 = l2->next;
        // removing trailing zeroes from l2
    }
    int n1 = length(l1);
    int n2 = length(l2);
    if (n1 == 0 && n2 == 0)
    {
        return new Node(0);
    }
    if (n2 > n1)
    {
        std::swap(l1, l2);
        // making sure l1 list has the bigger number
    }
    if (n1 == n2)
    {
        Node *t1 = l1;
        Node *t2 = l2;
        while (t1->data == t2->data)
        {
            // finding which number is greater
            t1 = t1->next;
            t2 = t2->next;
            if (t1 == NULL)
            {
                return new Node(0);
                // returning zero if both numbers are same
            }
        }
        if (t2->data > t1->data)
        {
            std::swap(l1, l2);
            // making sure l1 list has the bigger number
        }
    }
    l1 = reverse(l1);
    l2 = reverse(l2);
    Node *res = NULL;
    Node *t1 = l1;
    Node *t2 = l2;
    while (t1 != NULL)
    {
        int small = 0;
        if (t2 != NULL)
        {
            small = t2->data;
            // 'small' holds the next digit of number to be subtracted
        }
        if (t1->data < small)
        {
            t1->next->data -= 1;
            t1->data += 10;
            // taking carry
        }
        Node *n = new Node(t1->data - small);
        // creating new node for storing difference
        n->next = res;
        res = n;
        t1 = t1->next;
        if (t2 != NULL)
        {
            t2 = t2->next;
        }
    }
    while (res->next != NULL && res->data == 0)
    {
        res = res->next;
        // removing trailing zeroes from result list
    }
    return res;
}

// Q2. Remove Duplicates from Sorted List II.
// Method 1:
ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *curr = head;
    unordered_map<int, int> m;
    while (curr)
    {
        m[curr->val]++;
        curr = curr->next;
    }

    curr = head;
    ListNode *prev = NULL;
    while (curr)
    {
        if (m[curr->val] > 1)
        {
            if (!prev)
            {
                curr = curr->next;
                head = curr;
            }
            else
            {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

// Method 2:
ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    // ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;

    while (head != NULL)
    {

        if (head->next != NULL && head->val == head->next->val)
        {

            while (head->next != NULL && head->val == head->next->val)
                head = head->next;

            prev->next = head->next;
        }

        else
            prev = prev->next;

        head = head->next;
    }

    return dummy->next;
}

// Q3. Flatten a Multilevel Doubly Linked List.
Node *flatten(Node *head)
{
    Node *ptr = head, *tmp_next, *runner;

    while (ptr)
    {
        if (ptr->child)
        {

            // Save the current next and connect the child to next
            tmp_next = ptr->next;
            ptr->next = ptr->child;
            ptr->next->prev = ptr;
            ptr->child = NULL;

            // Run till the end of the current list and connect last node to
            // saved next
            runner = ptr->next;
            while (runner->next)
                runner = runner->next;
            runner->next = tmp_next;
            if (runner->next)
                runner->next->prev = runner;
        }

        ptr = ptr->next;
    }

    return head;
}

// Q4. Valid Palindrome II.
bool find(string &s, int count, int start, int end)
{
    if (start > end)
        return true;
    if (count > 1)
        return false;

    if (s[start] == s[end])
    {
        return find(s, count, start + 1, end - 1);
    }
    else
    {
        return find(s, count + 1, start + 1, end) || find(s, count + 1, start, end - 1);
    }
}
bool validPalindrome(string s)
{
    return find(s, 0, 0, s.size() - 1);
}

// Q5. Sum of Subarray Minimums.
using ll = long long;
const int MOD = 1e9 + 7;
int sumSubarrayMins(vector<int> &nums)
{
    int length = nums.size();
    vector<int> left(length, -1);
    vector<int> right(length, length);
    stack<int> stk;

    for (int i = 0; i < length; ++i)
    {
        while (!stk.empty() && nums[stk.top()] >= nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            left[i] = stk.top();
        }
        stk.push(i);
    }

    stk = stack<int>();

    for (int i = length - 1; i >= 0; --i)
    {
        while (!stk.empty() && nums[stk.top()] > nums[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            right[i] = stk.top();
        }
        stk.push(i);
    }

    ll sum = 0;

    for (int i = 0; i < length; ++i)
    {
        sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
        sum %= MOD;
    }

    return sum;
}

// Q6. Evaluate Reverse Polish Notation.
int evalRPN(vector<string> &tokens)
{
    stack<int> stn;
    for (auto s : tokens)
    {
        if (s.size() > 1 || isdigit(s[0]))
            stn.push(stoi(s));
        else
        {
            auto x2 = stn.top();
            stn.pop();
            auto x1 = stn.top();
            stn.pop();
            switch (s[0])
            {
            case '+':
                x1 += x2;
                break;
            case '-':
                x1 -= x2;
                break;
            case '*':
                x1 *= x2;
                break;
            case '/':
                x1 /= x2;
                break;
            }
            stn.push(x1);
        }
    }
    return stn.top();
}

// Q7. Remove All Adjacent Duplicates in String II.
// Method 1:
string removeDuplicates(string s, int k)
{
    stack<pair<char, pair<int, int>>> st;
    int i = 0;
    while (i < s.size())
    {
        if (!st.empty())
        {
            if (s[i] == st.top().first)
            {
                if (i - st.top().second.first + 1 == k)
                {
                    s.erase(st.top().second.first, k);
                    st.pop();
                    i = i - k + 1;
                }
                else
                {
                    int old_index = st.top().second.first;
                    st.pop();
                    st.push({s[i], {old_index, i}});
                    i++;
                }
            }
            else
            {
                st.push({s[i], {i, i}});
                i++;
            }
        }
        else
        {
            st.push({s[i], {i, i}});
            i++;
        }
    }

    return s;
}

// Method 2:
string removeDuplicates(string s, int k)
{
    vector<pair<char, short>> st;
    string res;
    for (auto ch : s)
    {
        if (st.empty() || st.back().first != ch)
            st.push_back({ch, 0});
        if (++st.back().second == k)
            st.pop_back();
    }
    for (auto &p : st)
        res += string(p.second, p.first);
    return res;
}

// Q8. Flatten Nested List Iterator.
// class NestedInteger
// {
// public:
//     bool isInteger() const;
//     int getInteger() const;
//     const vector<NestedInteger> &
//     getList() const;
// };
// int NestedIterator(vector<NestedInteger> &nestedList)
// {
//     int size = nestedList.size();
//     for (int i = size - 1; i >= 0; --i)
//     {
//         nodes.push(nestedList[i]);
//     }
// }
// stack<NestedInteger> nodes;

// int next()
// {
//     // Ensure the top of the stack contains an integer
//     int result = nodes.top().getInteger();
//     nodes.pop();
//     return result;
// }

// bool hasNext()
// {
//     // Process the stack until we find an integer
//     while (!nodes.empty())
//     {
//         NestedInteger curr = nodes.top();
//         if (curr.isInteger())
//         {
//             return true;
//         }

//         nodes.pop();
//         vector<NestedInteger> &adjs = curr.getList();
//         int size = adjs.size();
//         for (int i = size - 1; i >= 0; --i)
//         {
//             nodes.push(adjs[i]);
//         }
//     }

//     return false;
// }

int main() {}