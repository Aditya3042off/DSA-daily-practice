// Given an n x n integer matrix grid,
//     return the minimum sum of a falling path with non - zero shifts.

//                                                         A falling path with non -
//                zero shifts is a choice of exactly
//                    one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

//                Input : arr = [ [ 1, 2, 3 ], [ 4, 5, 6 ], [ 7, 8, 9 ] ] Output : 13 Explanation : The possible falling paths are : [ 1, 5, 9 ],
//                        [ 1, 5, 7 ], [ 1, 6, 7 ], [ 1, 6, 8 ],
//                        [ 2, 4, 8 ], [ 2, 4, 9 ], [ 2, 6, 7 ], [ 2, 6, 8 ],
//                        [ 3, 4, 8 ], [ 3, 4, 9 ], [ 3, 5, 7 ], [ 3, 5, 9 ] The falling path with the smallest sum is[1, 5, 7], so the answer is 13. Example 2 :

//     Input : grid = [[7]] Output : 7

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    //      int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int m,int n,int cols) {
    //          if(n < 0 || n > grid[0].size()-1) return INT_MAX;
    //          if(m==grid.size()-1) return grid[m][n];

    //         if(dp[m][n] != -1) return dp[m][n];

    //         for(int i=0;i<cols;i++) {
    //             if(i == n) continue;
    //             if(dp[m][n] == -1) {
    //                 dp[m][n] = grid[m][n] + solve(grid,dp,m+1,i,cols);
    //                 continue;
    //             }
    //             dp[m][n] = min(grid[m][n] + solve(grid,dp,m+1,i,cols), dp[m][n]);
    //         }
    //         return dp[m][n];
    //     }

    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        // vector<vector<int>>dp(rows,vector<int>(cols,-1));
        // int ans = INT_MAX;

        // for(int i = 0;i<cols;i++) {
        //     ans = min(ans,solve(grid,dp,0,i,cols));
        // }
        // return ans;

        // tabulation

        if (rows == 1)
        {
            sort(grid[0].begin(), grid[0].end());
            return grid[0][0];
        }

        pair<int, int> min1(-1, INT_MAX);
        pair<int, int> min2(-1, INT_MAX);

        for (int i = 0; i < cols; i++)
        {
            if (grid[rows - 1][i] < min1.second)
            {
                min2 = make_pair(min1.first, min1.second);
                min1 = make_pair(i, grid[rows - 1][i]);
            }
            else if (grid[rows - 1][i] < min2.second)
            {
                min2 = make_pair(i, grid[rows - 1][i]);
            }
        }

        for (int i = rows - 2; i >= 0; i--)
        {
            pair<int, int> temp1(-1, INT_MAX);
            pair<int, int> temp2(-2, INT_MAX);

            for (int j = cols - 1; j >= 0; j--)
            {
                pair<int, int> temp3(-2, 0);
                temp3.first = j;

                if (j != min1.first)
                    temp3.second = grid[i][j] + min1.second;
                else
                    temp3.second = grid[i][j] + min2.second;

                if (temp3.second < temp1.second)
                {
                    temp2 = make_pair(temp1.first, temp1.second);
                    temp1 = make_pair(temp3.first, temp3.second);
                }
                else if (temp3.second < temp2.second)
                {
                    temp2 = make_pair(temp3.first, temp3.second);
                }
            }
            min1 = make_pair(temp1.first, temp1.second);
            min2 = make_pair(temp2.first, temp2.second);
        }
        return min1.second;
    }
};