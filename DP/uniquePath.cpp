// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

// https://www.youtube.com/watch?v=sdE0A2Oxofw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=9

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[2] = {1, 0};
    int col[2] = {0, 1};

    // memoization

    int solve(vector<vector<int>> &matrix, vector<vector<int>> &dp, int m, int n)
    {

        if (m == dp.size() - 1 and n == dp[0].size() - 1)
            return 1;
        if (m >= dp.size() || n >= dp[0].size())
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        // go all 2 sides for every index
        dp[m][n] = 0;
        for (int i = 0; i < 2; i++)
        {
            dp[m][n] += solve(matrix, dp, m + row[i], n + col[i]);
        }

        return dp[m][n];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // return solve(matrix,dp,0,0);

        dp[m - 1][n - 1] = 1;

        // tabulation
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {

                if (i < m - 1)
                    dp[i][j] += dp[i + 1][j];
                if (j < n - 1)
                    dp[i][j] += dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};