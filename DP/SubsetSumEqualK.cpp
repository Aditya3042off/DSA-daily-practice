// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
// For Example :
// If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.

// https://www.youtube.com/watch?v=fWX9xDmIzRI&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=15
// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

#include <bits/stdc++.h>
// memoization
bool solve(vector<int> &arr, vector<vector<int>> &dp, int idx, int target)
{
    if (target == 0)
        return true;
    if (idx > arr.size() - 1 || target < 0)
        return false;

    if (dp[idx][target] != -1)
        return dp[idx][target];

    return dp[idx][target] = solve(arr, dp, idx + 1, target - arr[idx]) ||
                             solve(arr, dp, idx + 1, target);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    int length = arr.size();
    //     vector<vector<int>>dp (length,vector<int>(k+1,-1));

    //     return solve(arr,dp,0,k);

    // tabulation
    vector<vector<int>> dp(length, vector<int>(k + 1, 0));
    if (arr[n - 1] == k)
        return true;
    if (k >= arr[n - 1])
        dp[n - 1][arr[n - 1]] = 1;
    for (int i = n - 1; i >= 0; i--)
        dp[i][0] = 1;

    bool flag = false;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = k; j >= 1; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (j >= arr[i])
                dp[i][j] = dp[i][j] || dp[i + 1][j - arr[i]];
        }
    }
    return dp[0][k];
}