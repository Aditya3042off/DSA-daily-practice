#include <bits/stdc++.h>
using namespace std;

void conquer(int arr[], int start, int mid, int end)
{
    int size = end - start + 1;

    int temp[size];

    int idx1 = start, idx2 = mid + 1, idx3 = 0;

    while (idx1 <= mid and idx2 <= end)
    {
        if (arr[idx1] <= arr[idx2])
            temp[idx3++] = arr[idx1++];
        else
            temp[idx3++] = arr[idx2++];
    }

    while (idx1 <= mid)
        temp[idx3++] = arr[idx1++];
    while (idx2 <= end)
        temp[idx3++] = arr[idx2++];

    for (int i = 0, j = start; i < size; i++, j++)
        arr[j] = temp[i];
}

void divide(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;

    divide(arr, start, mid);
    divide(arr, mid + 1, end);

    conquer(arr, start, mid, end);
}

int main()
{
    int n = 7;

    // cin >> n;

    int arr[n] = {3, 1, 9, 4, 0, -9, 5};

    // for (int i = 0; i < n; i++)
    // cin >> arr[i];

    divide(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}