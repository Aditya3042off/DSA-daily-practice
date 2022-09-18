// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The efficient way is the one that involves the least number of multiplications.

// The dimensions of the matrices are given in an array arr[] of size N
// (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Example 1:

// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explaination: There are 4 matrices of dimension
// 40x20, 20x30, 30x10, 10x30. Say the matrices are
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D.
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.

// Example 2:

// Input: N = 4
// arr = {10, 30, 5, 60}
// Output: 4500
// Explaination: The matrices have dimensions
// 10*30, 30*5, 5*60. Say the matrices are A, B
// and C. Out of all possible combinations,the
// most efficient way is (A*B)*C. The
// number of multiplications are -
// 10*30*5 + 10*5*60 = 4500.

//{ Driver Code Starts
// Initial Template for C++

// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // memoization
    int f(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {
            ans = min(ans, arr[i - 1] * arr[k] * arr[j] + f(i, k, arr, dp) + f(k + 1, j, arr, dp));
        }

        return dp[i][j] = ans;
    }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        int i = 1, j = n - 1;
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return f(i,j,arr,dp);

        // tabulation
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for (int i = n - 2; i >= 1; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i; k < j; k++)
                    ans = min(ans, arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
                dp[i][j] = ans;
            }
        }
        return dp[1][n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends