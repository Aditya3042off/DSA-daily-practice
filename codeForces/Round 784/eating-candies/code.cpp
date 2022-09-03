#include <bits/stdc++.h>
using namespace std;

int findMaxCandles(int n, int arr[])
{
	unordered_map<int,int> mp;
	int psum = 0;

	for(int i=0;i<n;i++){
		psum += arr[i];
		mp[psum] = i;
	}

	int maxNoOfCandles = 0;

	psum = 0;
	for(int i=n-1;i>=0;i--){
		psum += arr[i];
		if(mp.find(psum) != mp.end()){
			if(mp[psum] < i){
				maxNoOfCandles = max(maxNoOfCandles,mp[psum] + 1 + n - i);
			}
			else break;
		}
	}
	return maxNoOfCandles;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int testcases, n, temp;

	cin >> testcases;

	while (testcases--)
	{
		cin >> n;
		int arr[n];

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			arr[i] = temp;
		}

		cout << findMaxCandles(n, arr) << endl;
	}
}