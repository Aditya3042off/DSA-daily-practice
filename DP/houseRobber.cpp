// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed,
// the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected
// and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house,
// return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// https://www.youtube.com/watch?v=GrMBfJNk_NY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=6&t=226s

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization

    // here at every index in dp i'm storing the max money robber can steel from all the houses
    // to the right of it including that house

    // at every house he has a situation of robbing it and not robbing
    // the max amount at every index depends on these two cases

    //     int Solve(vector<int> &nums,int idx,vector<int> &dp) {

    //         if(idx >=nums.size()) return 0;

    //         if(dp[idx] != -1) return dp[idx];

    //         int robbing = Solve(nums,idx+2,dp) + nums[idx];
    //         int notRobbing = Solve(nums,idx+1,dp);

    //         return dp[idx] = max(robbing,notRobbing);
    //     }

    //     int rob(vector<int>& nums) {
    //         int n = nums.size();

    //         vector<int>dp(n,-1);
    //         return Solve(nums,0,dp);
    //     }

    // Tabulation

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[n - 1] = nums[n - 1];
        int robbing, notRobbing;

        for (int idx = n - 2; idx >= 0; idx--)
        {

            if (idx == n - 2)
                robbing = nums[idx];
            else
                robbing = dp[idx + 2] + nums[idx];

            notRobbing = dp[idx + 1];

            dp[idx] = max(robbing, notRobbing);
        }
        return dp[0];
    }
};