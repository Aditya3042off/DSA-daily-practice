// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

// https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // void Solve(set<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int idx)
    // {

    //     if (idx == nums.size())
    //     {
    //         ans.insert(temp);
    //         return;
    //     }

    //     // selecting the number
    //     temp.push_back(nums[idx]);
    //     Solve(ans, temp, nums, idx + 1);
    //     temp.pop_back();

    //     // not selecting the number
    //     Solve(ans, temp, nums, idx + 1);
    //     return;
    // }

    // vector<vector<int>> subsetsWithDup(vector<int> &nums)
    // {
    //     set<vector<int>> ans;
    //     vector<int> temp;
    //     sort(nums.begin(), nums.end());
    //     Solve(ans, temp, nums, 0);

    //     vector<vector<int>> finalAns;
    //     for (auto i : ans)
    //         finalAns.push_back(i);
    //     return finalAns;
    // }

    void Solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int idx)
    {

        if (idx == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        // selecting the number
        temp.push_back(nums[idx]);
        Solve(ans, temp, nums, idx + 1);
        temp.pop_back();

        int n = nums.size();
        // not selecting the number
        while (idx < n - 1 and nums[idx] == nums[idx + 1])
            idx++;
        Solve(ans, temp, nums, idx + 1);
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        Solve(ans, temp, nums, 0);

        return ans;
    }
};