// https://www.geeksforgeeks.org/minimum-product-subset-array/

#include <bits/stdc++.h>
using namespace std;

long long solve(int *arr, int n)
{
    long long product = 1;
    int negMax = 1;
    int posMin = 0;
    int negCount = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] != 0)
            product *= arr[i];

        if (arr[i] >= 0)
            posMin = min(posMin, arr[i]);
        else if (arr[i] < 0)
        {
            negCount++;
            if (abs(negMax) > abs(arr[i]))
                negMax = arr[i];
        }
    }

    if (negCount == 0)
    {
        return posMin;
    }

    if (negCount & 1)
        return product;
    return product / negMax;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // 	freopen("input.txt","r",stdin);
    // 	freopen("output.txt","w",stdout);
    // #endif

    int arr[] = {0, 0, 0, 0};
    int n = sizeof(arr) / sizeof(int);

    cout << solve(arr, n);
}