// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

// Constraints:

// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.

// https://www.youtube.com/watch?v=YPTqKIgVk-k&list=PLot-Xpze53ldVwtstag2TL4HQhAnC8ATf&index=72

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
        {
            if (mp.find(i) != mp.end())
                mp[i]++;
            else
                mp[i] = 1;
        }

        priority_queue<pair<int, int>> pq;

        for (auto i : mp)
            pq.push({i.second, i.first});

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};