#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
vector<int> graph[N+1];

int subtreeSize[N];
long long int subtreeAns[N];
long long int ans[N];

void preprocessing(int src,int parent) {
	int numberOfNodes = 1;
	long long int distanceToAllNodes = 0;

	for(auto child : graph[src]) {
		if(child == parent) continue;
		preprocessing(child,src);
		numberOfNodes += subtreeSize[child];
		distanceToAllNodes += subtreeAns[child] + subtreeSize[child];
	}

	subtreeSize[src] = numberOfNodes;
	subtreeAns[src] = distanceToAllNodes;
}

void computeAns(int src,int parent,long long int parentPartialAns, int& totalNodes) {
	ans[src] = subtreeAns[src] + parentPartialAns + totalNodes - subtreeSize[src];

	for(auto child : graph[src]) {
		if(child == parent) continue;

		computeAns(child,src,ans[src]-subtreeAns[child]-subtreeSize[child],totalNodes);
	}
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	int u,v;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	preprocessing(1,0);

	computeAns(1,0,0,n);

	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}