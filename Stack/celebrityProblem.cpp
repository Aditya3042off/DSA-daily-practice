// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// https://www.youtube.com/watch?v=CiiXBvrX-5A
// A celebrity is a person who is known to all but does not know anyone at a party.
// If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that
// if an element of row i and column j  is set to 1 it means ith person knows jth person.
// Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.

// Example 1:

// Input:
// N = 3
// M[][] = {{0 1 0},
//          {0 0 0},
//          {0 1 0}}
// Output: 1
// Explanation: 0th and 2nd person both
// know 1. Therefore, 1 is the celebrity.

// Example 2:

// Input:
// N = 2
// M[][] = {{0 1},
//          {1 0}}
// Output: -1
// Explanation: The two people at the party both
// know each other. None of them is a celebrity.

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool know(vector<vector<int>> &M, int a, int b)
    {
        return M[a][b] == 1;
    }

    bool checkCelebrity(vector<vector<int>> &M, int candidate, int n)
    {
        int rowCount = 0;
        for (int i = 0; i < n; i++)
            if (M[candidate][i] == 0)
                rowCount++;
        if (rowCount != n)
            return false;

        int colCount = 0;
        for (int i = 0; i < n; i++)
            if (M[i][candidate] == 1)
                colCount++;
        if (colCount != n - 1)
            return false;

        return true;
    }

    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        stack<int> st;
        for (int i = 0; i < n; i++)
            st.push(i);

        while (st.size() > 1)
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            if (know(M, a, b))
                st.push(b);
            else
                st.push(a);
        }

        int lastCandidate = st.top();

        if (!checkCelebrity(M, lastCandidate, n))
            return -1;
        return lastCandidate;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends