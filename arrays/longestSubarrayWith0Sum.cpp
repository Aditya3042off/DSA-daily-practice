// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

// Example 1:

// Input:
// N = 8
// A[] = {15,-2,2,-8,1,7,10,23}
// Output: 5
// Explanation: The largest subarray with
// sum 0 will be -2 2 -8 1 7.

// https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this function*/

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        // Your code here
        int temp = 0;
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            temp += arr[i];
            if (arr[i] == 0)
                ans = max(ans, 1);
            if (temp == 0)
                ans = max(ans, i + 1);

            if (mp.find(temp) != mp.end())
                ans = max(ans, i - mp[temp]);
            else
                mp[temp] = i;
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
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends