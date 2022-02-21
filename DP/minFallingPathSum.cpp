// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the
// next row that is either directly below or diagonally left/right.
// Specifically, the next element from position (row, col) will be
// (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.

// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

// https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=13

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    //     int solve(vector<vector<int>>& matrix,vector<vector<int>>& dp,int m,int n) {
    //         if(n < 0 || n > matrix[0].size()-1) return INT_MAX;
    //         if(m == matrix.size()-1) return matrix[m][n];

    //         if(dp[m][n] != -1) return dp[m][n];

    //         dp[m][n] = matrix[m][n] + min({solve(matrix,dp,m+1,n),
    //                                        solve(matrix,dp,m+1,n+1),
    //                                        solve(matrix,dp,m+1,n-1)});
    //         return dp[m][n];

    //     }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int ans = INT_MAX;

        // for(int i = 0;i<cols;i++) ans = min(ans,solve(matrix,dp,0,i));
        // return ans;

        // tabulation

        if (rows == 1)
        {
            for (int i : matrix[0])
                ans = min(ans, i);
            return ans;
        }

        for (int i = 0; i < cols; i++)
            dp[rows - 1][i] = matrix[rows - 1][i];

        for (int i = rows - 2; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {

                dp[i][j] = matrix[i][j] + dp[i + 1][j];
                if (j < cols - 1)
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j + 1]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j], matrix[i][j] + dp[i + 1][j - 1]);

                if (i == 0)
                    ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};