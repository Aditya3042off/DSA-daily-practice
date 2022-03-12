// Given a string s. In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// Example 1:

// Input: s = "zzazz"
// Output: 0
// Explanation: The string "zzazz" is already palindrome we don't need any insertions.
// Example 2:

// Input: s = "mbadm"
// Output: 2
// Explanation: String can be "mbdadbm" or "mdbabdm".
// Example 3:

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

// https://www.youtube.com/watch?v=xPBLEj41rFU&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=30

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // If we know the longest palindromic sub-sequence is x and the length of the string is n then, what         is the answer to this problem? It is n - x as we need n - x insertions to make the remaining               characters also palindrome.
    int minInsertions(string s)
    {

        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        size_t k = s.find_last_of(s2[n - 1]);
        if (k != string::npos)
        {
            for (int i = 0; i < k + 1; i++)
                dp[i][n - 1] = 1;
        }

        k = s2.find_last_of(s[n - 1]);
        if (k != string::npos)
        {
            for (int i = 0; i < k + 1; i++)
                dp[n - 1][i] = 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                if (s[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return n - dp[0][0];
    }
};