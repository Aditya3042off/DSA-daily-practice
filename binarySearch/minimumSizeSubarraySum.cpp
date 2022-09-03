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

// sliding window solution also present

class Solution
{
public:
    bool f(int target, vector<int> &nums, int k)
    {
        int n = nums.size();

        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += nums[i];

        for (int i = k; i <= n; i++)
        {
            if (sum >= target)
                return true;
            if (i != n)
                sum += nums[i] - nums[i - k];
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int> &nums)
    {
        // binary search
        int n = nums.size();
        int low = 1, high = n;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (f(target, nums, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return (f(target, nums, low) == true) ? low : 0;
    }
};