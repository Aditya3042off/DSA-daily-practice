// https://codeforces.com/problemset/problem/1097/B
// https://www.youtube.com/watch?v=ZwU6wSkepBI&t=218s

#include<bits/stdc++.h>
using namespace std;

bool findIfCorrect(vector<int>& key,int n){

	bool flag = false;
	int sum = 0;

	for(int num=0;num < (1<<n)-1;num++){
		sum = 0;
		for(int bit = 0;bit<n;bit++){
			if(num & (1<<bit)) sum += key[bit];
			else sum -= key[bit];
		}
		if(sum % 360 == 0){
			flag = true;
			break;
		}
	}
	return flag;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n,temp;
	cin>>n;

	vector<int> key;

	for(int i=0;i<n;i++){
		cin>>temp;
		key.push_back(temp);
	}

	if(findIfCorrect(key,n))
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

}