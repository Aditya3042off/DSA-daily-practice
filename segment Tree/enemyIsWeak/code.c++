#include <bits/stdc++.h>
using namespace std;

class SGTree
{
public:
	vector<long long> sgt;

	SGTree(long long n)
	{
		sgt.resize(4 * n);
	}

	void build(long long idx, long long low, long long high, vector<long long> nums)
	{
		if (low == high)
		{
			sgt[idx] = nums[low];
			// cout << idx << "->" << sgt[idx] << endl;
			return;
		}
		long long mid = (low + high) >> 1;
		build(2 * idx + 1, low, mid, nums);
		build(2 * idx + 2, mid + 1, high, nums);

		sgt[idx] = sgt[(2 * idx) + 1] + sgt[(2 * idx) + 2];
		// cout << idx << "->" << sgt[idx] << endl;
		return;
	}

	long long query(long long idx, long long low, long long high, long long l, long long r)
	{
		// no overlap
		// low high l r or  l r low high
		if (r < low or high < l)
			return 0;

		// complete
		//  l low high r
		if (low >= l and high <= r)
			return sgt[idx];

		// partial
		long long mid = (low + high) >> 1;
		return query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r);
	}

	void pointUpdate(long long idx, long long low, long long high, long long updatedIdx, long long updatedVal)
	{
		if (low == high)
		{
			sgt[idx] = updatedVal;
			return;
		}

		long long mid = (low + high) >> 1;

		if (updatedIdx <= mid)
			pointUpdate(2 * idx + 1, low, mid, updatedIdx, updatedVal);
		else
			pointUpdate(2 * idx + 2, mid + 1, high, updatedIdx, updatedVal);

		sgt[idx] = sgt[2 * idx + 1] + sgt[2 * idx + 2];

		return;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long n;
	cin >> n;

	vector<long long> nums(n);
	for (long long i = 0; i < n; i++)
		cin >> nums[i];

	long long maxi = *max_element(nums.begin(), nums.end());
	long long mini = *min_element(nums.begin(), nums.end());

	vector<long long> freq1(maxi + 1, 0);

	for (long long i = 0; i < n; i++)
		freq1[nums[i]]++;

	vector<long long> freq2;
	for (long long i : freq1)
		freq2.push_back(i);

	vector<long long> ans(n, 0);

	SGTree sgtree1 = SGTree(maxi + 1);
	SGTree sgtree2 = SGTree(maxi + 1);

	sgtree1.build(0, 0, maxi, freq1);
	sgtree2.build(0, 0, maxi, freq2);

	for (long long i = 1; i < n - 1; i++)
	{
		sgtree1.pointUpdate(0, 0, maxi, nums[i - 1], --freq1[nums[i - 1]]);
		if (mini == nums[i])
			ans[i] = 0;
		else
			ans[i] = sgtree1.query(0, 0, maxi, mini, nums[i] - 1);
	}

	for (long long i = n - 2; i >= 1; i--)
	{
		sgtree2.pointUpdate(0, 0, maxi, nums[i + 1], freq2[nums[i + 1]] - 1);
		if (maxi == nums[i])
			ans[i] = 0;
		else
			ans[i] = ans[i] * sgtree2.query(0, 0, maxi, nums[i] + 1, maxi);
	}

	cout << accumulate(ans.begin(), ans.end(), 0);
}