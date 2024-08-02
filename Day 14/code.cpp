#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Q1. Task Scheduler.
int leastInterval(vector<char> &tasks, int n)
{
    // Calculate the freq of each Char
    vector<int> freq(26, 0);
    int count = 0;

    for (int i = 0; i < tasks.size(); i++)
    {
        freq[tasks[i] - 'A']++;
        count = max(count, freq[tasks[i] - 'A']);
    }

    int ans = (count - 1) * (n + 1);
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] == count)
        {
            ans++;
        }
    }

    return ans > tasks.size() ? ans : tasks.size();
}

int main() {}