// Given two strings. The task is to find the length of the longest common substring.

// Example 1:

// Input: S1 = "ABCDGH", S2 = "ACDGHR"
// Output: 4
// Explanation: The longest common substring
// is "CDGH" which has length 4.
// Example 2:

// Input: S1 = "ABC", S2 "ACB"
// Output: 1
// Explanation: The longest common substrings
// are "A", "B", "C" all having length 1.

// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
// https://www.youtube.com/watch?v=_wP9mWNPL5w&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=28

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            if (s1[i] == s2[m - 1])
                dp[i][m - 1] = 1;
        for (int i = 0; i < m; i++)
            if (s1[n - 1] == s2[i])
                dp[n - 1][i] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                if (s1[i] != s2[j])
                    continue;
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
        }
        int ans = INT_MIN;
        for (auto vect : dp)
        {
            for (int i : vect)
                ans = max(i, ans);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends