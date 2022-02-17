// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]

// https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12
// https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // in every recursion swap current index element with all the elements to the right side of it
    // and after every swap pass this new formed array to new recursion call

    void solve(vector<vector<int>> &ans, vector<int> &nums, int idx)
    {
        if (idx == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            solve(ans, nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
        return;
    }

    vector<vector<int>> permute(vector<int> &nums)
    {

        vector<vector<int>> ans;
        int idx = 0;
        solve(ans, nums, 0);
        return ans;
    }
};