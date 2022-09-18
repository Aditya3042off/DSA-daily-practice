// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

// Example 1:

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
// Example 2:

// Input: nums = [1,5]
// Output: 10

class Solution
{
public:
    // memoization
    //     int f(int start,int end,vector<int>& nums,vector<vector<int>>& dp) {
    //         if(start > end) return 0;

    //         if(dp[start][end] != -1) return dp[start][end];

    //         int ans = 0;

    //         for(int i=start;i<=end;i++)
    //             ans = max(ans,(nums[start-1]*nums[end+1]*nums[i]) + f(start,i-1,nums,dp) + f(i+1,end,nums,dp));

    //         return dp[start][end] = ans;
    //     }

    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        // vector<vector<int>> dp(n,vector<int>(n,-1));

        // return f(1,n-2,nums,dp);
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int start = n - 2; start >= 1; start--)
        {
            for (int end = start; end <= n - 2; end++)
            {
                int ans = 0;
                for (int i = start; i <= end; i++)
                    ans = max(ans, (nums[start - 1] * nums[i] * nums[end + 1] + dp[start][i - 1] + dp[i + 1][end]));
                dp[start][end] = ans;
            }
        }
        return dp[1][n - 2];
    }
};