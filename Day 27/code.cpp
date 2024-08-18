#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

// Q1. Add Binary.
string addBinary(string a, string b)
{
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
            carry += a[i--] - '0';
        if (j >= 0)
            carry += b[j--] - '0';
        ans += carry % 2 + '0';
        carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
}

// Q2. Maximum Product of Three Numbers.
// Method 1:
int maximumProduct(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int ans1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int ans2 = nums[0] * nums[1] * nums[n - 1];
    return max(ans1, ans2);
}

// Method 2:
int maximumProduct(vector<int> &nums)
{
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= min1)
        {
            min2 = min1;
            min1 = nums[i];
        }
        else if (nums[i] <= min2)
        {
            min2 = nums[i];
        }
        if (nums[i] >= max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] >= max2)
        {
            max3 = max2;
            max2 = nums[i];
        }
        else if (nums[i] >= max3)
        {
            max3 = nums[i];
        }
    }
    return max(min1 * min2 * max1, max1 * max2 * max3);
}

// Q3. Excel Sheet Column Title.
string convertToTitle(int columnNumber)
{
    string ans = "";
    while (columnNumber)
    {
        columnNumber -= 1;
        char ch = ((columnNumber) % 26) + 'A';
        ans = ch + ans;
        columnNumber /= 26;
    }

    return ans;
}

// Q4. Product array puzzle.
// Method 1:
vector<long long int> productExceptSelf(vector<long long int> &nums)
{

    // code here
    long long int temp = 1;
    int flag = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
            temp *= nums[i];
        else
            flag++;
    }
    vector<long long int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (flag == 1)
        {
            if (nums[i] == 0)
                ans.push_back(temp);
            else
                ans.push_back(0);
        }
        else if (flag > 1)
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(temp / nums[i]);
        }
    }

    return ans;
}

// Method 2:
vector<long long int> productExceptSelf(vector<long long int> &nums)
{

    // code here
    long long int prefix = 1;
    long long int suffix = 1;

    vector<long long int> ans(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] *= prefix;
        prefix *= nums[i];
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        ans[i] *= suffix;
        suffix *= nums[i];
    }

    return ans;
}

// Q5. Floor in a Sorted Array.
int findFloor(vector<long long> &v, long long n, long long x)
{
    // Your code here
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (v[mid] == x)
            return mid;
        else if (v[mid] > x)
            end = mid - 1;
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

// Q6. Permutations in array.
bool isPossible(int k, vector<int> &arr1, vector<int> &arr2)
{
    // Your code goes here
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end(), greater<int>());

    for (int i = 0; i < arr1.size(); i++)
    {
        if (arr1[i] + arr2[i] < k)
            return false;
    }

    return true;
}

// Q7. Find Pair Given Difference.
int findPair(int n, int x, vector<int> &arr)
{
    // code here
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        int start = i + 1, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] - arr[i] == x)
                return 1;
            else if (arr[mid] - arr[i] < x)
                start = mid + 1;
            else
                end = mid - 1;
        }
    }

    return -1;
}

// Q8. Check if reversing a sub array make the array sorted.
bool sortArr(int a[], int n)
{
    int x = -1;
    int y = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            if (x == -1)
            {
                x = i;
            }
            y = i + 1;
        }
    }

    if (x != -1)
    {
        reverse(a + x, a + y + 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                return false;
                return 0;
            }
        }
    }

    return true;
}

// Q9. Find Peak Element.
int findPeakElement(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1, mid;
    int n = arr.size();
    if (arr.size() < 2)
        return 0;

    if (arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;

    while (start <= end)
    {
        mid = end + (start - end) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

// Q10. Search in Rotated Sorted Array.
int search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[0])
        {
            if (nums[start] <= target && nums[mid] >= target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[end] >= target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return -1;
}

int main() {}