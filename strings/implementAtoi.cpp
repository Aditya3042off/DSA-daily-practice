// https://www.youtube.com/watch?v=TF0ELh6fpWo&list=PLjeQ9Mb66hM05uqfKysHKi3eA5HhK7QSy&index=5
// https://practice.geeksforgeeks.org/problems/implement-atoi/1

// Your task  is to implement the function atoi. The function takes a string(str) as argument and
// converts it to an integer and returns it.

// Note: You are not allowed to use inbuilt function.

// Example 1:

// Input:
// str = 123
// Output: 123
// Example 2:

// Input:
// str = 21a
// Output: -1
// Explanation: Output is -1 as all
// characters are not digit only.

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        // Your code here
        int ans = 0;

        bool flag = false;

        for (int i = 0; i <= str.size() - 1; i++)
        {

            if (i == 0 and str[0] == '-')
            {
                flag = true;
                continue;
            }

            if (str[i] - '0' > 9 or str[i] - '0' < 0)
                return -1;
            ans = (ans * 10) + (str[i] - '0');
        }
        if (flag)
            return 0 - ans;
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
// } Driver Code Ends