// https://www.codingninjas.com/codestudio/problems/count-derangements_873861?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
// https://www.youtube.com/watch?v=NW-BLDQHFXk&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=117

#define mod 1000000007
#include <bits/stdc++.h>
// long long f(int n,long long *dp){
//     if(n==1) return 0;
//     if(n==2) return 1;
//     if(dp[n] != -1) return dp[n];
//     long long ans =  0;
//     long long part1 = f(n-1,dp) % mod;
//     long long part2 = f(n-2,dp) % mod;

//     ans = ((n-1) * ((part1+part2)%mod))%mod;
//     return dp[n] = ans;
// }

long long int countDerangements(int n)
{
    // Write your code here.
    long long dp[n + 1] = {0};
    //     return f(n,dp);

    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        long long part1 = dp[i - 1] % mod;
        long long part2 = dp[i - 2] % mod;
        dp[i] = ((i - 1) * ((part1 + part2) % mod)) % mod;
    }
    return dp[n];
}