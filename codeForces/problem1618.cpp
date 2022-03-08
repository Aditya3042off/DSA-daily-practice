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
    int ptr1, ptr2;

    for (int i = 0; i < N; i++)
    {
        sort(arr[i].begin(), arr[i].end());

        ptr1 = arr[i].size() - 2 * operations[i];
        ptr2 = arr[i].size() - operations[i];

        while (ptr1 < ptr2)
        {
            score += floor(arr[i][ptr1] / arr[i][ptr2]);
            ptr1++;
            ptr2--;
        }
        for (int j = 0; j < arr[i].size() - 2 * operations[i]; j++)
            score += arr[i][j];
        cout << score << endl;
        score = 0;
    }
}