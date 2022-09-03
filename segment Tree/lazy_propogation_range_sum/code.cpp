#include<bits/stdc++.h>
using namespace std;

class SGTree {
public:
	vector<int> sgt,lazy;

	SGTree(int n){
		sgt.resize(4*n);
		lazy.resize(4*n,0);
	}

	void build(int idx,int low,int high,vector<int> nums){
		if(low == high){
			sgt[idx] = nums[low];
			return;
		}

		int mid = (low + high) >> 1;
		build(2*idx+1,low,mid,nums);
		build(2*idx+2,mid+1,high,nums);

		sgt[idx] = sgt[2*idx+1] + sgt[2*idx+2];
		return;
	}

	void update(int idx,int low,int high,int l,int r,int val){
		//every time when visiting a cell lazily update previously left
		//updates

		if(lazy[idx] != 0){
			sgt[idx] += (high - low + 1) * lazy[idx];

			if(low != high){
				lazy[2*idx+2] += lazy[idx];
				lazy[2*idx+1] += lazy[idx];	
			}

			lazy[idx] = 0;	
		}

		//no overlap
		// l r low high or low high l r
		if(r < low or high < l) return;

		// completely overlap
		if( low >= l and high <= r){
			//lazily update
			sgt[idx] += (high-low+1) * val;
			
			if(low != high){
				lazy[2*idx+1] += val;
				lazy[2*idx+2] += val;
			}
			
			return;
		}

		//partial overlap
		int mid = (low+high) >> 1;
		update(2*idx+1,low,mid,l,r,val);
		update(2*idx+2,mid+1,high,l,r,val);
		sgt[idx] = sgt[2*idx+1] + sgt[2*idx+2];

		return; 
	}

	int query(int idx,int low,int high,int l,int r){
		//every time when visiting a cell lazily update previously left
		//updates

		if(lazy[idx] != 0){
			sgt[idx] += (high - low + 1) * lazy[idx];

			if(low != high) {
				lazy[2*idx+1] += lazy[idx];
				lazy[2*idx+2] += lazy[idx];
			}

			lazy[idx] = 0;	
		}

		// no overlap
		// l r low high or low high l r
		if(r < low or high < l) return 0;

		//complete overlap
		// l low high r
		if(low >= l and high <= r) return sgt[idx];

		// partial overlap
		int mid = (low+high) >> 1;

		return query(2*idx+1,low,mid,l,r) +
			   query(2*idx+2,mid+1,high,l,r) ;
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>> n;

	vector<int> nums(n);

	for(int i=0;i<n;i++) cin>>nums[i];

	SGTree sgtree = SGTree(n);
	sgtree.build(0,0,n-1,nums);
	sgtree.update(0,0,n-1,1,6,1);
	
	cout<<sgtree.query(0,0,n-1,1,6);
}