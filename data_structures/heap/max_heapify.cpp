#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &heap, int idx)
{
    int largest;
    int l = (2 * idx) + 1;
    int r = (2 * idx) + 2;

    if (l <= heap.size() and heap[l] > heap[idx])
        largest = l;
    else
        largest = idx;

    if (r <= heap.size() and heap[r] > heap[largest])
        largest = r;

    if (largest != idx)
    {
        swap(heap[idx], heap[largest]);
        max_heapify(heap, largest);
    }
    return;
}

int main()
{
    vector<int> heap = {1, 14, 10, 8, 7, 9, 3, 2, 4, 6};
    int idx = 0;
    max_heapify(heap, idx);

    for (int i : heap)
        cout << i << " ";
}