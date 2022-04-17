// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')
// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5
// Explanation:
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')

// https://www.youtube.com/watch?v=fJaKO8FbDdo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=34

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    //     int solve(vector<vector<int>>& dp,string s1,string s2,int idx1,int idx2) {
    //         if(idx1 == s1.size() and idx2 == s2.size()) return 0;
    //         else if(idx1 == s1.size()) return s2.size()-idx2;
    //         else if(idx2 == s2.size()) return s1.size()-idx1;

    //         if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    //         if(s1[idx1] == s2[idx2])
    //             return dp[idx1][idx2] = solve(dp,s1,s2,idx1+1,idx2+1);
    //         else
    //             return dp[idx1][idx2] = 1 + min({solve(dp,s1,s2,idx1,idx2+1),
    //                                              solve(dp,s1,s2,idx1+1,idx2),
    //                                              solve(dp,s1,s2,idx1+1,idx2+1)});

    //     }

    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if (m == 0)
            return n;
        if (n == 0)
            return m;
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // return solve(dp,word1,word2,0,0);

        // tabulation
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // base cases
        for (int i = 0; i < m; i++)
        {
            if ((word1.substr(i)).find(word2[n - 1]) != string::npos)
                dp[i][n - 1] = m - 1 - i;
            else
                dp[i][n - 1] = m - i;
        }
        for (int i = 0; i < n; i++)
        {
            if ((word2.substr(i)).find(word1[m - 1]) != string::npos)
                dp[m - 1][i] = n - 1 - i;
            else
                dp[m - 1][i] = n - i;
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = 1 + min({dp[i + 1][j], dp[i + 1][j + 1], dp[i][j + 1]});
            }
        }
        return dp[0][0];
    }
};