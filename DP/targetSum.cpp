// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1

// https://www.youtube.com/watch?v=g0npyaQtAQM&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO&index=1&t=57s
// https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<pair<int, int>, int> mp;
    int solve(vector<int> &nums, int target, int idx, int curSum)
    {
        if (idx > nums.size() - 1)
        {
            if (curSum == target)
                return 1;
            return 0;
        }

        if (mp.find({idx, curSum}) != mp.end())
            return mp[{idx, curSum}];

        return mp[{idx, curSum}] = solve(nums, target, idx + 1, curSum + nums[idx]) +
                                   solve(nums, target, idx + 1, curSum - nums[idx]);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return solve(nums, target, 0, 0);
    }
};