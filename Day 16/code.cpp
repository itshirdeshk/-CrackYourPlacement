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

// Q1. Flatten Binary Tree to Linked List.
void flatten(TreeNode *root)
{
    while (root)
    {
        if (!root->left)
            root = root->right;
        else
        {
            TreeNode *curr = root->left;
            while (curr->right)
                curr = curr->right;
            curr->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
}

int main() {}