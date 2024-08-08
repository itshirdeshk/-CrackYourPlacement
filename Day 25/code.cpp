#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Partition Equal Subset Sum.
int equalPartition(int N, int arr[])
{
    // code here
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2 != 0)
        return 0;
    else
        sum /= 2;

    int n = N;
    vector<int> dp(sum + 1, 0);

    // A sum of 0 can always be achieved with an empty subset
    dp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        // Update the dp array in reverse to avoid using updated values within the same iteration
        for (int j = sum; j >= arr[i]; j--)
        {
            if (dp[j - arr[i]])
            {
                dp[j] = 1;
            }
        }
    }

    return dp[sum];
}

// Q2. Maximum Product Subarray.
int maxProduct(vector<int> &nums)
{
    double maxi = INT_MIN;
    double prod = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prod *= nums[i];
        maxi = max(prod, maxi);
        if (prod == 0)
            prod = 1;
    }
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        prod *= nums[i];

        maxi = max(prod, maxi);
        if (prod == 0)
            prod = 1;
    }
    return maxi;
}

int main() {}