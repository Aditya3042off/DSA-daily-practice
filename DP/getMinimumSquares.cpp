// Given a number N. Find the minimum number of squares of any number that sums to N.
// For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5)
// but the output will be 1 as minimum number of square is 1 , i.e (10*10).

// Example 1:

// Input: N = 100
// Output: 1
// Explanation: 10 * 10 = 100
// Example 2:

// Input: N = 6
// Output: 3
// Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    // 	int f(int n,int dp[]) {
    // 	    if(n == 0) return 0;
    // 	    if(n == 1) return 1;
    // 	    if(dp[n] != -1) return dp[n];
    // 	    int ans = INT_MAX;
    // 	    for(int i = 1;i*i <= n;i++){
    // 	        int temp = 1 + f(n- i*i,dp);
    // 	        ans = min(ans,temp);
    // 	    }
    // 	    return dp[n] = ans;
    // 	}

    int MinSquares(int n)
    {
        // Code here
        int dp[n + 1];
        memset(dp, 1000000007, sizeof(dp));
        // return f(n,dp);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.MinSquares(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends