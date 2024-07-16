#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// Q1. Container With Most Water.
int maxArea(vector<int> &height)
{
    int low = 0, high = height.size() - 1;
    int water = 0;
    while (low < high)
    {
        water = max(water, (high - low) * min(height[low], height[high]));
        if (height[low] < height[high])
            low++;
        else
            high--;
    }
    return water;
}

// Q2. 3Sum.
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int target = 0 - nums[i];
        int low = i + 1, high = n - 1;

        if (target < 0)
            break;

        while (low < high)
        {
            if (nums[low] + nums[high] < target)
                low++;
            else if (nums[low] + nums[high] > target)
                high--;
            else
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                low++, high--;
                while (low < high && nums[low] == nums[low - 1])
                    low++;
                while (high > low && nums[high] == nums[high + 1])
                    high--;
            }
        }
    }
    return ans;
}

// Q4. 4Sum.
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1;
            int l = nums.size() - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum > target)
                    l--;
                else
                    k++;
            }
        }
    }
    return ans;
}

// Q5. Maximum Points You Can Obtain from Cards.
int maxScore(vector<int> &cardPoints, int k)
{
    int res = 0;

    // First k elements in our window
    for (int i = 0; i < k; i++)
        res += cardPoints[i];

    int curr = res;
    for (int i = k - 1; i >= 0; i--)
    {
        // We remove the last visited element and add the non-visited element from the last
        curr -= cardPoints[i];
        curr += cardPoints[cardPoints.size() - k + i];

        // We check the maximum value any possible combination can give
        res = max(res, curr);
    }

    return res;
}

// Q6. Subarray Sum Equals K.
int subarraySum(vector<int> &nums, int k)
{
    if (nums.size() == 1 && nums[0] != k)
        return 0;
    int total = 0;
    int prefix = 0;

    unordered_map<int, int> m;
    m[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        prefix += nums[i];
        if (m.count(prefix - k) == 1)
        {
            total += m[prefix - k];
        }
        m[prefix]++;
    }

    return total;
}

// Q7. Valid Parentheses.
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return 0;
            else if (s[i] == ')')
            {
                if (st.top() != '(')
                    return 0;
                else
                    st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.top() != '[')
                    return 0;
                else
                    st.pop();
            }
            else
            {
                if (st.top() != '{')
                    return 0;
                else
                    st.pop();
            }
        }
    }

    return st.empty();
}

// Q8. Print all the duplicate characters in a string.
void printDups(string str)
{
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++)
    {
        // increase the count of character str[i] by 1
        count[str[i]]++;
    }
    // iterating through the unordered map
    for (auto it : count)
    {
        // if the count of characters is greater than 1 then
        // duplicate found
        if (it.second > 1)
            cout << it.first << ", count = " << it.second << "\n";
    }
}

// Q9. Find the Index of the First Occurrence in a String.
void lpsFind(vector<int> &lps, string s)
{
    int pre = 0, suf = 1;

    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++, suf++;
        }
        else
        {
            if (pre == 0)
                lps[suf++] = 0;
            else
                pre = lps[pre - 1];
        }
    }
}

int strStr(string haystack, string needle)
{
    vector<int> lps(needle.size(), 0);
    lpsFind(lps, needle);

    int first = 0, second = 0;

    while (first < haystack.size() && second < needle.size())
    {
        if (haystack[first] == needle[second])
            first++, second++;
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = lps[second - 1];
            }
        }
    }

    if (second == needle.size())
        return first - second;
    return -1;
}

// Q10. Longest Common Prefix.
string longestCommonPrefix(vector<string> &v)
{
    string ans = "";
    sort(v.begin(), v.end());
    int n = v.size();
    string first = v[0], last = v[n - 1];
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

int main() {}