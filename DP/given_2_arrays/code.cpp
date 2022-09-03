#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	int one_count = 0;
	cin>>n;

	int *a = new int[n];
	int *b = new int[n];

	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		cin>>b[i];
		if(b[i] == 1) one_count++;
	}

	priority_queue<int,vector<int>,greater<int>> pq(a,a+n);

	while(one_count--){
		int temp = pq.top();
		pq.pop();
		temp++;
		pq.push(temp);
	}

	int ans = 1;

	while(pq.empty() == false){
		ans = (ans * pq.top())%mod;
		pq.pop();
	}

	for(int i=0;i<n;i++) ans = (ans*b[i])%mod;

	cout<<ans;

}