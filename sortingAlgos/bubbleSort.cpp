#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    bool swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
    return;
}

int main()
{
    int n = 8;
    int arr[n] = {44, 90, 23, 6, 1, 88, 4, 76};

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Time Complexities:

// Worst Case Complexity: O(n2)
// If we want to sort in ascending order and the array is in descending order then the worst case occurs.

// Best Case Complexity: O(n)
// If the array is already sorted, then there is no need for sorting.

// Average Case Complexity: O(n2)
// It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

// Space Complexity:
// Space complexity is O(1) because an extra variable is used for swapping.
// In the optimized bubble sort algorithm, two extra variables are used. Hence, the space complexity will be O(2)