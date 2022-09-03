#include<bits/stdc++.h>
using namespace std;

bool findIsPossible(int arr[],int n){
	for(int i=0;i<n-1;i++){
		if(arr[i+1]-arr[i] == 1) continue;

		if(arr[i] == arr[i+1])
			arr[i+1]++;
		else if(arr[i+1]-arr[i] == 2 || arr[i+1]-arr[i] == 3)
			arr[i+1]--;
		else return false;
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int testcases;
	cin>>testcases;

	int n,temp;

	for(int i=0;i<testcases;i++ ){
		cin>>n;
		int arr[n];

		for(int i=0;i<n;i++){
			cin>>temp;
			arr[i] = temp;
		}

		if(findIsPossible(arr,n))
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}