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

	segmentTree[idx] = max(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);

	return;
}

int query(int idx, int low, int high, vector<int> &arr, vector<int> &segmentTree, int l, int r)
{
	if (l <= low and r >= high)
		return segmentTree[idx];

	if (high < l || low > r)
		return INT_MIN;

	int mid = (low + high) / 2;
	int leftMax = query((2 * idx + 1), low, mid, arr, segmentTree, l, r);
	int rightMax = query((2 * idx + 2), mid + 1, high, arr, segmentTree, l, r);

	return max(leftMax, rightMax);
}

int main()
{
	int n = 5, temp, l = 1, r = 3;
	// cin >> n;

	vector<int> arr = {9, 20, 7, 35, 22};

	// for (int i = 0; i < n; i++)
	// {
	// 	cin >> temp;
	// 	arr[i] = temp;
	// }

	// query
	// cin >> l >> r;

	vector<int> segmentTree(4 * n, 0);

	build(0, 0, n - 1, arr, segmentTree);

	// for (int i : segmentTree)
	// cout << i << " ";

	cout << query(0, 0, n - 1, arr, segmentTree, l, r);
}