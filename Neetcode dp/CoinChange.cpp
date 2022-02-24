// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//     Return the fewest number of coins that you need to make up that amount.If that amount of money cannot be made up by any combination of the coins,
//     return -1.

//             You may assume that you have an infinite number of each kind of coin.

//             Example 1 :

//     Input : coins = [ 1, 2, 5 ],
//             amount = 11 Output : 3 Explanation : 11 = 5 + 5 + 1 Example 2 :

//     Input : coins = [2],
//             amount = 3 Output : -1 Example 3 :

//     Input : coins = [1],
//             amount = 0 Output : 0

// https://www.youtube.com/watch?v=H9bfqozjoqs

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // memoization
    //     int solve(vector<int>& coins,vector<vector<long>>& dp,int amount,int idx,long sum) {
    //         if(idx > coins.size()-1) {
    //             if(amount == sum) return 0;
    //             return -1;
    //         }
    //         if(amount == sum) return 0;

    //         if(dp[idx][sum] != -2) return dp[idx][sum];

    //         //pick
    //         int pick = -1;
    //         if(sum + coins[idx] <= amount) pick =  solve(coins,dp,amount,idx,sum + coins[idx]);
    //         //non pick
    //         int notPick = solve(coins,dp,amount,idx+1,sum);

    //         if(pick == -1 and notPick != -1) return dp[idx][sum] = notPick;
    //         if(pick != -1 and notPick == -1) return dp[idx][sum] = pick+1;

    //         return dp[idx][sum] = min(pick+1,notPick);

    //     }

    int coinChange(vector<int> &coins, int amount)
    {
        //         vector<vector<long>> dp(coins.size(),vector<long>(amount+1,-2));

        //         return solve(coins,dp,amount,0,0);

        // tabulation
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1, INT_MAX);

        dp[amount] = 0;

        for (long i = amount - 1; i >= 0; i--)
        {

            for (int j = 0; j < coins.size(); j++)
            {
                if (i + coins[j] <= amount && dp[i + coins[j]] < INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i + coins[j]]);
            }
        }
        if (dp[0] == INT_MAX)
            return -1;
        return dp[0];
    }
};