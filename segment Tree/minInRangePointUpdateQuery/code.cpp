#include <bits/stdc++.h>
using namespace std;

void build(int idx, int low, int high, vector<int> &arr, vector<int> &segmentTree)
{
    if (low == high)
    {
        segmentTree[idx] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    // building left segemntTree
    build(2 * idx + 1, low, mid, arr, segmentTree);
    // building right SegmentTree
    build(2 * idx + 2, mid + 1, high, arr, segmentTree);

    segmentTree[idx] = min(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);

    return;
}

void pointUpdate(int idx, int low, int high, vector<int> &segmentTree, int idxToUpdate, int updatedValue)
{
    if (low == high){
        segmentTree[idx] = updatedValue;
        return;
    }

    int mid = (low + high) / 2;
    if (idxToUpdate <= mid)
        pointUpdate(2 * idx + 1, low, mid, segmentTree, idxToUpdate, updatedValue);
    else
        pointUpdate(2 * idx + 2, mid + 1, high, segmentTree, idxToUpdate, updatedValue);

    segmentTree[idx] = min(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);

    return;
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n = 7;
    vector<int> arr = {2, -1, 3, 7, 4, 10, 11};
    vector<int> segmentTree(4 * n + 1, 0);

    build(0, 0, n - 1, arr, segmentTree);

    for (int i : segmentTree)
        cout << i << " ";
    cout << endl;

    // point update query
    int idxToUpdate = 1;
    int updatedValue = 21;

    arr[idxToUpdate] = updatedValue;

    pointUpdate(0, 0, n - 1, segmentTree, idxToUpdate, updatedValue);

    for (int i : segmentTree)
        cout << i << " ";
}