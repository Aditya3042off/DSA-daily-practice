// // https://www.geeksforgeeks.org/policemen-catch-thieves/

// Given an array of size n such that each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police.
// Keep in mind the following conditions :

// Each policeman can catch only one thief.
// A policeman cannot catch a thief who is more than K units away from him.
// Example 1:

// Input:
// N = 5, K = 1
// arr[] = {P, T, T, P, T}
// Output: 2
// Explanation: Maximum 2 thieves can be
// caught. First policeman catches first thief
// and second police man can catch either second
// or third thief.
// Example 2:

// Input:
// N = 6, K = 2
// arr[] = {T, T, P, P, T, P}
// Output: 3
// Explanation: Maximum 3 thieves can be caught.

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int catchThieves(char arr[], int n, int k)
    {
        int police = -1;
        int thief = -1;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'P')
            {
                police == i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 'T')
            {
                thief == i;
                break;
            }
        }
        if (police == -1 or thief == -1)
            return 0;

        while (police < n and thief < n)
        {
            if (abs(police - thief) <= k)
            {
                ans++;
                police++;
                thief++;
                while (police < n and arr[police] != 'P')
                    police++;
                while (thief < n and arr[thief] != 'T')
                    thief++;
            }
            else if (police < thief)
            {
                police++;
                while (police < n and arr[police] != 'P')
                    police++;
            }
            else
            {
                thief++;
                while (thief < n and arr[thief] != 'T')
                    thief++;
            }
        }
        return ans;

        /*
            method-1
            queue<int> q;
            for(int i=0;i<n;i++){
                if(arr[i] == 'T') q.push(i);
            }

            int ans = 0;

            for(int i=0;i<n;i++){
                if(arr[i] == 'T') continue;
                if(q.empty()) break;

                while(i-q.front() > k) q.pop();
                if(abs(i-q.front()) <= k) {
                    ans++;
                    q.pop();
                }
            }
            return ans;
        */
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        char arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.catchThieves(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends