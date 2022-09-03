#include<bits/stdc++.h>
using namespace std;

vector<string> computePrev(string&s){
	vector<string> ans;
	int n = s.size();
	string temp = "";

	for(int i=0;i<n;i++){
		int count = 1;
		while(i<n and s[i] == s[i+1]) {i++;count++;}
		if(count == 1) temp += s[i];
		else temp += to_string(count) + s[i];
		ans.push_back(temp);
	}

	return ans;
}

vector<string> computeNext(string&s){
	vector<string> ans;
	int n = s.size();
	string temp = "";

	for(int i=n-1;i>=0;i--){
		int count = 1;
		while(i>0 and s[i] == s[i-1]) {i--;count++;}
		if(count == 1) temp = s[i] + temp;
		else temp = to_string(count) + s[i] + temp;
		ans.push_back(temp);
	}

	return ans;
}

int solution(string& s,int k){
	int n = s.size();

	vector<string> prev;
	vector<string> next;

	prev = computePrev(s);
	next = computeNext(s);

	int ans = INT_MAX;

	for(int i=0;i<=n-k;i++){

		if(i==0){
			ans = min(ans,(int)next[i+k].length());
			continue;
		}

		if(i==n-k){
			ans = min(ans,(int)next[i-1].length());
			continue;
		}

		int prevsize = prev[i-1].length();
		int nextsize = next[i+k].length();

		if(s[i-1] == s[i+k]){
			int count1 = 1;
			int count2 = 1;

			int j = i-1;
			while(j > 0 and s[j] == s[j-1]) {j--;count1++;}
			int itr = i+k;
			while(itr < n and s[itr] == s[itr+1]) {itr++;count2++;}

			if(count1==1 and count2==1) ans = min(ans,prevsize+nextsize);
			else if(count1==1 or count2==1) ans = min(ans,prevsize+nextsize);
			else ans = min(ans,prevsize+nextsize-2);
		}

		ans = min(ans,prevsize+nextsize);
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	string s;
	int k;

	cin>>s;
	cin>>k;

	cout<<solution(s,k);

}