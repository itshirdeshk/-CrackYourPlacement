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

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

struct Node1
{
    int key;
    struct Node1 *left;
    struct Node1 *right;

    Node1(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Q1. Count BST nodes that lie in a given range.
int count1 = 0;
void find(TreeNode *root, int &l, int &h)
{
    if (!root)
        return;
    if (root->val >= l && root->val <= h)
        count1++;
    find(root->left, l, h);
    find(root->right, l, h);
}

int getCount(TreeNode *root, int l, int h)
{
    find(root, l, h);
    return count1;
}

// Q2. Preorder to BST.
Node *BST(int pre[], int &size, int &index, int lower, int upper)
{
    if (index == size || pre[index] < lower || pre[index] > upper)
        return NULL;
    Node *root = newNode(pre[index++]);
    root->left = BST(pre, size, index, lower, root->data);
    root->right = BST(pre, size, index, root->data, upper);
    return root;
}

// Function that constructs BST from its preorder traversal.
Node *Bst(int pre[], int size)
{
    // code here
    int index = 0;
    return BST(pre, size, index, INT_MIN, INT_MAX);
}

// Q3. Binary Tree to DLL.
Node *head = NULL;
Node *prev1 = NULL;
Node *bToDLL(Node *root)
{
    if (root == NULL)
        return root;
    bToDLL(root->left);
    if (prev1 == NULL)
    {
        prev1 = root;
        head = root;
    }
    else
    {
        root->left = prev1;
        prev1->right = root;
        prev1 = root;
    }
    bToDLL(root->right);

    return head;
}

// Q4. Vertical Order Traversal of a Binary Tree.
void find(TreeNode *root, int index, int depth, map<int, vector<pair<int, int>>> &nodes)
{
    if (!root)
        return;
    nodes[index].push_back(make_pair(depth, root->val));
    find(root->left, index - 1, depth + 1, nodes);
    find(root->right, index + 1, depth + 1, nodes);
}

// Function to perform vertical order traversal of the binary tree
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    if (!root)
        return {};

    map<int, vector<pair<int, int>>> nodes;
    find(root, 0, 0, nodes);

    vector<vector<int>> result;
    for (map<int, vector<pair<int, int>>>::iterator it = nodes.begin(); it != nodes.end(); ++it)
    {
        sort(it->second.begin(), it->second.end());
        vector<int> col;
        for (vector<pair<int, int>>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
        {
            col.push_back(jt->second);
        }
        result.push_back(col);
    }

    return result;
}

// Q5. Median of BST.
float val1, val2;
void inorder(Node *root, int &count)
{
    if (!root)
        return;
    inorder(root->left, count);
    count++;
    inorder(root->right, count);
}
void inorder1(Node *root, int &index1, int &index2, int &count)
{
    if (!root)
        return;
    inorder1(root->left, index1, index2, count);
    count++;
    if (count == index1)
        val1 = root->data;
    if (count == index2)
        val2 = root->data;
    inorder1(root->right, index1, index2, count);
}

void inorder2(Node *root, int &index1, int &count)
{
    if (!root)
        return;
    inorder2(root->left, index1, count);
    count++;
    if (count == index1)
        val1 = root->data;
    inorder2(root->right, index1, count);
}

float findMedian(struct Node *root)
{
    // Code here
    int count = 0;
    inorder(root, count);

    if (count % 2 == 0)
    {
        int index1 = count / 2;
        int index2 = count / 2 + 1;
        int count = 0;
        inorder1(root, index1, index2, count);
        return (val1 + val2) * 1.0 / 2 * 1.0;
    }
    else
    {
        int index1 = (count + 1) / 2;
        int count = 0;
        inorder2(root, index1, count);
        return val1 * 1.0;
    }

    return -1;
}

// Q6. Construct Tree from Preorder Traversal.
Node1 *construct(int &n, int pre[], char preLN[], int &index)
{
    if (index == n)
        return NULL;
    if (preLN[index] == 'L')
    {
        Node1 *temp = new Node1(pre[index++]);
        return temp;
    }
    Node1 *temp = new Node1(pre[index++]);
    temp->left = construct(n, pre, preLN, index);
    temp->right = construct(n, pre, preLN, index);
    return temp;
}
// function should return the root of the new binary tree formed
struct Node1 *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index = 0;
    return construct(n, pre, preLN, index);
}

int main() {}