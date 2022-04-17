// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// https://www.youtube.com/watch?v=on2hvxBXJH4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=44

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return 1;
        // in dp at every index we store the length of longest increasing subsequence starting
        //  from that index to the end of the array
        vector<int> dp(size, 0);
        dp[size - 1] = 1;

        int ans = INT_MIN;
        int j;
        for (int i = size - 2; i >= 0; i--)
        {
            dp[i] = 1;
            for (int j = i + 1; j <= size - 1; j++)
            {
                if (nums[i] < nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};