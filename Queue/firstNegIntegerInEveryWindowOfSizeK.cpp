// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// https://www.youtube.com/watch?v=_gJ3to4RyeQ&list=PLDzeHZWIZsTrhXYYtx4z8-u8zA-DzuVsj&index=8

// Given an array A[] of size N and a positive integer K, find the first negative integer
// for each and every window(contiguous subarray) of size K.

// Example 1:

// Input :
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output :
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

// Example 2:
// Input :
// N = 8
// A[] = {12, -1, -7, 8, -15, 30, 16, 28}
// K = 3
// Output :
// -1 -1 -7 -15 -15 0

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int arr[], long long int N, long long int K)
{

    vector<long long> ans;
    queue<pair<long long, long long>> q;

    for (int i = 0; i < K; i++)
    {
        if (arr[i] < 0)
            q.push({arr[i], i});
    }

    for (int i = K - 1; i < N; i++)
    {
        if (q.empty())
            ans.push_back(0);
        else
            ans.push_back(q.front().first);

        if (!q.empty() and q.front().second <= i + 1 - K)
            q.pop();
        if (i + 1 < N and arr[i + 1] < 0)
            q.push({arr[i + 1], i + 1});
    }

    return ans;
}