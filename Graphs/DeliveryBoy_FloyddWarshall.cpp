// Chef has started Home Delivery scheme in one of his restaurants. As the scheme is new ,
// Chef appoints only one employee to deliver food to various locations.
// The delivery boy who has been appointed is an absent-minded chap.
// He always forgets to fill fuel in his delivery scooter. So what he does is that whenever Chef sends him for delivery,
// he goes to the gas station from the restaurant first. He gets his tank filled and then he heads towards his destination.
// He will do this every single time irrespective of the destination. The delivery boy tries his best to be on time.
// And to do this, he will choose those paths(from restaurant to gas station AND gas station to destinaion)
// which cost him the least amount of time. Your task is to tell the Chef how much time can the delivery boy save
// if he had enough fuel in his scooter i.e. if he went to the destination directly without stopping for fuel (taking the path which
// costs him least amount of time).

// The city has N streets numbered from 0 to N-1.
// The restaurant is on street number S, the gas station is on street number G and the food has to be delivered to street D .
// Note that S, G and D need not be distinct.

// Input:
// First line of the input contains a single integer N.
// Then follows an NxN matrix T which is represented in N lines with N space separated integers on each line.
// T[i][j] denotes the time taken to move from the ith street to jth street. Obviously, T[i][i] = 0.
// Next line contains a single integer M, the number of scenarios.
// The following M lines contain 3 space separated integers S, G and D.
// Output:
// For each of the M scenarios, output the time taken by the delivery boy to deliver the food and the time he could have saved if he went directly from S to D.
// Both these values must be on the same line separated by a single space.

// Constraints:

// 1 ≤ N ≤ 250
// 1 ≤ M ≤ 10000
// 0 ≤ T[i][j] ≤ 100000
// 0 ≤ S,G,D ≤ N-1

// Example:
// Input:
// 4
// 0 2 1 3
// 1 0 4 5
// 3 1 0 3
// 1 1 1 0
// 4
// 0 2 1
// 0 2 2
// 3 1 2
// 3 0 1

// Output:
// 2 0
// 1 0
// 3 2
// 3 2

// https://www.codechef.com/submit/HOMDEL?showProblemStatement=1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int n, m;
    // taking input
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cin >> m;
    // taking input
    vector<vector<int>> qu(m, vector<int>(3, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> qu[i][0] >> qu[i][1] >> qu[i][2];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[i][j] = matrix[i][j];
    }
    // Floydd-Warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    for (auto path : qu)
    {
        cout << dp[path[0]][path[1]] + dp[path[1]][path[2]] << " " << dp[path[0]][path[1]] + dp[path[1]][path[2]] - dp[path[0]][path[2]] << endl;
    }

    return 0;
}
