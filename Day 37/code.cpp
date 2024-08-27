#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Topological sort.
// Method 1:
void dfs(int node, vector<int> adj[], stack<int> &s, vector<bool> &visited)
{
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
            dfs(adj[node][i], adj, s, visited);
    }
    s.push(node);
}
// Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    vector<bool> visited(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adj, s, visited);
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// Method 2:
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    vector<int> ans;
    queue<int> q;
    vector<int> inDeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            inDeg[adj[i][j]]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (!inDeg[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            inDeg[adj[node][i]]--;
            if (inDeg[adj[node][i]] == 0)
                q.push(adj[node][i]);
        }
    }

    return ans;
}

// Q2. Prerequisite Tasks.
bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    // Code here
    vector<int> adj[N];
    vector<int> inDeg(N, 0);
    queue<int> q;

    for (int i = 0; i < P; i++)
    {
        inDeg[prerequisites[i].first]++;
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
    }

    for (int i = 0; i < N; i++)
    {
        if (inDeg[i] == 0)
            q.push(i);
    }

    int count = 0;

    while (!q.empty())
    {
        int task = q.front();
        q.pop();
        count++;
        for (int i = 0; i < adj[task].size(); i++)
        {
            inDeg[adj[task][i]]--;
            if (inDeg[adj[task][i]] == 0)
                q.push(adj[task][i]);
        }
    }

    return count == N;
}

// Q3. Alien Dictionary.
string findOrder(string dict[], int N, int K)
{
    // code here
    vector<int> InDeg(K, 0);

    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string str1 = dict[i], str2 = dict[i + 1];
        int j = 0, k = 0;

        while (j < str1.size() && k < str2.size() && str1[j] == str2[k])
            k++, j++;
        if (j == str1.size())
            continue;

        adj[str1[j] - 'a'].push_back(str2[k] - 'a');
        InDeg[str2[k] - 'a']++;
    }
    // apply kahn's algorithm

    queue<int> q;
    for (int i = 0; i < K; i++)
    {
        if (!InDeg[i])
            q.push(i);
    }
    string ans;
    while (!q.empty())
    {
        int Node = q.front();
        q.pop();
        char c = 'a' + Node;
        ans += c;
        for (int j = 0; j < adj[Node].size(); j++)
        {
            InDeg[adj[Node][j]]--;
            if (InDeg[adj[Node][j]] == 0)
                q.push(adj[Node][j]);
        }
    }
    return ans;
}

int main() {}