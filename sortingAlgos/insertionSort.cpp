// Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
// The array is virtually split into a sorted and an unsorted part.
// Values from the unsorted part are picked and placed at the correct position in the sorted part.

// Algorithm
// To sort an array of size n in ascending order:
// 1: Iterate from arr[1] to arr[n] over the array.
// 2: Compare the current element (key) to its predecessor.
// 3: If the key element is smaller than its predecessor, compare it to the elements before.
// Move the greater elements one position up to make space for the swapped element.

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 1; i < n - 1; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return;
}

int main()
{
    int n = 7;
    int arr[n] = {27, 42, 1, 6, 9, 12, 23};

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// What is Binary Insertion Sort?
// We can use binary search to reduce the number of comparisons in normal insertion sort.
// Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration.
// In normal insertion, sorting takes O(i) (at ith iteration) in worst case. We can reduce it to O(logi) by using binary search.
// The algorithm, as a whole, still has a running worst case running time of O(n^2) because of the series of swaps required for each insertion.

// Time Complexities

// Worst Case Complexity: O(n2)
// Suppose, an array is in ascending order, and you want to sort it in descending order. In this case, worst case complexity occurs.

// Each element has to be compared with each of the other elements so, for every nth element, (n-1) number of comparisons are made.

// Thus, the total number of comparisons = n*(n-1) ~ n2

// Best Case Complexity: O(n)
// When the array is already sorted, the outer loop runs for n number of times whereas the inner loop does not run at all.
// So, there are only n number of comparisons. Thus, complexity is linear.

// Average Case Complexity: O(n2)
// It occurs when the elements of an array are in jumbled order (neither ascending nor descending).

// Space Complexity
// Space complexity is O(1) because an extra variable key is used.