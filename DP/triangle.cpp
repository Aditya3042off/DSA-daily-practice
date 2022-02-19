// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10

// https://www.youtube.com/watch?v=SrP-PiLSYC0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=12

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // memoization
    int findMin(vector<vector<int>> &triangle, vector<vector<int>> &dp, int m, int n)
    {
        if (m == dp.size() - 1)
            return triangle[m][n];

        if (dp[m][n] != -1)
            return dp[m][n];

        int bottom = findMin(triangle, dp, m + 1, n);
        int cross = findMin(triangle, dp, m + 1, n + 1);

        return dp[m][n] = min(bottom, cross) + triangle[m][n];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        int rows = triangle.size();
        int cols = triangle[rows - 1].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        // return findMin(triangle,dp,0,0);

        // tabulation
        for (int i = 0; i < cols; i++)
            dp[rows - 1][i] = triangle[rows - 1][i];

        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = triangle[i].size() - 1; j >= 0; j--)
            {
                if (i == rows - 1)
                    continue;

                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};