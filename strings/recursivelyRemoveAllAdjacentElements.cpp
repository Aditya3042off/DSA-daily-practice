// https://www.youtube.com/watch?v=e6qvg0t1nh0&list=PLjeQ9Mb66hM05uqfKysHKi3eA5HhK7QSy&index=4
// https://practice.geeksforgeeks.org/problems/recursively-remove-all-adjacent-duplicates0744/1

// Given a string s, remove all its adjacent duplicate characters recursively.

// Example 1:

// Input:
// S = "geeksforgeek"
// Output: "gksforgk"
// Explanation:
// g(ee)ksforg(ee)k -> gksforgk

// Example 2:

// Input:
// S = "abccbccba"
// Output: ""
// Explanation:
// ab(cc)b(cc)ba->abbba->a(bbb)a->aa->(aa)->""(empty string)

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    string rremove(string s)
    {
        // code here

        string temp = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1)
                temp += s[i];
            else
            {
                if (s[i] != s[i + 1])
                    temp += s[i];
                else
                {
                    while (i < s.size() - 1 and s[i] == s[i + 1])
                        i++;
                }
            }
        }

        if (s.size() == temp.size())
            return temp;
        return rremove(temp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends