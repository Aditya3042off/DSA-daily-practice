// Imagine you have a special keyboard with all keys in a single row. The layout of characters on a keyboard is denoted by a string S1 of length 26. S1 is indexed from 0 to 25. Initially, your finger is at index 0.
// To type a character, you have to move your finger to the index of the desired character. The time taken to move your finger from index i to index j is |j-i|, where || denotes absolute value.Find the time taken to type the string S2 with the given keyboard layout.

// Example 1:

// Input:
// S1 = "abcdefghijklmnopqrstuvwxyz"
// S2 = "cba"
// Output:
// 4
// Explanation:
// Initially we are at index 0. To type 'c',
// it will take a time of abs(0-2) = 2. To, type
// 'b' next, it will take abs(2-1) = 1. And, for
// 'a', it will take abs(1-0) = 1 unit time.
// So, total time = 2+1+1 = 4.
// Example 2:

// Input:
// S1 = "zyxwvutsrqponmlkjihgfedcba"
// S2 = "a"
// Output:
// 25
// Explanation:
// 'a' is at index 25. So, the time taken
// to type 'a' will be abs(0-25) = 25.

// https://practice.geeksforgeeks.org/problems/228d0aa9f26db93ee5b2cb3583dbd4b197447e16/1?page=1&curated[]=3&curated[]=6&sortBy=submissions

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int findTime(string keyboard, string str)
    {
        // code here
        unordered_map<char, int> pos;
        for (int i = 0; i < 26; i++)
            pos[keyboard[i]] = i;

        int ans = 0;
        int idx = 0;

        for (char c : str)
        {
            ans += abs(pos[c] - idx);
            idx = pos[c];
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
        string S1, S2;
        cin >> S1;
        cin >> S2;

        Solution ob;
        cout << ob.findTime(S1, S2) << endl;
    }
    return 0;
}
// } Driver Code Ends