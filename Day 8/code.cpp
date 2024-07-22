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

// Q1. Diameter of Binary Tree.
int diameterOfBinaryTree(TreeNode *root)
{
    int d = 0;
    rec(root, d);
    return d;
}

int rec(TreeNode *root, int &d)
{
    if (root == NULL)
        return 0;
    int ld = rec(root->left, d);
    int rd = rec(root->right, d);
    d = max(d, ld + rd);
    return max(ld, rd) + 1;
}

// Q2. Invert Binary Tree.
void mirror(TreeNode *root)
{
    if (root == nullptr)
        return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
}

TreeNode *invertTree(TreeNode *root)
{
    mirror(root);
    return root;
}

// Q3. Subtree of Another Tree.
bool preorder(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return 1;
    if (root == NULL && subRoot != NULL)
        return 0;
    if (root != NULL && subRoot == NULL)
        return 0;
    if (root->val != subRoot->val)
        return 0;
    return preorder(root->left, subRoot->left) && preorder(root->right, subRoot->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (root == NULL && subRoot == NULL)
        return 1;
    if (root == NULL && subRoot != NULL)
        return 0;
    if (root != NULL && subRoot == NULL)
        return 1;
    if (root->val == subRoot->val)
    {
        TreeNode *temp1 = root;
        TreeNode *temp2 = subRoot;
        if (preorder(temp1, temp2))
            return 1;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Q4. Range Sum of BST.
void preorder(TreeNode *root, int low, int high, int &sum)
{
    if (root == NULL)
        return;
    if (root->val >= low && root->val <= high)
        sum += root->val;
    if (root->val >= low)
        preorder(root->left, low, high, sum);
    if (root->val <= high)
        preorder(root->right, low, high, sum);
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;
    int sum = 0;
    preorder(root, low, high, sum);
    return sum;
}

// Q5. Symmetric Tree.
bool check(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;

    return (root1->val == root2->val && check(root1->left, root2->right) &&
            check(root1->right, root2->left));
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return 1;
    return check(root->left, root->right);
}

// Q6. Convert Sorted Array to Binary Search Tree.
TreeNode *create(int start, int end, vector<int> &nums)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = create(start, mid - 1, nums);
    root->right = create(mid + 1, end, nums);
    return root;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    return create(start, end, nums);
}

// Q7. Merge Two Binary Trees.
TreeNode *merge(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;
    if (root1 == NULL && root2 != NULL)
    {
        root1 = new TreeNode(root2->val);
    }
    else if (root1 != NULL && root2 == NULL)
        return root1;
    else
    {
        root1->val = root1->val + root2->val;
    }
    root1->left = merge(root1->left, root2->left);
    root1->right = merge(root1->right, root2->right);
    return root1;
}

TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return NULL;
    if (root1 != NULL && root2 == NULL)
        return root1;
    if (root1 == NULL && root2 != NULL)
        return root2;
    merge(root1, root2);
    return root1;
}

// Q8. Maximum Depth of Binary Tree.
int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}
int maxDepth(TreeNode *root)
{
    return height(root);
}

// Q9. Binary Tree Paths.
void path(TreeNode *root, vector<string> &ans, string str)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        str += to_string(root->val);
        ans.push_back(str);
    }

    char c = root->val;
    str += to_string(root->val);
    str += "->";
    path(root->left, ans, str);
    path(root->right, ans, str);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    path(root, ans, "");
    return ans;
}

// Q10. Same Tree.
bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return 1;
    if (!p || !q)
        return 0;

    if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))
        return 1;
    return 0;
}

// Q11. Lowest Common Ancestor of a Binary Search Tree.
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (p == root || q == root)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (right == NULL)
        return left;
    if (left == NULL)
        return right;
    return root;
}

// Q12. Path Sum.
bool check(TreeNode *root, int sum, int &targetSum)
{
    if (!root)
        return 0;
    if (!(root->left) && !(root->right) && sum + root->val == targetSum)
    {
        return 1;
    }
    return check(root->left, sum + root->val, targetSum) || check(root->right, sum + root->val, targetSum);
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    return check(root, 0, targetSum);
}

// Q13. Minimum Absolute Difference in BST.
void minAbs(TreeNode *root, int &prev, int &ans)
{
    if (!root)
        return;
    minAbs(root->left, prev, ans);
    if (prev != INT_MIN)
    {
        ans = min(ans, root->val - prev);
    }
    prev = root->val;
    minAbs(root->right, prev, ans);
}
int getMinimumDifference(TreeNode *root)
{
    int prev = INT_MIN;
    int ans = INT_MAX;
    minAbs(root, prev, ans);
    return ans;
}

// Q14. Sum of Left Leaves.
void sumLeaf(TreeNode *root, int &sum, int flag)
{
    if (!root)
        return;
    if (flag == 1 && !root->left && !root->right)
    {
        sum += root->val;
        return;
    }
    sumLeaf(root->left, sum, 1);
    sumLeaf(root->right, sum, 0);
}
int sumOfLeftLeaves(TreeNode *root)
{
    int sum = 0;
    sumLeaf(root->left, sum, 1);
    sumLeaf(root->right, sum, 0);
    return sum;
}

int main() {}