// The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part
// and putting it at the beginning.

// The algorithm maintains two subarrays in a given array.
// 1) The subarray which is already sorted. -> part from index = 0 to index = i
// 2) Remaining subarray which is unsorted. -> part from index = j to index = n-1

// In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray
// is picked and moved to the sorted subarray.

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    int temp; // stores the index of minimum element in every iteration

    for (int i = 0; i < n - 2; i++)
    {
        temp = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[temp] > arr[j])
                temp = j;
        }
        swap(arr[i], arr[temp]);
    }
}

int main()
{
    int n = 5;
    int arr[5] = {2, 1, 1, 2, 1};

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Worst Case Complexity: O(n2)
// If we want to sort in ascending order and the array is in descending order then, the worst case occurs.

// Best Case Complexity: O(n2)
// It occurs when the array is already sorted

// Average Case Complexity: O(n2)
// It occurs when the elements of the array are in jumbled order (neither ascending nor descending).

// The time complexity of the selection sort is the same in all cases.
// At every step, you have to find the minimum element and put it in the right place.
// The minimum element is not known until the end of the array is not reached.

// Space Complexity:

// Space complexity is O(1) because an extra variable temp is used.
