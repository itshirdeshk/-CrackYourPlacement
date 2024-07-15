#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Q1. Find the Duplicate Number.
int findDuplicate(vector<int> &nums)
{
    while (nums[0] != nums[nums[0]])
    {
        swap(nums[0], nums[nums[0]]);
    }
    return nums[0];
}

// Q2. Sort Colors.
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] < 1)
        {
            swap(nums[low++], nums[mid++]);
        }
        else if (nums[mid] > 1)
        {
            swap(nums[high--], nums[mid]);
        }
        else
        {
            mid++;
        }
    }
}

// Q3. Remove Duplicates from Sorted Array.
int removeDuplicates(vector<int> &nums)
{
    int count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[count] != nums[i])
        {
            nums[++count] = nums[i];
        }
    }

    return count + 1;
}

// Q4. Set Matrix Zeroes.
void setZeroes(vector<vector<int>> &matrix)
{
    bool isZeroCol = false;
    bool isZeroRow = false;
    for (int i = 0; i < matrix.size(); i++)
    { // check the first column
        if (matrix[i][0] == 0)
        {
            isZeroCol = true;
            break;
        }
    }
    for (int i = 0; i < matrix[0].size(); i++)
    { // check the first row
        if (matrix[0][i] == 0)
        {
            isZeroRow = true;
            break;
        }
    }
    for (int i = 1; i < matrix.size(); i++)
    { // check except the first row and column
        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
    }
    for (int i = 1; i < matrix.size(); i++)
    { // process except the first row and column
        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    }
    if (isZeroCol)
    { // handle the first column
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }
    if (isZeroRow)
    { // handle the first row
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = 0;
    }
}

// Q5. Move Zeroes.
void moveZeroes(vector<int> &nums)
{
    if (nums.size() == 1)
        return;

    int ptr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0 && nums[ptr] != 0)
        {
            ptr++;
        }
        else if (nums[i] != 0 && nums[ptr] == 0)
        {
            int temp = nums[i];
            nums[i] = 0;
            nums[ptr++] = temp;
        }
    }
}

// Q6. Best Time to Buy and Sell Stock.
int maxProfit(vector<int> &prices)
{
    int maxCur = 0, maxSoFar = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
        maxSoFar = max(maxCur, maxSoFar);
    }
    return maxSoFar;
}

// Q7. Chocolate Distribution Problem.
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code
    sort(a.begin(), a.end());
    long long ptr1 = 0, ptr2 = m - 1;
    long long mini = INT_MAX;
    while (ptr2 < a.size())
    {
        mini = min(mini, a[ptr2] - a[ptr1]);
        ptr1++, ptr2++;
    }
    return mini;
}

// Q8. Two Sum.
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numMap;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        numMap[nums[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int complement = target - nums[i];
        if (numMap.count(complement) && numMap[complement] != i)
        {
            return {i, numMap[complement]};
        }
    }

    return {};
}

// Q9. Best Time to Buy and Sell Stock II.
int maxProfit(vector<int> &prices)
{
    int totalMax = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i - 1] < prices[i])
        {
            totalMax += prices[i] - prices[i - 1];
        }
    }
    return totalMax;
}

// Q10. Subarray Sums Divisible by K.
int subarraysDivByK(vector<int> &nums, int k)
{
    // Unordered Map
    unordered_map<int, int> m;
    m[0] = 1;

    int prefixSum = 0, rem, total = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        prefixSum += nums[i];
        rem = prefixSum % k;

        if (rem < 0)
            rem = k + rem;

        if (m.count(rem))
        {
            total += m[rem];
            m[rem]++;
        }
        else
        {
            m[rem] = 1;
        }
    }
    return total;
}

int main() {}