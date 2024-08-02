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

// Q1. Kth Smallest Element in a BST.
int result;
void smallest(TreeNode *root, int &count, int &k)
{
    if (!root)
        return;
    smallest(root->left, count, k);
    count++;
    if (count == k)
    {
        result = root->val;
        return;
    }
    smallest(root->right, count, k);
}

int kthSmallest(TreeNode *root, int k)
{
    int count = 0;
    smallest(root, count, k);
    return result;
}

// Q2. Binary Tree Zigzag Level Order Traversal.
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> ans;
    stack<TreeNode *> LR;
    stack<TreeNode *> RL;

    LR.push(root);
    while (!LR.empty() || !RL.empty())
    {
        vector<int> tempArr;
        if (!LR.empty())
        {
            while (!LR.empty())
            {
                TreeNode *temp = LR.top();
                LR.pop();
                tempArr.push_back(temp->val);
                if (temp->left)
                    RL.push(temp->left);
                if (temp->right)
                    RL.push(temp->right);
            }
        }
        else
        {
            while (!RL.empty())
            {
                TreeNode *temp = RL.top();
                RL.pop();
                tempArr.push_back(temp->val);
                if (temp->right)
                    LR.push(temp->right);
                if (temp->left)
                    LR.push(temp->left);
            }
        }
        ans.push_back(tempArr);
    }
    return ans;
}

int main() {}