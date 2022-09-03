#include<bits/stdc++.h>
// #define INT_MAX inf;
using namespace std;

// for minimum 
class SGTree{
public:
	vector<int> sgt,lazy;

	SGTree(int n){
		sgt.resize(4*n);
		lazy.resize(4*n,INT_MAX);
	}

	void build(int idx,int low,int high,vector<int>& nums){
		if(low == high) {
			sgt[idx] = nums[low];
			return;
		}

		int mid = (low+high) >> 1;
		build(2*idx+1,low,mid,nums);
		build(2*idx+2,mid+1,high,nums);
		sgt[idx] = min(sgt[2*idx+1],sgt[2*idx+2]);

		return;
	}

	void update(int idx,int low,int high,int l,int r,int val){
		//when first visiting any cell if any previous updates left then
		//lazily update them

		if(lazy[idx] != INT_MAX){
			sgt[idx] += lazy[idx];

			if(low != high) {
				lazy[2*idx+1] += lazy[idx];
				lazy[2*idx+2] += lazy[idx];
			} 

			lazy[idx] = 0;
		}

		// no overlap
		// l r low high or low high l r
		if(r < low or high < l) return;

		//complete overlap
		// l low high r
		if(low >= l and high <= r){
			sgt[idx] = min(sgt[idx],val);

			if(low != high) {
				lazy[2*idx+1] += val;
				lazy[2*idx+2] += val;
			}
			return; 
		}

		//partial overlap
		int mid = (low+high) >> 1;
		update(2*idx+1,low,mid,l,r,val);
		update(2*idx+2,mid+1,high,l,r,val);
		sgt[idx] = min(sgt[2*idx+1],sgt[2*idx+2]);
		return;
	}

	int query(int idx,int low,int high,int l,int r) {
		//when first visiting any cell if any previous updates left then
		//lazily update them

		if(lazy[idx] != 0){
			sgt[idx] += lazy[idx];

			if(low != high) {
				lazy[2*idx+1] += lazy[idx];
				lazy[2*idx+2] += lazy[idx];
			} 

			lazy[idx] = 0;
		}

		//no overlap
		// l r low high or low high l r
		if(r < low or high < l) return INT_MAX;

		//complete overlap
		// l low high r
		if(low >= l and high <= r) return sgt[idx];

		//partial overlap
		int mid = (low+high) >> 1;
		int left = query(2*idx+1,low,mid,l,r);
		int right = query(2*idx+2,mid+1,high,l,r);
		return min(left,right);
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	vector<int> nums(n);

	for(int i=0;i<n;i++) cin>>nums[i];

	SGTree sgtree = SGTree(n);
	sgtree.build(0,0,n-1,nums);

	cout<<sgtree.query(0,0,n-1,1,4);
}