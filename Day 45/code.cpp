#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Negative weight cycle.
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    // Code here
    vector<int> dist(n, 1e9);
    dist[0] = 0;
    int e = edges.size();

    for (int i = 0; i < n - 1; i++)
    {
        // Relax all the edges
        for (int j = 0; j < e; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            // if(dist[u] == 1e9) continue;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int j = 0; j < e; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        // if(dist[u] == 1e9) continue;

        if (dist[u] + weight < dist[v])
        {
            // cycle detected
            return 1;
        }
    }

    return 0;
}

int main() {}