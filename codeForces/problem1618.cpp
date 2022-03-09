#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr[N];
    vector<int> operations;
    int a, k, temp;

    for (int i = 0; i < N; i++)
    {
        cin >> a >> k;
        operations.push_back(k);

        for (int j = 0; j < a; j++)
        {
            cin >> temp;
            arr[i].push_back(temp);
        }
    }

    int score = 0;

    for (int i = 0; i < N; i++)
    {
        k = operations[i];

        sort(arr[i].begin(), arr[i].end(), greater<int>());

        for (int j = 0; j < k; j++)
            score += floor(arr[i][k + j] / arr[i][j]);

        for (int j = 0; j < arr[i].size() - 2 * k; j++)
            score += arr[i][j];
        cout << score << endl;
        score = 0;
    }
}