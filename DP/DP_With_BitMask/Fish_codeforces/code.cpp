#include<bits/stdc++.h>
using namespace std;

float solve(vector<vector<float>>& probMatrix,vector<vector<float>>& dp,int currFish,int remFishMask){
	int n = probMatrix.size();
	if(remFishMask == 0)
		return 1;

	if(dp[currFish][remFishMask] != -1)
		return dp[currFish][remFishMask];

	float totalProb = 0;
	float numPlayed = 0;
	for(int i=0;i<n;i++){
		if(remFishMask & (1<<i) == 0) continue;
		numPlayed++;
		if(probMatrix[currFish][i] < probMatrix[i][currFish]) continue;
		totalProb += solve(probMatrix,dp,currFish,remFishMask & ~(1<<i));
	}

	return dp[currFish][remFishMask] = totalProb / numPlayed;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n; // no of fishes
	cin>>n;

	float temp;

	vector<vector<float>> probMatrix(n,vector<float>(n,-1));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>temp;
			probMatrix[i][j] = temp;
		}
	}

	vector<vector<float>> dp(n,vector<float>((1<<n)-1,-1));
	vector<float> probWin(n,0);

	for(int i=0;i<n;i++){
		probWin[i] = solve(probMatrix,dp,i,((1<<n)-1 & ~(1<<i)));
	}

	for(int i = 0;i<n;i++)
		cout<<probWin[i]<<" ";

}