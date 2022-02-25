// A thief is robbing a store and can carry a maximum weight of ‘W’ into his knapsack.There are 'N' items available in the store and the weight and value of each item is known to the thief.Considering the constraints of the maximum weight that a knapsack can carry,
// you have to find the maximum profit that a thief can generate by stealing items.Note : The thief is not allowed to break the items.For example, N = 4, W = 10 and the weights and values of items are weights = [ 6, 1, 5, 3 ] and values = [ 3, 6, 1, 4 ].Then the best way to fill the knapsack is to choose items with weight 6, 1 and 3. The total value of knapsack = 3 + 6 + 4 = 13.
//
// https :// www.codingninjas.com/codestudio/problems/1072980?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// https : // www.youtube.com/watch?v=GqOmJHQZivw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=20

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
// memoization
//  int solve(vector<int> &values, vector<int> &weights,vector<vector<int>>& dp,int idx,int w,int sum) {
//      if(idx > values.size()-1 || sum == w) return 0;

//     if(dp[idx][sum] != -1) return dp[idx][sum];

//     //not pick
//     dp[idx][sum] = solve(values,weights,dp,idx+1,w,sum);
//     //pick
//     if(sum + weights[idx] <= w)
//         dp[idx][sum] = max(dp[idx][sum],values[idx] + solve(values,weights,dp,idx+1,w,sum+weights[idx]));
//     return dp[idx][sum];
// }
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    //  	vector<vector<int>>dp(n,vector<int>(w+1,-1));
    // 	return solve(values,weights,dp,0,w,0);

    // tabulation
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = 0; i <= w - weights[n - 1]; i++)
        dp[n - 1][i] = values[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (j + weights[i] <= w)
                dp[i][j] = max(dp[i][j], values[i] + dp[i + 1][j + weights[i]]);
        }
    }
    return dp[0][0];
}