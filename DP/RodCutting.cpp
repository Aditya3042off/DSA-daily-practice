// Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it.
//  Determine the maximum cost obtained by cutting the rod and selling its pieces.
// Note:
// 1. The sizes will range from 1 to ‘N’ and will be integers.

// 2. The sum of the pieces cut should be equal to ‘N’.

// 3. Consider 1-based indexing.
// Input Format:
// The first line of input contains an integer ‘T’ denoting the number of test cases.

// The next 2 * T lines represent the ‘T’ test cases.

// The first line of each test case contains an integer ‘N’ denoting the length of the rod.

// The second line of each test case contains a vector ’A’, of size ‘N’ representing the cost of different lengths,
// where each index of the array is the sub-length and the element at that index is the cost for that sub-length.

// 2
// 5
// 2 5 7 8 10
// 8
// 3 5 8 9 10 17 17 20
// Sample Output 1:
// 12
// 24

// 1
// 6
// 3 5 6 7 10 12
// Sample Output 2:
// 18

// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
// https://www.youtube.com/watch?v=mO8XpGoJwuo&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=25

#include <bits/stdc++.h>
using namespace std;

// memoization
//  int solve(vector<int>& price,vector<int>&dp,int length,int n) {
//      if(length == n) return 0;
//      if(dp[length] != -1) return dp[length];
//      int ans = 0;
//      for(int j=1;j<=n;j++)
//          if(length + j <= n)
//              ans = max(ans,price[j-1] + solve(price,dp,length+j,n));
//      return dp[length] = ans;
//  }

int cutRod(vector<int> &price, int n)
{
    //     vector<int>dp(n,-1);
    // 	return solve(price,dp,0,n);

    // tabulation
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = 1; j <= n; j++)
            if (i + j <= n)
                dp[i] = max(dp[i], price[j - 1] + dp[i + j]);
    }
    return dp[0];
}
