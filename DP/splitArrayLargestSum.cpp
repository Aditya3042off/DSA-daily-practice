// Given an array nums which consists of non-negative integers and an integer m,
// you can split the array into m non-empty continuous subarrays.

// Write an algorithm to minimize the largest sum among these m subarrays.

// Example 1:

// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], m = 2
// Output: 9
// Example 3:

// Input: nums = [1,4,4], m = 3
// Output: 4

// https://leetcode.com/problems/split-array-largest-sum/

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(m + 1, 0));

        // base cases
        int temp = 0;
        for (int i = 0; i < size; i++)
        {
            temp += nums[i];
            dp[i][1] = temp;
        }

        for (int idx = 1; idx < size; idx++)
        {
            for (int subarrayleft = 2; subarrayleft <= m; subarrayleft++)
            {
                int ans = INT_MAX;
                int sum = 0;
                int temp;
                for (int i = idx; i > 0; i--)
                {
                    sum += nums[i];
                    temp = sum;

                    temp = max(temp, dp[i - 1][subarrayleft - 1]);
                    ans = min(ans, temp);
                }
                dp[idx][subarrayleft] = ans;
            }
        }
        return dp[size - 1][m];
    }
};