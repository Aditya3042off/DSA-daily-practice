// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:

// Input: s = "rabbbit", t = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// rabbbit
// rabbbit
// rabbbit
// Example 2:

// Input: s = "babgbag", t = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// https://www.youtube.com/watch?v=nVG7eTiD2bY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=33&t=1447s

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // memoization
    //     int solve(string s,string t,int idx1,int idx2,vector<vector<int>>& dp){
    //         if(idx2 > t.size()-1) return 1;
    //         if(idx1 > s.size()-1) return 0;

    //         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    //         dp[idx1][idx2] = 0;

    //         dp[idx1][idx2] = solve(s,t,idx1+1,idx2,dp);
    //         if(s[idx1] == t[idx2])
    //             dp[idx1][idx2] += solve(s,t,idx1+1,idx2+1,dp);

    //         return dp[idx1][idx2];
    //     }

    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(s,t,0,0,dp);

        // tabulation
        vector<vector<double>> dp(m, vector<double>(n, 0));
        int count = 0;
        for (int i = m - 1; i >= 0; i--)
        {
            if (s[i] == t[n - 1])
                count++;
            dp[i][n - 1] = count;
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j];
                if (s[i] == t[j])
                    dp[i][j] += dp[i + 1][j + 1];
            }
        }
        return (int)dp[0][0];
    }
};