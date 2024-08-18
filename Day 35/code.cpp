#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Flood Fill.
int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
int r, c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

void dfs(int i, int j, vector<vector<int>> &image, int &curr_color, int &color)
{
    image[i][j] = color;

    for (int k = 0; k < 4; k++)
    {
        int new_i = i + row[k];
        int new_j = j + col[k];

        if (valid(new_i, new_j) && image[new_i][new_j] == curr_color && image[new_i][new_j] != color)
        {
            dfs(new_i, new_j, image, curr_color, color);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    r = image.size();
    c = image[0].size();

    int val = image[sr][sc];

    dfs(sr, sc, image, val, color);
    return image;
}

// Q2. Rat in a Maze Problem - I.
vector<string> ans;
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

int r, c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

void dfs(int i, int j, vector<vector<int>> &mat, string &temp)
{
    if (i == r - 1 && j == c - 1)
    {
        ans.push_back(temp);
        return;
    }

    mat[i][j] = 0;

    for (int k = 0; k < 4; k++)
    {
        int new_i = i + row[k];
        int new_j = j + col[k];

        if (valid(new_i, new_j) && mat[new_i][new_j] == 1)
        {
            if (k == 0)
                temp.push_back('D');
            if (k == 1)
                temp.push_back('U');
            if (k == 2)
                temp.push_back('R');
            if (k == 3)
                temp.push_back('L');
            dfs(new_i, new_j, mat, temp);
            mat[new_i][new_j] = 1;
            temp.pop_back();
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat)
{
    // Your code goes here
    if (mat[0][0] == 0)
        return {};
    r = mat.size();
    c = mat[0].size();
    string temp = "";
    dfs(0, 0, mat, temp);
    return ans;
}

// Q3. Directed Graph Cycle.
bool cycleDetect(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &path)
{
    visited[node] = 1;
    path[node] = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (path[adj[node][i]])
            return 1;
        if (visited[adj[node][i]])
            continue;
        if (cycleDetect(adj[node][i], adj, visited, path))
            return 1;
    }
    path[node] = 0;
    return 0;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, 0);
    vector<bool> path(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && cycleDetect(i, adj, visited, path))
            return 1;
    }
    return 0;
}

// Q4. Steps by Knight.
int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

int r, c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1])
        return 0;
    r = N, c = N;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, 0));
    q.push({KnightPos[0] - 1, KnightPos[1] - 1});
    visited[KnightPos[0] - 1][KnightPos[1] - 1] = 1;

    int ans = 0;
    while (!q.empty())
    {
        int count = q.size();
        ans++;
        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 8; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j) && !visited[new_i][new_j])
                {

                    if (TargetPos[0] - 1 == new_i && TargetPos[1] - 1 == new_j)
                        return ans;

                    q.push({new_i, new_j});
                    visited[new_i][new_j] = 1;
                }
            }
        }
    }
    return -1;
}

// Q5. Strongly Connected Components (Kosaraju's Algo).
void topologicalSort(int node, vector<vector<int>> &adj, stack<int> &s, vector<bool> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            topologicalSort(adj[node][i], adj, s, visited);
    }
    s.push(node);
}

void DFS(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            DFS(adj[node][i], adj, visited);
    }
}

// Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<vector<int>> &adj)
{
    stack<int> s;
    vector<bool> visited(V, 0);
    // Topological Sort
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topologicalSort(i, adj, s, visited);
        }
    }

    // Reverse edges
    vector<vector<int>> adj2(V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int u = i;
            int v = adj[i][j];

            adj2[v].push_back(u);
        }
    }

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Pop the node from the stack
    // If it is not visited yet
    // SCC++
    // Call the DFS

    int SCC = 0;

    while (!s.empty())
    {
        int node = s.top();
        s.pop();

        if (!visited[node])
        {
            SCC++;
            DFS(node, adj2, visited);
        }
    }

    return SCC;
}

int main() {}