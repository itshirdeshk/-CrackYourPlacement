#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. M-Coloring Problem.
// Method 1:
bool DFS(int node, vector<int> &color, bool graph[101][101], int m, int n)
{
    // Try each color one by one
    for (int i = 0; i < m; i++)
    {
        // No adjacent node should have this color
        bool isPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == i)
            {
                isPossible = 0;
                break;
            }
        }

        if (isPossible == 0)
            continue; // check the next color

        color[node] = i; // assigned color to the node
        isPossible = 1;
        // Go to the adjacent node, whom the color is not assigned
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == -1)
            {
                if (!DFS(j, color, graph, m, n))
                {
                    isPossible = 0;
                    break;
                }
            }
        }

        if (isPossible)
            return 1;

        color[node] = -1;
    }

    return 0;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
        if (color[i] == -1 && !DFS(i, color, graph, m, n))
            return 0;
    return 1;
}

// Method 2:
bool find(int node, bool graph[101][101], int n, int m, vector<int> &color)
{
    if (node == n)
        return 1;
    for (int i = 0; i < m; i++)
    {
        bool isPossible = 1;
        for (int j = 0; j < n; j++)
        {
            if (graph[node][j] && color[j] == i)
            {
                isPossible = 0;
                break;
            }
        }

        if (isPossible)
        {
            color[node] = i;
            if (find(node + 1, graph, n, m, color))
                return 1;
            color[node] = -1;
        }
    }
    return 0;
}
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> color(n, -1);
    return find(0, graph, n, m, color);
}

int main() {}