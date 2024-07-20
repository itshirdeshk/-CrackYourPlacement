#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Implement Stack using Queues.
queue<int> q1;
queue<int> q2;
void push(int x)
{
    if (!q1.empty())
        q1.push(x);
    else
        q2.push(x);
}

int pop()
{
    if (!q1.empty())
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ele = q1.front();
        q1.pop();
        return ele;
    }
    else
    {
        while (q2.size() != 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        int ele = q2.front();
        q2.pop();
        return ele;
    }
}

int top()
{
    if (!q1.empty())
    {
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ele = q1.front();
        q2.push(q1.front());
        q1.pop();
        return ele;
    }
    else
    {
        while (q2.size() != 1)
        {
            q1.push(q2.front());
            q2.pop();
        }
        int ele = q2.front();
        q1.push(q2.front());
        q2.pop();
        return ele;
    }
}

bool empty()
{
    return q1.empty() && q2.empty();
}

// Q2. Next Greater Element I.
vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
{
    stack<int> s;
    unordered_map<int, int> m;
    for (int n : nums)
    {
        while (s.size() && s.top() < n)
        {
            m[s.top()] = n;
            s.pop();
        }
        s.push(n);
    }
    vector<int> ans;
    for (int n : findNums)
        ans.push_back(m.count(n) ? m[n] : -1);
    return ans;
}

// Q3. Evaluation of Postfix Expression.
int evaluatePostfix(string S)
{
    // Your code here
    stack<int> s;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] >= '0' && S[i] <= '9')
        {
            s.push(S[i] - '0');
        }
        else
        {
            int num1 = s.top();
            s.pop();
            int num2 = s.top();
            s.pop();

            if (S[i] == '*')
            {
                s.push(num2 * num1);
            }
            else if (S[i] == '/')
            {
                s.push(num2 / num1);
            }
            else if (S[i] == '-')
            {
                s.push(num2 - num1);
            }
            else if (S[i] == '+')
            {
                s.push(num2 + num1);
            }
        }
    }

    return s.top();
}

// Q4. Implement two stacks in an array.
int arr[200];
int index1 = -1, index2 = 200;

// Function to push an integer into the stack1.
void push1(int x)
{
    index1 += 1;
    arr[index1] = x;
}

// Function to push an integer into the stack2.
void push2(int x)
{
    index2 -= 1;
    arr[index2] = x;
}

// Function to remove an element from top of the stack1.
int pop1()
{
    if (index1 == -1)
        return -1;
    else
    {
        int num = arr[index1--];
        return num;
    }
}

// Function to remove an element from top of the stack2.
int pop2()
{
    if (index2 == 200)
        return -1;
    else
    {
        int num = arr[index2++];
        return num;
    }
}

// Q5. Daily Temperatures.
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> s;
    vector<int> ans(temperatures.size(), 0);
    for (int i = 0; i < temperatures.size(); i++)
    {
        while (!s.empty() && temperatures[s.top()] < temperatures[i])
        {
            ans[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }

    return ans;
}

// Q6. Minimum Cost Tree From Leaf Values.
int mctFromLeafValues(vector<int> &arr)
{
    int cost = 0, n = arr.size();
    stack<int> S;

    for (int i = 0; i < n; i++)
    {
        while (!S.empty() && arr[S.top()] < arr[i])
        {
            int m = arr[S.top()];
            S.pop();
            if (S.empty())
            {
                cost += m * arr[i];
            }
            else
            {
                cost += m * min(arr[i], arr[S.top()]);
            }
        }
        S.push(i);
    }

    while (S.size() > 1)
    {
        int m = arr[S.top()];
        S.pop();
        cost += m * arr[S.top()];
    }

    return cost;
}

int main() {}