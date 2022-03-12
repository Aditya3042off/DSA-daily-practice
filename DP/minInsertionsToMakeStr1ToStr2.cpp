// You are given 2 non-empty strings “str” and “ptr” consisting of lowercase English alphabets only. Your task is to convert string “str” into string “ptr”. In one operation you can do either of the following on “str”:
// Remove a character from any position in “str”.
// Add a character to any position in “str”.
// You have to find the minimum number of operations required to convert string “str” into “ptr”.

// Sample Input 1 :
// 2
// abcd anc
// aa aaa
// Sample Output 1 :
// 3
// 1
// Explanation For Sample Output 1:
// For the first test case,
// str = “abcd”, ptr = “anc”

// In one operation remove str[3], after this operation str becomes “abc”.
// In the second operation remove str[1], after this operation str becomes “ac”.
// In the third operation add ‘n’ in str[1], after this operation str becomes “anc”.

// Hence, the output will be 3.

// For the second test case,
// str = “aaa”, ptr = “aa”

// In one operation remove str[2], after this operation str becomes “aa”.

// Hence, the output will be 1.
// Sample Input 2 :
// 2
// cue dgo
// edl xcqja
// Sample Output 2 :
// 6
// 8

// https://www.youtube.com/watch?v=yMnH0jrir0Q&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=31
// https://www.codingninjas.com/codestudio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int canYouMake(string &str, string &ptr)
{
    // using LCS concept
    int m = str.size();
    int n = ptr.size();
    // Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, 0));
    size_t k;

    k = str.find_last_of(ptr[n - 1]);
    if (k != string::npos)
        for (int i = 0; i <= k; i++)
            dp[i][n - 1] = 1;
    k = ptr.find_last_of(str[m - 1]);
    if (k != string::npos)
        for (int i = 0; i <= k; i++)
            dp[m - 1][i] = 1;

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (str[i] == ptr[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return m + n - 2 * dp[0][0];
}