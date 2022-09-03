//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    pair<int, int> utility(vector<vector<int>> &matrix)
    {
        int maxi = INT_MIN, mini = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, matrix[i][m - 1]);
            mini = min(mini, matrix[i][0]);
        }
        return {maxi, mini};
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        pair<int, int> temp = utility(matrix);
        int high = temp.first, low = temp.second;

        int highcount = 0, lowcount = 0;

        while (low < high)
        {
            highcount = lowcount = 0;
            int mid = (low + high) >> 1;

            for (int i = 0; i < n; i++)
            {
                int upboundIdx = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

                lowcount += upboundIdx;
                highcount += m - upboundIdx;
            }
            if (highcount + 1 == lowcount)
                return mid;
            else if (highcount < lowcount)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}
// } Driver Code Ends