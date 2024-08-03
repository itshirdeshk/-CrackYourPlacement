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
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Q1. Largest BST.
class info
{
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};
info solve(Node *root, int &maxisize)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN, true, 0};
    }

    info left = solve(root->left, maxisize);
    info right = solve(root->right, maxisize);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST and right.isBST and (left.maxi < root->data and root->data < right.mini))
        currNode.isBST = true;

    else
        currNode.isBST = false;

    if (currNode.isBST)
    {
        maxisize = max(currNode.size, maxisize);
    }

    return currNode;
}

int largestBst(Node *root)
{
    int maxisize = 0;
    info temp = solve(root, maxisize);
    return maxisize;
}

// Q2. Climbing Stairs.
// Method 1:
int step(int curr, int &n, vector<int> &dp)
{
    if (curr == n)
        return 1;
    if (curr > n)
        return 0;

    if (dp[curr] != -1)
        return dp[curr];

    return dp[curr] = step(curr + 1, n, dp) + step(curr + 2, n, dp);
}
int climbStairs(int n)
{
    vector<int> dp(n + 2, -1);
    return step(0, n, dp);
}

// Method 2:
int climbStairs(int n)
{
    vector<int> dp(n + 2, -1);
    dp[n] = 1;
    dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1] + dp[i + 2];
    }
    return dp[0];
}

// Method 3:
int climbStairs(int n)
{
    int last1 = 1, last2 = 0;
    int result;
    for (int i = n - 1; i >= 0; i--)
    {
        result = last1 + last2;
        last2 = last1;
        last1 = result;
    }
    return result;
}

// Q3. 
vector<int> countBits(int n)
{
    vector<int> ans(n + 1, -1);
    for (int i = 0; i <= n; i++)
    {
        int num = i;
        int count = 0;
        while (num)
        {
            if (ans[num] != -1)
            {
                count += ans[num];
                break;
            }
            else
            {
                if (num & 1 == 1)
                    count++;
                num = num >> 1;
            }
        }
        ans[i] = count;
    }

    return ans;
}

int main() {}