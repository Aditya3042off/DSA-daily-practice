// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

// Example 1:

// Input:
// N = 7, K = 4
// A[] = {1,2,1,3,4,2,3}
// Output: 3 4 4 3
// Explanation: Window 1 of size k = 4 is
// 1 2 1 3. Number of distinct elements in
// this window are 3.
// Window 2 of size k = 4 is 2 1 3 4. Number
// of distinct elements in this window are 4.
// Window 3 of size k = 4 is 1 3 4 2. Number
// of distinct elements in this window are 4.
// Window 4 of size k = 4 is 3 4 2 3. Number
// of distinct elements in this window are 3.
// Example 2:

// Input:
// N = 3, K = 2
// A[] = {4,1,1}
// Output: 2 1

// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/#
// https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> countDistinct(int arr[], int n, int k)
    {
        // code here.
        vector<int> ans;
        unordered_map<int, int> mp;
        int count = 0;

        for (int i = 0; i < k; i++)
        {
            if (mp.find(arr[i]) == mp.end())
                count++;
            mp[arr[i]]++;
        };
        ans.push_back(count);
        int i = 0;
        for (int j = k; j < n; j++)
        {
            if (mp[arr[i]] == 1)
                count--;
            mp[arr[i]]--;

            if (mp.find(arr[j]) == mp.end() || mp[arr[j]] == 0)
                count++;
            mp[arr[j]]++;
            ans.push_back(count);
            i++;
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> result = obj.countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends