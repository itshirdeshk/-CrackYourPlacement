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

// Q1. LRU Cache.
class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};

Node *head = new Node(-1, -1);
Node *tail = new Node(-1, -1);

int cap;
unordered_map<int, Node *> m;

int LRUCache(int capacity)
{
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}

void addNode(Node *newnode)
{
    Node *temp = head->next;

    newnode->next = temp;
    newnode->prev = head;

    head->next = newnode;
    temp->prev = newnode;
}

void deleteNode(Node *delnode)
{
    Node *prevv = delnode->prev;
    Node *nextt = delnode->next;

    prevv->next = nextt;
    nextt->prev = prevv;
}

int get(int key)
{
    if (m.find(key) != m.end())
    {
        Node *resNode = m[key];
        int ans = resNode->val;

        m.erase(key);
        deleteNode(resNode);
        addNode(resNode);

        m[key] = head->next;
        return ans;
    }
    return -1;
}

void put(int key, int value)
{
    if (m.find(key) != m.end())
    {
        Node *curr = m[key];
        m.erase(key);
        deleteNode(curr);
    }

    if (m.size() == cap)
    {
        m.erase(tail->prev->key);
        deleteNode(tail->prev);
    }

    addNode(new Node(key, value));
    m[key] = head->next;
}

// Q2. Celebrity Problem.
int celebrity(vector<vector<int>> &mat)
{
    // code here
    int n = mat.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        if (mat[i][j] == 1)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    int candidate = i;

    for (int k = 0; k < n; k++)
    {
        if (k != candidate)
        {
            if (mat[candidate][k] == 1 || mat[k][candidate] == 0)
            {
                return -1;
            }
        }
    }
    return candidate;
}

int main() {}