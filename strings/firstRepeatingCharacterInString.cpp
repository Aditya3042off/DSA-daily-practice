// https://practice.geeksforgeeks.org/problems/repeated-character2058/1
// Given a string consisting of lowercase english alphabets.
// Find the repeated character present first in the string.

// Example 1:

// Input:
// S = "geeksforgeeks"
// Output: g
// Explanation: g, e, k and s are the repeating
// characters. Out of these, g occurs first.
// Example 2:

// Input:
// S = "abcde"
// Output: -1
// Explanation: No repeating character present.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    char firstRep(string s)
    {
        // code here.
        unordered_map<char, int> freq;
        for (char ch : s)
            freq[ch]++;

        for (int i = 0; i < s.size(); i++)
            if (freq[s[i]] != 1)
                return s[i];

        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        char res = ob.firstRep(s);
        if (res == '#')
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends