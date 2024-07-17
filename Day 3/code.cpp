#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Q1. N-Queens.
void find(int row, int n, vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, vector<bool> &leftDig, vector<bool> &rightDig)
{
    // Base Condition
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    // Put queen at any n position
    for (int i = 0; i < n; i++)
    {
        if (column[i] == 0 && leftDig[n - 1 + (i - row)] == 0 && rightDig[row + i] == 0)
        {
            column[i] = 1;
            board[row][i] = 'Q';
            leftDig[n - 1 + (i - row)] = 1;
            rightDig[row + i] = 1;
            find(row + 1, n, ans, board, column, leftDig, rightDig);
            column[i] = 0;
            board[row][i] = '.';
            leftDig[n - 1 + (i - row)] = 0;
            rightDig[row + i] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i].push_back('.');

    vector<bool> leftDig(2 * n - 1, 0);
    vector<bool> rightDig(2 * n - 1, 0);

    vector<bool> column(n, 0);

    find(0, n, ans, board, column, leftDig, rightDig);

    return ans;
}

// Q2. M-Coloring Problem.
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

// Q3. Sudoku Solver.
bool check(int num, vector<vector<char>> &board, int i, int j)
{
    char c = '0' + num;
    // check at same row
    for (int col = 0; col < 9; col++)
    {
        if (board[i][col] == c)
            return 0;
    }
    // check at same col
    for (int row = 0; row < 9; row++)
    {
        if (board[row][j] == c)
            return 0;
    }
    // check at same block
    int row = i / 3 * 3, col = j / 3 * 3;
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            if (board[row + a][col + b] == c)
                return 0;
        }
    }

    return 1;
}

bool find(int i, int j, vector<vector<char>> &board)
{
    if (i == 9)
        return 1;
    if (j == 9)
        return find(i + 1, 0, board);

    if (board[i][j] != '.')
        return find(i, j + 1, board);

    for (int num = 1; num <= 9; num++)
    {
        if (check(num, board, i, j))
        {
            board[i][j] = '0' + num;
            if (find(i, j + 1, board))
                return 1;
            board[i][j] = '.';
        }
    }
    return 0;
}

void solveSudoku(vector<vector<char>> &board)
{
    find(0, 0, board);
}

// Q4. Middle of the Linked List.
ListNode *middleNode(ListNode *head)
{
    if (head->next == NULL)
        return head;
    ListNode *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    int newCount = 0;
    count = count / 2;
    curr = head;
    while (newCount != count)
    {
        newCount++;
        curr = curr->next;
    }

    return curr;
}

// Q5. Merge Two Sorted Lists.
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *dummy, *temp;
    dummy = new ListNode();
    temp = dummy;

    // when both list1 and list2 isn't empty
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // we reached at the end of one of the list
    if (list1)
        temp->next = list1;
    if (list2)
        temp->next = list2;

    return dummy->next;
}

// Q6. BFS of graph.
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    if (V == 1)
        return {0};
    vector<int> ans;
    queue<int> q;
    vector<bool> visited(V, 0);
    visited[0] = 1;
    q.push(0);
    ans.push_back(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                ans.push_back(adj[node][i]);
                q.push(adj[node][i]);
                visited[adj[node][i]] = 1;
            }
        }
    }

    return ans;
}

// Q7. DFS of Graph.
void DFS(int node, vector<int> adj[], vector<int> &ans, vector<bool> &visited)
{
    visited[node] = 1;
    ans.push_back(node);
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            DFS(adj[node][i], adj, ans, visited);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    vector<bool> visited(V, 0);
    DFS(0, adj, ans, visited);
    return ans;
}

int main() {}