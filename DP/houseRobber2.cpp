// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed.
// All houses at this place are arranged in a circle.
// That means the first house is the neighbor of the last one.
// Meanwhile, adjacent houses have a security system connected,
// and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 3:

// Input: nums = [1,2,3]
// Output: 3

// https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int Solve(vector<int> &nums, int idx, vector<int> &dp)
    {

        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int robbing = Solve(nums, idx + 2, dp) + nums[idx];
        int notRobbing = Solve(nums, idx + 1, dp);

        return dp[idx] = max(robbing, notRobbing);
    }

    int rob(vector<int> &nums)
    {
        vector<int> temp1, temp2;
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n - 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }

        int case_1 = Solve(temp1, 0, dp);

        for (int i = 0; i < n - 1; i++)
            dp[i] = -1;

        int case_2 = Solve(temp2, 0, dp);

        return max(case_1, case_2);
    }
};