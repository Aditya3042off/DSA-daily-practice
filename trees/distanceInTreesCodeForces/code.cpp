#include <bits/stdc++.h>
using namespace std;

const int N = 50001;
const int K = 501;

vector<int> graph[N];
long long int dp[N][K];
long long int ans[N][K];

void preprocessing(int src, int parent, int k)
{
	dp[src][0] = 1;

	for (auto child : graph[src])
	{
		if (child == parent)
			continue;
		preprocessing(child, src, k);
		for (int i = 1; i <= k; i++)
			dp[src][i] += dp[child][i - 1];
	}
}

void solve(int src, int par, int &k)
{
	for (int dis = 0; dis <= k; dis++)
		ans[src][dis] = dp[src][dis];

	if (par != 0)
	{
		ans[src][1] += ans[par][0];
		for (int dis = 2; dis <= k; dis++)
		{
			ans[src][dis] += ans[par][dis - 1];
			ans[src][dis] -= dp[src][dis - 2];
		}
	}

	for (int child : graph[src])
		if (child != par)
			solve(child, src, k);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(dp, 0, sizeof(dp));

	preprocessing(1, 0, k);
	solve(1, 0, k);

	long long int count = 0;
	for (int i = 1; i <= n; i++)
		count += ans[i][k];

	cout << count / 2;
}