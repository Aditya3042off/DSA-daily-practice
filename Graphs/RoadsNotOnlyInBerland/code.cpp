#include<bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] > size[pv])
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

    void unionRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

		int n; //no of cities
		cin>>n;
		int x,y;

		vector<pair<int,int>> roads;

		for(int i=1;i<=n-1;i++){
			cin>>x>>y;
			roads.push_back({x,y});
		}

		vector<pair<int,int>> duplicateRoads;
		set<int> ultimateParents;

		// cities are labelled from 1 to n 
		DSU dsu = DSU(n+1);

		for(int i=0;i<roads.size();i++){
			if(dsu.findParent(roads[i].first) == dsu.findParent(roads[i].second)){
				duplicateRoads.push_back(roads[i]);
				continue;
			}

			dsu.unionSize(roads[i].first,roads[i].second);
		}

		// so now using this we get ultimate parents of all the components in set
		for(int i=1;i<=n;i++){
			ultimateParents.insert({dsu.findParent(i)});
		}

		int numOfComponents = ultimateParents.size();
		// so if there are k diff components we need k-1 roads to connect them
		// so we remove k-1 duplicate roads and attach these components

		vector<int> ans;

		for(int i=0;i<numOfComponents-1;i++){
			ans.push_back(duplicateRoads[i].first);
			ans.push_back(duplicateRoads[i].second);

			ans.push_back(*(ultimateParents.begin()));
			ultimateParents.erase(ultimateParents.begin());
			ans.push_back(*(ultimateParents.begin()));
		}

		cout<<numOfComponents-1<<endl;
		for(int i : ans){
			cout<<i<<" ";
		}
}