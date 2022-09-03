// Given an array of positive integers nums and a positive integer target,
// return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is
// greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

// https://leetcode.com/problems/minimum-size-subarray-sum/

// binary search solution also present

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        // sliding window

        int len = INT_MAX;
        int n = nums.size();
        int i = 0, j = 0;

        int sum = 0;

        while (j < n)
        {
            sum += nums[j];

            if (sum < target)
            {
                j++;
                continue;
            }

            len = min(len, j - i + 1);

            while (sum >= target)
            {
                sum -= nums[i++];
                if (sum >= target)
                    len = min(len, j - i + 1);
            }
            j++;
        }
        return len == INT_MAX ? 0 : len;
    }
};