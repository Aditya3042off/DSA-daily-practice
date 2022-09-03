#include <bits/stdc++.h>
using namespace std;

struct node
{
	int open, closed, full;

	node()
	{
		open = 0;
		closed = 0;
		full = 0;
	}

	node(int _open, int _closed, int _full)
	{
		open = _open;
		closed = _closed;
		full = _full;
	}
};

class SGTree
{
public:
	vector<node> segmentTree;

	SGTree(int n)
	{
		segmentTree.resize(4 * n);
	}

	node mergeNodes(node leftNode, node rightNode)
	{
		int newFormedFull = min(leftNode.open, rightNode.closed);
		int full = leftNode.full + rightNode.full + newFormedFull;
		int open = leftNode.open - newFormedFull + rightNode.open;
		int closed = rightNode.closed - newFormedFull + leftNode.closed;

		return node(open, closed, full);
	}

	void build(int idx, int low, int high, string &str)
	{
		if (low == high)
		{
			segmentTree[idx] = node(str[low] == '(', str[low] == ')', 0);
			return;
		}

		int mid = (low + high) / 2;

		build(2 * idx + 1, low, mid, str);
		build(2 * idx + 2, mid + 1, high, str);

		segmentTree[idx] = mergeNodes(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);

		return;
	}

	node query(int idx, int low, int high, int l, int r)
	{
		if (l <= low and high <= r)
			return segmentTree[idx];

		if (r < low || high < l)
			return node(0, 0, 0);

		int mid = (low + high) / 2;
		node leftNode = query(2 * idx + 1, low, mid, l, r);
		node rightNode = query(2 * idx + 2, mid + 1, high, l, r);

		return mergeNodes(leftNode, rightNode);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;

	int size = str.size();

	int n;
	cin >> n;

	vector<pair<int, int>> queries(n, {0, 0});

	for (int i = 0; i < n; i++)
		cin >> queries[i].first >> queries[i].second;

	SGTree segmentTree = SGTree(size);
	segmentTree.build(0, 0, size - 1, str);

	node temp = node(0, 0, 0);
	for (auto query : queries)
	{
		temp = segmentTree.query(0, 0, size - 1, (query.first) - 1, (query.second) - 1);
		cout << temp.full * 2 << endl;
	}
}