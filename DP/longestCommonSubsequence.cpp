// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings

// Example 1:

// Input: text1 = "abcde", text2 = "ace"
// Output: 3
// Explanation: The longest common subsequence is "ace" and its length is 3.
// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.
// Example 3:

// Input: text1 = "abc", text2 = "def"
// Output: 0
// Explanation: There is no such common subsequence, so the result is 0.

// https://www.youtube.com/watch?v=NPZn9jBrX8U&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=26

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    //     int solve(string &s1,string &s2,vector<vector<int>>&dp,int idx1,int idx2) {
    //         if(idx1 > s1.size()-1 || idx2 > s2.size()-1) return 0;

    //         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    //         if(s1[idx1] == s2[idx2]) return dp[idx1][idx2] =  1 + solve(s1,s2,dp,idx1+1,idx2+1);

    //         return dp[idx1][idx2] =  max(solve(s1,s2,dp,idx1+1,idx2),solve(s1,s2,dp,idx1,idx2+1));
    //     }

    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        // vector<vector<int>> dp(m,vector<int>(n,0));
        // return solve(text1,text2,dp,0,0);

        // tabulation
        vector<vector<int>> dp(m, vector<int>(n, 0));

        size_t k = text1.find_last_of(text2[n - 1]);
        if (k != string::npos)
        {
            for (int i = 0; i < k + 1; i++)
                dp[i][n - 1] = 1;
        }

        k = text2.find_last_of(text1[m - 1]);
        if (k != string::npos)
        {
            for (int i = 0; i < k + 1; i++)
                dp[m - 1][i] = 1;
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};