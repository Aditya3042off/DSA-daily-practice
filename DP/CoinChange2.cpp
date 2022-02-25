// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

// Example 1:

// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.
// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1

// https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {

        // tabulation

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int amt = 0; amt < amount; amt++)
            if (((amount - amt) % coins[n - 1]) == 0)
                dp[n - 1][amt] = 1;
        for (int i = 0; i < n; i++)
            dp[i][amount] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = amount - 1; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j];
                if (j + coins[i] <= amount)
                    dp[i][j] += dp[i][j + coins[i]];
            }
        }

        return dp[0][0];
    }
};
