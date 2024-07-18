#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Spiral Matrix.
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int top = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1,
        left = 0;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

// Q2. Merge Sorted Array.
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}

// Q3. Word Search.
bool DFS(vector<vector<char>> &board, string word, int i, int j, int n)
{
    // check if all the alphabets in the word is checked
    if (n == word.size())
        return true;

    // check if i and j are out of bound or if the characters aren't equal
    if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() ||
        board[i][j] != word[n])
        return false;

    // mark as visited
    board[i][j] = '0';

    // branch out in all 4 directions
    bool status = DFS(board, word, i + 1, j, n + 1) || // down
                  DFS(board, word, i, j + 1, n + 1) || // right
                  DFS(board, word, i - 1, j, n + 1) || // up
                  DFS(board, word, i, j - 1, n + 1);   // left

    // change the character back for other searches
    board[i][j] = word[n];

    return status;
}

bool exist(vector<vector<char>> &board, string word)
{
    if (word == "")
        return false;

    for (int i = 0; i < board.size(); i++)
        for (int j = 0; j < board[i].size(); j++)
            // check if the characters are equal then call DFS
            if (board[i][j] == word[0] && DFS(board, word, i, j, 0))
                return true;

    return false;
}

// Q4. Jump Game.
bool canJump(vector<int> &nums)
{
    vector<bool> dp(nums.size(), false);
    dp[nums.size() - 1] = true;
    int n = nums.size();

    for (int i = n - 2; i >= 0; i--)
    {
        int jump = nums[i];
        while (jump)
        {
            if ((i + jump) >= n - 1 || (i + jump < n - 1 && dp[i + jump] == true))
            {
                dp[i] = true;
                break;
            }
            jump--;
        }
    }

    return dp[0];
}

// Q5. Majority Element.
int majorityElement(vector<int> &nums)
{
    int candidate, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            candidate = nums[i];
        }
        else
        {
            if (candidate == nums[i])
                count++;
            else
                count--;
        }
    }

    return candidate;
}

// Q6. All Unique Permutations of an array.
void find(vector<int> &arr, vector<vector<int>> &ans, int index)
{
    if (index == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    unordered_map<int, int> m;
    for (int i = index; i < arr.size(); i++)
    {
        if (m[arr[i]] == 0)
        {
            swap(arr[index], arr[i]);
            find(arr, ans, index + 1);
            swap(arr[index], arr[i]);
            m[arr[i]] = 1;
        }
    }
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n)
{
    // code here
    vector<vector<int>> ans;
    find(arr, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {}