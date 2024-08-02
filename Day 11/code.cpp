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

// Q1. Path Sum III.
int counter = 0;
void path(TreeNode *root, long sum)
{
    if (!root)
        return;
    if (root->val == sum)
        counter++;
    path(root->left, sum - root->val);
    path(root->right, sum - root->val);
}

int pathSum(TreeNode *root, int targetSum)
{
    if (root)
    {
        path(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }

    return counter;
}

// Q2. Construct Binary Tree from Preorder and Postorder Traversal.
int preIndex = 0, posIndex = 0;
TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    TreeNode *root = new TreeNode(pre[preIndex++]);
    if (root->val != post[posIndex])
        root->left = constructFromPrePost(pre, post);
    if (root->val != post[posIndex])
        root->right = constructFromPrePost(pre, post);
    posIndex++;
    return root;
}

int main() {}