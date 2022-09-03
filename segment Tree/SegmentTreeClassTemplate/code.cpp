#include <bits/stdc++.h>
using namespace std;

class SGTree
{

	vector<int> segmentTree;

	void build(int idx, int low, int high, vector<int> arr)
	{
		if (low == high)
		{
			segmentTree[idx] = arr[low];
			return;
		}

		int mid = (low + high) / 2;

		build(2 * idx + 1, low, mid, arr);
		build(2 * idx + 2, mid + 1, high, arr);

		segmentTree[idx] = min(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);

		return;
	}

	void pointUpdate(int idx, int low, int high, vector<int> arr, int idxToUpdate, int updatedValue)
	{
		if (low == high)
		{
			segmentTree[idx] = updatedValue;
			return;
		}

		int mid = (low + high) / 2;

		if (idxToUpdate <= mid)
			pointUpdate(2 * idx + 1, low, mid, arr, idxToUpdate, updatedValue);
		else
			pointUpdate(2 * idx + 2, mid + 1, high, arr, idxToUpdate, updatedValue);

		segmentTree[idx] = min(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);

		return;
	}

	int query(int idx, int low, int high, vector<int> arr, int l, int r)
	{
		if (l <= low and high <= r)
			return segmentTree[idx];

		if (r < low || high < l)
			return INT_MAX;

		int mid = (low + high) / 2;
		int leftMin = query(2 * idx + 1, low, mid, arr, l, r);
		int rightMin = query(2 * idx + 2, mid + 1, high, arr, l, r);

		return min(leftMin, rightMin);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;

	vector<int> arr;
}