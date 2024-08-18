#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Q1. Maximum of minimum for every window size.
vector<int> maxOfMin(int arr[], int n)
{
    // Your code here
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int index = st.top();
            st.pop();
            if (st.empty())
            {
                int range = i;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
            else
            {
                int range = i - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }
        st.push(i);
    }
    while (!st.empty())
    {
        int index = st.top();
        st.pop();
        if (st.empty())
        {
            int range = n;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
        else
        {
            int range = n - st.top() - 1;
            ans[range - 1] = max(ans[range - 1], arr[index]);
        }
    }

    for (int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);

    return ans;
}

// Q2. Min distance between two given nodes of a Binary Tree.
int dist_to_node(Node *head, int target)
{
    if (!head)
        return -1;
    if (head->data == target)
        return 0;

    int left_dist = dist_to_node(head->left, target);
    int right_dist = dist_to_node(head->right, target);

    if (left_dist >= 0)
        return left_dist + 1;
    if (right_dist >= 0)
        return right_dist + 1;

    return -1;
}

Node *LCA(Node *head, int val1, int val2)
{
    if (!head)
        return NULL;
    if (head->data == val1 || head->data == val2)
        return head;

    Node *left_lca = LCA(head->left, val1, val2);
    Node *right_lca = LCA(head->right, val1, val2);

    if (left_lca && right_lca)
        return head;
    return left_lca ? left_lca : right_lca;
}

int findDist(Node *root, int a, int b)
{
    // Your code here
    Node *temp = LCA(root, a, b);
    return dist_to_node(temp, a) + dist_to_node(temp, b);
}

// Q3. K Sum Paths.
int count1 = 0;
void find(Node *root, vector<int> &path, int &k)
{
    if (!root)
        return;

    path.push_back(root->data);
    find(root->left, path, k);
    find(root->right, path, k);

    int sum = 0;
    for (int i = path.size() - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count1++;
    }

    path.pop_back();
}

// Q4. Binary Tree Maximum Path Sum.
int pathSum = INT_MIN;

int find(TreeNode *root)
{
    if (!root->left && !root->right)
        return root->val;
    int left_sum = 0, right_sum = 0;
    if (root->left)
    {
        left_sum = find(root->left);
        pathSum = max(pathSum, left_sum);
    }
    if (root->right)
    {
        right_sum = find(root->right);
        pathSum = max(pathSum, right_sum);
    }

    int sum = root->val + left_sum + right_sum;
    if (sum > root->val)
        pathSum = max(pathSum, sum);
    else
        pathSum = max(pathSum, root->val);
    pathSum = max(pathSum, root->val + max(left_sum, right_sum));

    return max(root->val, root->val + max(left_sum, right_sum));
}

int maxPathSum(TreeNode *root)
{
    if (!root->left && !root->right)
        return root->val;
    find(root);
    return pathSum;
}

int sumK(Node *root, int k)
{
    // code here
    vector<int> path;
    find(root, path, k);
    return count1;
}

// Q5. Sum of Distances in Tree.
int n;
vector<list<int>> adjList;
vector<int> sz, val, ans;

void dfs1(int node, int par)
{

    for (int child : adjList[node])
    {
        if (child != par)
        {
            dfs1(child, node);
            sz[node] += sz[child];
            val[node] += val[child] + sz[child];
        }
    }
    sz[node]++;
}

void dfs2(int node, int par, int dpVal)
{
    ans[node] = val[node] + dpVal + (n - sz[node]);

    for (int child : adjList[node])
    {
        if (child != par)
            dfs2(child, node, ans[node] - val[child] - sz[child]);
    }
}
vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
{
    n = N;
    adjList.resize(n), sz.resize(n), val.resize(n), ans.resize(n);
    for (vector<int> &v : edges)
    {
        adjList[v[0]].push_back(v[1]);
        adjList[v[1]].push_back(v[0]);
    }
    dfs1(0, 0);
    dfs2(0, 0, 0);
    return ans;
}

// Q6. Number of Islands.
int row[8] = {-1, 1, 0, 0};
int col[8] = {0, 0, -1, 1};
int r, c;

bool valid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }

void dfs(int i, int j, vector<vector<char>> &grid)
{
    grid[i][j] = '0';

    for (int k = 0; k < 4; k++)
    {
        int i_new = i + row[k];
        int j_new = j + col[k];

        if (valid(i_new, j_new) && grid[i_new][j_new] == '1')
        {
            dfs(i_new, j_new, grid);
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    r = grid.size();
    c = grid[0].size();

    int ans = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                dfs(i, j, grid);
            }
        }
    }

    return ans;
}

int main() {}