// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and space is marked as 1 and 0 respectively in the grid.

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

// https://www.youtube.com/watch?v=TmhpgXScLyY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=11

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row[2] = {0, 1};
    int col[2] = {1, 0};
    int solve(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int m, int n)
    {
        if (m >= obstacleGrid.size() || n >= obstacleGrid[0].size())
            return 0;
        if (m == obstacleGrid.size() - 1 and n == obstacleGrid[0].size() - 1)
            return 1;

        if (obstacleGrid[m][n] == 1)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];

        dp[m][n] = 0;
        for (int i = 0; i < 2; i++)
            dp[m][n] += solve(obstacleGrid, dp, m + row[i], n + col[i]);

        return dp[m][n];
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, dp, 0, 0);
    }
};