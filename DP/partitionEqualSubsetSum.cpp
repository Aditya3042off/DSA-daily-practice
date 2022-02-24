Given a non - empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

                                                                  Example 1 :

    Input : nums = [ 1, 5, 11, 5 ] Output : true Explanation : The array can be partitioned as[1, 5, 5] and[11].Example 2 :

    Input : nums = [ 1, 2, 3, 5 ] Output : false Explanation : The array cannot be partitioned into equal sum subsets.

                                                               https : // www.youtube.com/watch?v=7win3dcgo3k&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=16

                                                                       class Solution
{
public:
    // memoization
    //     bool solve(vector<int>nums,vector<vector<int>> dp,int idx,int target) {
    //         if(target == 0) return true;
    //         if(idx > nums.size() - 1 || target < 0) return false;

    //         if(dp[idx][target] != -1) return dp[idx][target];

    //         return dp[idx][target] = solve(nums,dp,idx+1,target) ||
    //                                  solve(nums,dp,idx+1,target-nums[idx]);
    //     }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum & 1)
            return false;
        int length = nums.size();

        //         vector<vector<int>> dp(length,vector<int>((sum / 2) + 1, -1));

        //         return solve(nums,dp,0,sum/2);

        // tabulation

        int k = sum / 2;
        int n = length;
        vector<vector<int>> dp(length, vector<int>(k + 1, 0));

        if (nums[n - 1] == k)
            return true;

        if (k >= nums[n - 1])
            dp[n - 1][nums[n - 1]] = 1;
        for (int i = n - 1; i >= 0; i--)
            dp[i][0] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = k; j >= 1; j--)
            {
                dp[i][j] = dp[i + 1][j];
                if (j >= nums[i])
                    dp[i][j] = dp[i][j] || dp[i + 1][j - nums[i]];
            }
        }
        return dp[0][k];
    }
};