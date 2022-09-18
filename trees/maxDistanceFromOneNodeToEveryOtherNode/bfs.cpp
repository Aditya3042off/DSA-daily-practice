// https://www.youtube.com/watch?v=N7e4CTfimkU&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=4

#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
vector<int> graph[N + 1];

long long int ans[N];

struct Node
{
	int node;
	int parent;
	long long int dist;

	Node(int _node, int _parent, long long int _dist)
	{
		node = _node;
		parent = _parent;
		dist = _dist;
	}
};

pair<int, int> find2FarthestNodes()
{
	auto comp = [](const Node &p1, const Node &p2)
	{ return p1.dist > p2.dist; };
	set<Node, decltype(comp)> s(comp);

	queue<Node> q;
	q.push(Node(1, 0, 0));

	while (!q.empty())
	{
		int node = q.front().node;
		long long int dist = q.front().dist;
		int parent = q.front().parent;
		q.pop();
		if(graph[node].size() == 1)
			s.insert(Node(node, parent, dist));

		for (auto child : graph[node])
		{
			if (child == parent)
				continue;
			q.push(Node(child, node, dist + 1));
		}
	}

	int farthest = (s.begin())->node;
	s.erase(s.begin());
	int secondFarthest = (s.begin())->node;

	return {farthest, secondFarthest};
}

void findAnswer(int src)
{
	queue<Node> q;
	q.push(Node(src, 0, 0));

	while (!q.empty())
	{
		int node = q.front().node;
		long long int dist = q.front().dist;
		int parent = q.front().parent;
		q.pop();
		ans[node] = max(ans[node], dist);

		for (auto child : graph[node])
		{
			if (child == parent)
				continue;
			q.push(Node(child, node, dist + 1));
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	pair<int, int> temp = find2FarthestNodes();
	int farthest = temp.first;
	int secondFarthest = temp.second;

	cout<<farthest<<" "<<secondFarthest<<endl;

	findAnswer(farthest);
	findAnswer(secondFarthest);

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
}