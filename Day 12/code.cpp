#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// Q1. Unique Binary Search Trees.
int numTrees(int n)
{
    long ans = 1;
    for (int i = 0; i < n; i++)
        ans *= (4 * i + 2) / (i + 2.);
    return ans;
}

// Q2. Recover Binary Search Tree.
TreeNode *first1, *last1, *prev1;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (prev1 != NULL && (root->val < prev1->val))
    {
        if (first1 == NULL)
        {
            first1 = prev1;
            last1 = root;
        }
        else
            last1 = root;
    }
    prev1 = root;
    inorder(root->right);
}
void recoverTree(TreeNode *root)
{
    first1 = last1 = prev1 = NULL;
    inorder(root);
    swap(first1->val, last1->val);
}

int main() {}