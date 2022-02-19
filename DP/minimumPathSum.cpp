// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// https://www.youtube.com/watch?v=_rgTlyky1uQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // returning - 1 when there is no path to final block

    // memoization
    int
    minSum(vector<vector<int>> &grid, vector<vector<int>> &dp, int m, int n)
    {

        if (m == grid.size() - 1 && n == grid[0].size() - 1)
            return grid[m][n];
        if (m >= grid.size() || n >= grid[0].size())
            return -1;

        if (dp[m][n] != -2)
            return dp[m][n];

        int rightPathSum = minSum(grid, dp, m, n + 1);
        int bottomPathSum = minSum(grid, dp, m + 1, n);

        if (rightPathSum != -1 && bottomPathSum != -1)
        {
            dp[m][n] = min(rightPathSum, bottomPathSum) + grid[m][n];
        }
        else if (rightPathSum == -1)
        {
            dp[m][n] = bottomPathSum + grid[m][n];
        }
        else
        {
            dp[m][n] = rightPathSum + grid[m][n];
        }

        return dp[m][n];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -2));
        // return minSum(grid,dp,0,0);
        dp[rows - 1][cols - 1] = grid[rows - 1][cols - 1];

        // tabulation

        for (int m = rows - 1; m >= 0; m--)
        {
            for (int n = cols - 1; n >= 0; n--)
            {
                if (m == rows - 1 and n == cols - 1)
                    continue;

                int right = INT_MAX;
                int bottom = INT_MAX;
                if (n < cols - 1)
                    right = dp[m][n + 1];
                if (m < rows - 1)
                    bottom = dp[m + 1][n];

                dp[m][n] = min(right, bottom) + grid[m][n];
            }
        }
        return dp[0][0];
    }
};