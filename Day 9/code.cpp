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

// Q1. Balanced Binary Tree.
int height(TreeNode *root, bool &valid)
{
    if (!root)
        return 0;
    int L = height(root->left, valid);
    int R = height(root->right, valid);
    if (abs(L - R) > 1)
        valid = 0;
    return 1 + max(L, R);
}
bool isBalanced(TreeNode *root)
{
    bool valid = 1;
    height(root, valid);
    return valid;
}

// Q2. Predecessor and Successor.
bool b = 0;
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    if (root == NULL)
        return;
    findPreSuc(root->left, pre, suc, key);
    if (root->key > key and b != 1)
    {
        suc = root;
        b = 1;
    }
    if (root->key < key)
    {
        pre = root;
    }
    findPreSuc(root->right, pre, suc, key);
}

// Q3. Binary Tree Inorder Traversal.
void preorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    preorder(root->left, ans);
    ans.push_back(root->val);
    preorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}

// Q4. Check whether BST contains Dead End.
bool find(Node *root, unordered_map<int, int> &m)
{
    if (!root)
        return 0;
    if (!root->left && !root->right && (m[root->key - 1] == 1 || root->key == 1) && (m[root->key + 1] == 1 || root->key == 10001))
    {
        return 1;
    }
    m[root->key] = 1;
    return find(root->left, m) || find(root->right, m);
}

bool isDeadEnd(Node *root)
{
    // Your code here
    unordered_map<int, int> m;
    return find(root, m);
}

// Q5. Binary Search Tree Iterator.
// Method 1:
vector<int> ans;
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    ans.push_back(root->val);
    inorder(root->right);
}
int n;
int index = 0;
void BSTIterator(TreeNode *root)
{
    inorder(root);
    n = ans.size();
}

int next()
{
    return ans[index++];
}

bool hasNext()
{
    if (index < n)
        return 1;
    return 0;
}

// Method 2:
stack<TreeNode *> s;
void BSTIterator(TreeNode *root)
{
    partialInorder(root);
}

void partialInorder(TreeNode *root)
{
    while (root != NULL)
    {
        s.push(root);
        root = root->left;
    }
}

int next()
{
    TreeNode *top = s.top();
    s.pop();
    partialInorder(top->right);
    return top->val;
}

bool hasNext()
{
    return !s.empty();
}

// Q6. Lowest Common Ancestor of a Binary Tree.
TreeNode *rec(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode *l = rec(root->left, p, q);
    TreeNode *r = rec(root->right, p, q);

    if (l && r)
        return root;
    if (!l && r)
        return r;
    return l;
}
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    return rec(root, p, q);
}

// Q7. Unique Binary Search Trees II.
vector<TreeNode *> buildTree(int start, int end)
{
    vector<TreeNode *> ans;

    // If start > end, then subtree will be empty so add NULL in the ans and
    // return it.
    if (start > end)
    {
        ans.push_back(NULL);
        return ans;
    }

    // Iterate through all values from start to end to construct left and
    // right subtree recursively
    for (int i = start; i <= end; ++i)
    {
        vector<TreeNode *> leftSubTree =
            buildTree(start, i - 1); // Construct left subtree
        vector<TreeNode *> rightSubTree =
            buildTree(i + 1, end); // Construct right subtree

        // loop through all left and right subtrees and connect them to ith
        // root
        for (int j = 0; j < leftSubTree.size(); j++)
        {
            for (int k = 0; k < rightSubTree.size(); k++)
            {
                TreeNode *root =
                    new TreeNode(i);           // Create root with value i
                root->left = leftSubTree[j];   // Connect left subtree rooted
                                               // at leftSubTree[j]
                root->right = rightSubTree[k]; // Connect right subtree
                                               // rooted at rightSubTree[k]
                ans.push_back(root);           // Add this tree(rooted at i) to ans
                                               // data-structure
            }
        }
    }

    return ans;
}

vector<TreeNode *> generateTrees(int n) { return buildTree(1, n); }

// Q8. All Nodes Distance K in Binary Tree.
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int si = q.size();
            for(int i = 0; i < si; i++){
                auto top = q.front();
                q.pop();
                
                if(top -> left){
                    parent[top->left->val] = top;
                    q.push(top->left); 
                }

                if(top -> right){
                    parent[top->right->val] = top;
                    q.push(top->right); 
                }
            }
        }

        unordered_map<int, int> visited;
        q.push(target);
        while(k-- && !q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto top = q.front();
                q.pop();

                visited[top -> val] = 1;

                if(top -> left && !visited[top->left->val]){
                    q.push(top -> left);
                }

                if(top -> right && !visited[top->right->val]){
                    q.push(top -> right);
                }

                if(parent[top->val] && !visited[parent[top->val] -> val]){
                    q.push(parent[top->val]);
                }

            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

int main() {}