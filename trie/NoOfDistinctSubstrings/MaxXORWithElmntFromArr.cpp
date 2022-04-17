// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

// Example 1:

// Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
// Output: [3,3,7]
// Explanation:
// 1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
// 2) 1 XOR 2 = 3.
// 3) 5 XOR 2 = 7.
// Example 2:

// Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
// Output: [15,-1,5]

// https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// https://www.youtube.com/watch?v=Q8LhG9Pi5KM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=8

#include <bits/stdc++.h>
struct Node
{
    Node *links[2];

    bool containsKey(int ind)
    {
        return (links[ind] != NULL);
    }
    Node *get(int ind)
    {
        return links[ind];
    }
    void put(int ind, Node *node)
    {
        links[ind] = node;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

public:
    void insert(int num)
    {
        Node *node = root;
        // cout << num << endl;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

public:
    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size(), 0);
        vector<pair<int, pair<int, int>>> offlineQueries;
        sort(arr.begin(), arr.end());
        int index = 0;
        for (auto &it : queries)
        {
            offlineQueries.push_back({it[1], {it[0], index++}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        int n = arr.size();
        Trie trie;

        for (auto &it : offlineQueries)
        {
            while (i < n && arr[i] <= it.first)
            {
                trie.insert(arr[i]);
                i++;
            }
            if (i != 0)
                ans[it.second.second] = trie.findMax(it.second.first);
            else
                ans[it.second.second] = -1;
        }
        return ans;
    }
};