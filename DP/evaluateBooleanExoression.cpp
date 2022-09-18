/* Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.



Example 1:

Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates
to true in 4 ways ((T|T)&(F^T)),
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:

Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the
only ways.

https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define mod 1003
class Solution
{
public:
    // recursion
    /*
        int f(int start,int end,bool isTrue,string s) {
            if(start == end) {
                if(isTrue) return s[start] == 'T';
                return s[start] == 'F';
            }

            int count = 0;

            for(int i=start+1;i<end;i += 2) {
                int lt = f(start,i-1,true,s);
                int lf = f(start,i-1,false,s);
                int rt = f(i+1,end,true,s);
                int rf = f(i+1,end,false,s);

                if(s[i] == '&'){
                    if(isTrue) count += lt*rt;
                    else count += lt*rf + lf*rt + lf*rf;
                }
                else if(s[i] == '|'){
                    if(isTrue) count += lt*rt + lt*rf + lf*rt;
                    else count += lf*rf;
                }
                else if(s[i] == '^'){
                    if(isTrue) count += lt*rf + lf*rt;
                    else count += lt*rt + lf*rf;
                }
            }

            return count;
        }
    */
    int countWays(int n, string s)
    {
        // code here

        int dp[n][n][2];
        memset(dp, 0, sizeof(dp));

        for (int start = n - 1; start >= 0; start--)
        {
            for (int end = start; end <= n - 1; end++)
            {
                if (start == end)
                {
                    dp[start][end][1] = (s[start] == 'T');
                    dp[start][end][0] = (s[start] == 'F');
                }
                else
                {
                    for (int i = start + 1; i < end; i += 2)
                    {
                        int lt = dp[start][i - 1][1];
                        int lf = dp[start][i - 1][0];
                        int rt = dp[i + 1][end][1];
                        int rf = dp[i + 1][end][0];

                        if (s[i] == '&')
                        {
                            dp[start][end][1] = (dp[start][end][1] + (lt * rt) % mod) % mod;
                            dp[start][end][0] = (dp[start][end][0] + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
                        }
                        else if (s[i] == '|')
                        {
                            dp[start][end][1] = (dp[start][end][1] + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                            dp[start][end][0] = (dp[start][end][0] + (lf * rf) % mod) % mod;
                        }
                        else if (s[i] == '^')
                        {
                            dp[start][end][1] = (dp[start][end][1] + (lt * rf) % mod + (lf * rt) % mod) % mod;
                            dp[start][end][0] = (dp[start][end][0] + (lt * rt) % mod + (lf * rf) % mod) % mod;
                        }
                    }
                }
            }
        }
        return dp[0][n - 1][1];
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
}
// } Driver Code Ends