// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

// https://www.youtube.com/watch?v=HLZLwjzIVGo
// https://www.youtube.com/watch?v=1xfx6M_GqFk
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // memoization
    //     int solve(int n,int k,int currSum,vector<int>& dp) {
    //         if(currSum == n) return 0;

    //         if(dp[currSum] != -1) return dp[currSum];
    //         int count = INT_MAX;

    //         for(int i=1;i<=k;i++) {
    //             if(currSum + (i*i) > n) break;
    //             count = min(count,1+solve(n,k,currSum+(i*i),dp));
    //         }
    //         return dp[currSum] = count;
    //     }

    int numSquares(int n)
    {
        int k = 1;
        while (k * k <= n)
            k++;
        k--;
        if (k * k == n)
            return 1;
        //         vector<int>dp(n+1,-1);
        //         return solve(n,k,0,dp);

        // tabulation
        int count = INT_MAX;
        vector<int> dp(n + 1, 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            count = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                if (i + (j * j) > n)
                    break;
                count = min(count, 1 + dp[i + (j * j)]);
            }
            dp[i] = count;
        }
        return dp[0];
    }
};