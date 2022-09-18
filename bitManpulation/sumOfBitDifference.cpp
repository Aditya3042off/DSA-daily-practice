/* Given an integer array of N integers, find sum of bit differences in all pairs that can be formed from array elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 (first and last bits differ in two numbers).

Note: (x, y) and (y, x) are considered two separate pairs.

Example 1:

Input:
N = 2
arr[] = {1, 2}
Output: 4
Explanation: All pairs in array are (1, 1)
(1, 2), 2, 1), (2, 2)
Sum of bit differences = 0 + 2 + 2 + 0
                       = 4
Example 2:

Input:
N = 3
arr[] = {1, 3, 5}
Output: 8
Explanation:
All pairs in array are (1, 1), (1, 3),
(1, 5), (3, 1), (3, 3) (3, 5),(5, 1),
(5, 3), (5, 5)
Sum of bit differences =  0 + 1 + 1 +
                          1 + 0 + 2 +
                          1 + 2 + 0
                       = 8

https://practice.geeksforgeeks.org/problems/sum-of-bit-differences2937/1 */

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    long long sumBitDifferences(int arr[], int n)
    {
        // code here
        int bitcount[32] = {0};

        for (int idx = 0; idx < n; idx++)
        {
            for (int i = 0; i < 32; i++)
                if (arr[idx] & (1 << i))
                    bitcount[i]++;
        }
        long long ans = 0;

        for (int idx = 0; idx < n; idx++)
        {
            for (int i = 0; i < 32; i++)
            {
                if (arr[idx] & (1 << i))
                    ans += n - bitcount[i];
                else
                    ans += bitcount[i];
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends