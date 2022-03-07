// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

// https://www.youtube.com/watch?v=6i_T5kkfv4A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=29

class Solution
{
public:
    int longestPalindromeSubseq(string s)
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
        return dp[0][0];
    }
};