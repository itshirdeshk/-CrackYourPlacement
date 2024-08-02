#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Q1. Populating Next Right Pointers in Each Node.
Node *connect(Node *root)
{
    if (!root)
        return root;
    queue<Node *> q;
    Node *fut = NULL;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            Node *curr = q.front();
            q.pop();
            curr->next = fut;
            if (curr->right)
                q.push(curr->right);
            if (curr->left)
                q.push(curr->left);
            fut = curr;
        }
        fut = NULL;
    }

    return root;
}