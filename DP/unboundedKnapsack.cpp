// You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with weight capacity ‘W’. You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.
// For Example
// Let us say we have 'N' = 3 items and a knapsack of capacity 'W' =  10
// 'PROFIT' = { 5, 11, 13 }
// 'WEIGHT' = { 2, 4, 6 }

// We can fill the knapsack as:

// 1 item of weight 6 and 1 item of weight 4.
// 1 item of weight 6 and 2 items of weight 2.
// 2 items of weight 4 and 1 item of weight 2.
// 5 items of weight 2.

// The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.

// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// https://www.youtube.com/watch?v=OgvOZ6OrJoY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=24&t=110s

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
// memoization
//  int solve(vector<int> &profit, vector<int> &weights,vector<vector<int>>& dp,int idx,int w,int weight) {
//      if(idx == profit.size() -1) {
//          if(weights[idx] + weight > w) return 0;
//          return profit[idx] * ((w-weight) / weights[idx]);
//      }
//      if(w == weight) return 0;

//     if(dp[idx][weight] != -1) return dp[idx][weight];
//     //not pick
//     int notPick = solve(profit,weights,dp,idx+1,w,weight);
//     //pick
//     int pick = INT_MIN;
//     if(weights[idx] + weight <= w ) pick = profit[idx] + solve(profit,weights,dp,idx,w,weight+weights[idx]);

//     return dp[idx][weight] = max(pick,notPick);
// }

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weights)
{
    //     vector<vector<int>> dp(n,vector<int>(w+1,-1));
    //     return solve(profit,weights,dp,0,w,0);

    // tabulation
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = 0; i <= w; i++)
        if (i + weights[n - 1] <= w)
            dp[n - 1][i] = profit[n - 1] * ((w - i) / weights[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (j + weights[i] <= w)
                dp[i][j] = max(dp[i][j], profit[i] + dp[i][j + weights[i]]);
        }
    }
    return dp[0][0];
}