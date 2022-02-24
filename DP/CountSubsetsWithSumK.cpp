// You are given an array(0 - based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.Note : Two ways are considered different if sets of indexes of elements chosen by these ways are different.

//                                                                                                                                                                                                                                                 Input is given such that the answer will fit in a 32 -
//     bit integer.For Example : If N = 4 and tar = 3 and the array elements are[1, 2, 2, 3],
//                                  then the number of possible ways are : {1, 2} {3} {1, 2} Hence the output will be 3.

// // https://www.youtube.com/watch?v=ZHyb-A2Mte4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=18

// memoization
int solve(vector<int> &arr, vector<vector<int>> &dp, int tar, int idx)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;
    if (idx > arr.size() - 1)
        return 0;

    if (dp[idx][tar] != -1)
        return dp[idx][tar];

    return dp[idx][tar] = solve(arr, dp, tar, idx + 1) +
                          solve(arr, dp, tar - arr[idx], idx + 1);
}
int findWays(vector<int> &arr, int tar)
{
    int n = arr.size();
    // Write your code here.
    //     vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    //  	return solve(arr,dp,tar,0);

    // tabulation
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (tar >= arr[n - 1])
        dp[n - 1][arr[n - 1]] = 1;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = tar; j >= 1; j--)
        {
            dp[i][j] = dp[i + 1][j];
            if (arr[i] <= j)
                dp[i][j] += dp[i + 1][j - arr[i]];
        }
    }
    return dp[0][tar];
}