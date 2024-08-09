#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Unique Paths.
int uniquePaths(int m, int n)
{
    int dp[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (i == 0 || j == 0)
                dp[i][j] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}

// Q2. Minimum Insertion Steps to Make a String Palindrome.
int minInsertions(string str1)
{
    int n = str1.size();
    string str2 = str1;
    reverse(str2.begin(), str2.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int result = dp[n][n];
    return n - result;
}

// Q3. Best Time to Buy and Sell Stock IV.
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    int total;

    for (int i = 1; i <= k; i++)
    {
        total = -prices[0];
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] + total);
            total = max(total, -prices[j - 1] + dp[i - 1][j]);
        }
    }
    return dp[k][n];
}

// Q4. Rotate Image.
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse the rows
    for (int i = 0; i < n; i++)
    {
        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[i][start++], matrix[i][end--]);
        }
    }
}

// Q5. Find the number of islands.
int row[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int col[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int r, c;

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

void dfs(int i, int j, vector<vector<char>> &grid)
{
    grid[i][j] = '0';

    for (int k = 0; k < 8; k++)
    {
        int i_new = i + row[k];
        int j_new = j + col[k];

        if (valid(i_new, j_new) && grid[i_new][j_new] == '1')
        {
            dfs(i_new, j_new, grid);
        }
    }
}

// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
    // Code here
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