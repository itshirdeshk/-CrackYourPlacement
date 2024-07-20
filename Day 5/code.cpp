#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

// Q1. Game of Life.
int getLiveNeighbours(vector<vector<int>> &curr, int i, int j, int m, int n)
{
    int liveNeighbours = 0;
    if (i > 0)
    {
        // check the upper neighbour
        if (curr[i - 1][j] == 1 || curr[i - 1][j] == 3)
            liveNeighbours++;
    }
    if (i < m - 1)
    {
        // check the lower neighbour
        if (curr[i + 1][j] == 1 || curr[i + 1][j] == 3)
            liveNeighbours++;
    }
    if (j > 0)
    {
        // check the left neighbour
        if (curr[i][j - 1] == 1 || curr[i][j - 1] == 3)
            liveNeighbours++;
    }
    if (j < n - 1)
    {
        // check the right neighbour
        if (curr[i][j + 1] == 1 || curr[i][j + 1] == 3)
            liveNeighbours++;
    }

    if (i > 0 && j > 0)
    {
        if (curr[i - 1][j - 1] == 1 || curr[i - 1][j - 1] == 3)
            liveNeighbours++;
    }
    if (i > 0 && j < n - 1)
    {
        if (curr[i - 1][j + 1] == 1 || curr[i - 1][j + 1] == 3)
            liveNeighbours++;
    }
    if (i < m - 1 && j > 0)
    {
        if (curr[i + 1][j - 1] == 1 || curr[i + 1][j - 1] == 3)
            liveNeighbours++;
    }
    if (i < m - 1 && j < n - 1)
    {
        if (curr[i + 1][j + 1] == 1 || curr[i + 1][j + 1] == 3)
            liveNeighbours++;
    }
    return liveNeighbours;
}
void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ln = getLiveNeighbours(board, i, j, m, n);
            if (board[i][j] == 0)
            {
                // currently dead
                // can become alive if has exactly three live neighbours
                if (ln == 3)
                {
                    board[i][j] = 2; // newly alive
                }
            }
            else if (board[i][j] == 1)
            {
                //<2 -> die
                //==2 || ==3 live
                //>3 ->die
                if (ln < 2 || ln > 3)
                {
                    board[i][j] = 3; // newly dead
                }
            }
        }
    }
    // final modifications 2->1, 3->0
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 2)
                board[i][j] = 1;
            else if (board[i][j] == 3)
                board[i][j] = 0;
        }
    }
}

// Q2. Largest Rectangle in Histogram.
int largestRectangleArea(vector<int> &heights)
{
    int ans = 0, index, n = heights.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            index = st.top();
            st.pop();
            if (!st.empty())
                ans = max(ans, heights[index] * (i - st.top() - 1));
            else
                ans = max(ans, heights[index] * i);
        }
        st.push(i);
    }
    while (!st.empty())
    {
        index = st.top();
        st.pop();
        if (!st.empty())
            ans = max(ans, heights[index] * (n - st.top() - 1));
        else
            ans = max(ans, heights[index] * n);
    }
    return ans;
}

// Q3. Implement Queue using Stacks.
class queue
{
    stack<int> s1;
    stack<int> s2;
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (!s2.empty())
        {
            int ele = s2.top();
            s2.pop();
            return ele;
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            int ele = s2.top();
            s2.pop();
            return ele;
        }
    }

    int peek()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            return s2.top();
        }
    }

    bool empty()
    {
        return s1.empty() && s2.empty();
    }
};

// Q4. Backspace String Compare.
bool backspaceCompare(string s, string t)
{
    int k = 0, p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            k--;
            k = max(0, k);
        }

        else
        {
            s[k] = s[i];
            k++;
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '#')
        {
            p--;
            p = max(0, p);
        }

        else
        {
            t[p] = t[i];
            p++;
        }
    }
    if (k != p)
        return false;
    else
    {
        for (int i = 0; i < k; i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
}