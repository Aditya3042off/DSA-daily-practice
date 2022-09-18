/* Given N activities with their start and finish day given in array start[ ] and end[ ]. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.


Example 1:

Input:
N = 2
start[] = {2, 1}
end[] = {2, 2}
Output:
1
Explanation:
A person can perform only one of the
given activities.
Example 2:

Input:
N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output:
3
Explanation:
A person can perform activities 1, 2
and 4. */

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Node
{
    int start;
    int end;
    Node(int _start, int _end)
    {
        start = _start;
        end = _end;
    }
};

class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<Node> activities;
        for (int i = 0; i < n; i++)
            activities.push_back(Node(start[i], end[i]));

        auto comp = [](Node &a1, Node &a2)
        {
            return a1.end < a2.end;
        };

        sort(activities.begin(), activities.end(), comp);
        int ans = 0;
        int prevCompletionTime = -1;

        for (auto job : activities)
        {
            if (job.start > prevCompletionTime)
            {
                ans++;
                prevCompletionTime = job.end;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;

    // testcases
    cin >> t;
    while (t--)
    {
        // size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        // adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        // function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends