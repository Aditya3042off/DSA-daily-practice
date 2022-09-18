// https://www.youtube.com/watch?v=N7e4CTfimkU&list=PLb3g_Z8nEv1j_BC-fmZWHFe6jmU_zv-8s&index=4

#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;
vector<int> graph(N+1);

int maxSubtreeDist[N];
int ans[N];

void preprocessing(int src,int parent) {
	int maxDist = 0;
	for(auto child : graph[src]){
		if(child == parent) continue;
		preprocessing(child,src);
		maxDist = max(maxDist,1 + maxSubtreeDist[child]);
	}
	maxSubtreeDist[src] = maxDist;
}

void computeAns(int src,int parent,int partialParentAns) {
	ans[src] = max(maxSubtreeDist[src],1 + partialParentAns);
	for(auto child : graph[src]){
		if(child == parent) continue;
		int partialSrcAns = 0;

		for(auto child : graph[src]){
			if(child)
		}
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


}