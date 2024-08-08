#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Longest Common Substring.
int longestCommonSubstr(string s1, string s2)
{
    // your code here
    vector<int> dp(s2.size() + 1, 0);

    for (int i = 1; i <= s1.size(); i++)
    {
        int prev = 0;
        for (int j = 1; j <= s2.size(); j++)
        {
            int curr = dp[j];
            if (s1[i - 1] == s2[j - 1])
            {
                dp[j] = 1 + prev;
                ans = max(dp[j], ans);
            }
            else
            {
                dp[j] = 0; // Reset the current dp[j] value to 0
            }
            prev = curr;
        }
    }

    // find(s1.size(), s2.size(), s1, s2, dp);
    return ans;
}

// Q2. Longest Increasing Subsequence.
int lengthOfLIS(vector<int> &a)
{
    int size = 0, start, end, mid, index;
    int n = a.size();
    vector<int> LIS(n);
    LIS[0] = a[0];

    for (int i = 0; i < n; i++)
    {
        start = 0, end = size;
        index = size + 1;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (LIS[mid] < a[i])
                start = mid + 1;
            else if (LIS[mid] == a[i])
            {
                index = mid;
                break;
            }
            else
            {
                index = mid;
                end = mid - 1;
            }
        }

        LIS[index] = a[i];
        size = max(size, index);
    }

    return size + 1;
}

int main() {}