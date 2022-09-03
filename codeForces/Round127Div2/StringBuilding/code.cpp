#include<bits/stdc++.h>
using namespace std;

bool findIsPossible(string str){
	int count = 0;
	int n = str.size();
	int i = 0;

	while(i <= n-1){
		while(i <= n-2 and str[i] == str[i+1]){
			count++;
			i++;
		}
		count++;

		if(count % 2 != 0 and count % 3 != 0 and count % 5 != 0)
			return false;
		count = 0;
		i++;
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

	vector<string> inputs;
	string temp;

	for(int i=0;i<testcases;i++){
		cin>>temp;
		inputs.push_back(temp);
	}

	for(int i=0;i<testcases;i++){
		if(findIsPossible(inputs[i]))
			cout<<"YES"<<endl;
		else{
			cout<<"NO"<<endl;
		}
	}


}