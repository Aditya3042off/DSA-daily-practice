#include <bits/stdc++.h>
using namespace std;

string longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size();
    int n = text2.size();

    // tabulation
    vector<vector<string>> dp(m, vector<string>(n, ""));

    size_t k = text1.find_last_of(text2[n - 1]);
    if (k != string::npos)
    {
        for (int i = 0; i < k + 1; i++)
            dp[i][n - 1] = text2[n - 1];
    }

    k = text2.find_last_of(text1[m - 1]);
    if (k != string::npos)
    {
        for (int i = 0; i < k + 1; i++)
            dp[m - 1][i] = text1[m - 1];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (text1[i] == text2[j])
                dp[i][j] = text1[i] + dp[i + 1][j + 1];

            else if (dp[i + 1][j].size() > dp[i][j + 1].size())
                dp[i][j] = dp[i + 1][j];

            else if (dp[i + 1][j] == dp[i][j + 1])
                dp[i][j] = dp[i + 1][j];

            else
                dp[i][j] = dp[i][j + 1];
        }
    }

    return dp[0][0];
}

int main()
{
    string s1 = "abcde";
    string s2 = "bdgek";
    cout << longestCommonSubsequence(s1, s2);
}
