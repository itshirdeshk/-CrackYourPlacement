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

// Q1. Validate Binary Search Tree.
void inorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

bool isValidBST(TreeNode *root)
{
    vector<int> ans;
    inorder(root, ans);
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] < ans[i + 1])
            continue;
        else
            return 0;
    }
    return 1;
}

// Q2. Binary Tree Right Side View.
vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    int count;

    while (!q.empty())
    {
        count = q.size();
        ans.push_back(q.back()->val);
        while (count--)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

// Q3. Binary Tree Level Order Traversal.
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        vector<int> helper;
        while (count--)
        {
            TreeNode *temp = q.front();
            helper.push_back(temp->val);
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ans.push_back(helper);
    }
    return ans;
}

int main() {}