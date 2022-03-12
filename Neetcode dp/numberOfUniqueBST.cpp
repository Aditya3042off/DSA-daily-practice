// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
// Input: n = 3
// Output: 5
// Example 2:

// Input: n = 1
// Output: 1

// https://www.youtube.com/watch?v=Ox0TenN3Zpg&t=401s
// https://www.youtube.com/watch?v=OIc0mHgHUww&t=56s

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    //     int findTrees(int n, vector<int>& dp) {
    //         if(n ==0 || n==1) return 1;

    //         if(dp[n] != -1) return dp[n];
    //         int count = 0;

    //         for(int i=0;i<n;i++) {
    //             count += findTrees(n-i-1,dp) * findTrees(i,dp);
    //         }
    //         return dp[n] = count;
    //     }

    int numTrees(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        // vector<int>dp(n+1,-1);
        // return findTrees(n,dp);

        // tabulation

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= i - 1; j++)
            {
                dp[i] += dp[i - j - 1] * dp[j];
            }
        }
        return dp[n];
    }

    // recursion-> TLE
    //     int numTrees(int n) {
    //         if(n ==0 || n==1) return 1;
    //         int count = 0;

    //         for(int i=0;i<n;i++) {
    //             count += numTrees(n-1-i) * numTrees(i);
    //         }
    //         return count;
    //     }
};