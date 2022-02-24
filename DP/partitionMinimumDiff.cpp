// You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.
// Note:
// 1. Each element of the array should belong to exactly one of the subset.

// 2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

// 3. Subset-sum is the sum of all the elements in that subset.

// https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=17

#include <bits/stdc++.h>

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int length = arr.size();
    // Write your code here.
    int sum = 0;
    for (int i : arr)
        sum += i;
    vector<vector<bool>> dp(length, vector<bool>((sum / 2) + 1, false));

    for (int i = 0; i < length; i++)
        dp[i][0] = true;
    if ((sum / 2 + 1) >= arr[length - 1])
        dp[length - 1][arr[length - 1]] = true;

    for (int i = length - 2; i >= 0; i--)
    {
        for (int j = sum / 2; j >= 1; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (arr[i] <= j)
                dp[i][j] = dp[i][j] || dp[i + 1][j - arr[i]];
        }
    }
    int ans = 1e9;
    for (int i = 0; i < (sum / 2) + 1; i++)
        if (dp[0][i])
            ans = min(ans, abs(sum - 2 * i));
    return ans;
}
