// https://codeforces.com/contest/339/problem/D
// https://www.youtube.com/watch?v=NEG-SoyigGE&t=5799s

// Xenia the beginner programmer has a sequence a, consisting of 2n non-negative integers: a1, a2, ..., a2n. Xenia is currently studying bit operations. To better understand how they work, Xenia decided to calculate some value v for a.

// Namely, it takes several iterations to calculate value v. At the first iteration, Xenia writes a new sequence a1 or a2, a3 or a4, ..., a2n - 1 or a2n, consisting of 2n - 1 elements. In other words, she writes down the bit-wise OR of adjacent elements of sequence a. At the second iteration, Xenia writes the bitwise exclusive OR of adjacent elements of the sequence obtained after the first iteration. At the third iteration Xenia writes the bitwise OR of the adjacent elements of the sequence obtained after the second iteration. And so on; the operations of bitwise exclusive OR and bitwise OR alternate. In the end, she obtains a sequence consisting of one element, and that element is v.

// Let's consider an example. Suppose that sequence a = (1, 2, 3, 4). Then let's write down all the transformations (1, 2, 3, 4)  →  (1 or 2 = 3, 3 or 4 = 7)  →  (3 xor 7 = 4). The result is v = 4.

// You are given Xenia's initial sequence. But to calculate value v for a given sequence would be too easy, so you are given additional m queries. Each query is a pair of integers p, b. Query p, b means that you need to perform the assignment ap = b. After each query, you need to print the new value v for the new sequence a.

// Input
// The first line contains two integers n and m (1 ≤ n ≤ 17, 1 ≤ m ≤ 105). The next line contains 2n integers a1, a2, ..., a2n (0 ≤ ai < 230). Each of the next m lines contains queries. The i-th line contains integers pi, bi (1 ≤ pi ≤ 2n, 0 ≤ bi < 230) — the i-th query.

// Output
// Print m integers — the i-th integer denotes value v for sequence a after the i-th query.

// Examples
// input
// 2 4
// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2
// output
// 1
// 3
// 3
// 3

#include<bits/stdc++.h>
using namespace std;

class SGTree{

public:
	vector<int> segmentTree;

	SGTree(int n){
		segmentTree.assign(4*n,0);
	}

	void build(int idx,int low,int high,vector<int>& arr,bool isOR){
		if(low == high){
			segmentTree[idx] = arr[low];
			return;
		}

		int mid = (low + high) / 2;

		build(2*idx + 1,low,mid,arr,!isOR);
		build(2*idx + 2,mid+1,high,arr,!isOR);

		if(!isOR)
			segmentTree[idx] = segmentTree[2*idx + 1] ^ segmentTree[2*idx + 2];
		else 
			segmentTree[idx] = segmentTree[2*idx + 1] | segmentTree[2*idx + 2];

		return;
	}

	void pointUpdate(int idx,int low,int high,vector<int>& arr,int idxToUpdate,int updatedValue,bool isOR){
		if(low == high){
			segmentTree[idx] = updatedValue;
			return;
		}

		int mid = (low + high) / 2;

		if(idxToUpdate <= mid)
			pointUpdate(2*idx + 1,low,mid,arr,idxToUpdate,updatedValue,!isOR);
		else 
			pointUpdate(2*idx + 2,mid + 1,high,arr,idxToUpdate,updatedValue,!isOR);

		if(!isOR)
			segmentTree[idx] = segmentTree[2*idx + 1] ^ segmentTree[2*idx + 2];
		else 
			segmentTree[idx] = segmentTree[2*idx + 1] | segmentTree[2*idx + 2];

		return;
	}

	int returnAns(){
		return segmentTree[0];
	}
};

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	int size = pow(2,n);
	vector<int> arr(size,0);

	for(int i=0;i<size;i++) cin>>arr[i];

	vector<pair<int,int>> queries(m,{0,0});
	
	for(int i=0;i<m;i++) cin>>queries[i].first>>queries[i].second;

	SGTree segmentTree = SGTree(size);

	if(n % 2 != 0)
		segmentTree.build(0,0,size-1,arr,true);
	else 
		segmentTree.build(0,0,size-1,arr,false);

	for(auto query: queries){

		if(n % 2 != 0)
			segmentTree.pointUpdate(0,0,size-1,arr,(query.first)-1,query.second,true);
		else
			segmentTree.pointUpdate(0,0,size-1,arr,(query.first)-1,query.second,false);
		cout<<segmentTree.returnAns()<<endl;
	}

	
}