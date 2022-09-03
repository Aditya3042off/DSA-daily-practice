#include <bits/stdc++.h>
using namespace std;

bool findSol(int arr[], int n)
{
	int oddIdxRemainder = arr[1] % 2;
	int evenIdxRemainder = arr[0] % 2;

	for (int i = 2; i < n; i++)
	{
		if (i % 2 == 0)
		{
			if ((arr[i] % 2) != evenIdxRemainder)
			{
				return false;
			}
		}
		else
		{
			if ((arr[i] % 2) != oddIdxRemainder)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int testcases;
	cin>>testcases;

	int n;
	int temp;

	while(testcases--){
		cin>>n;
		int arr[n];

		for(int i=0;i<n;i++){
			cin>>temp;
			arr[i] = temp;
		}

		if(findSol(arr,n) == true)
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
	
}