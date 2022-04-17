// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

// https://www.youtube.com/watch?v=9ZyLjjk536U

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sum = 0, size = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (!nums[i])
                sum--;

            if (sum == 0)
                size = max(size, i + 1);

            if (mp.find(sum) == mp.end())
                mp[sum] = i;
            else
                size = max(size, i - mp[sum]);
        }
        return size;
    }
};