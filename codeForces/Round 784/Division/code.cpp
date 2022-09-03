#include <bits/stdc++.h>
using namespace std;

string findDivision(int& rating){
	string ans = "";

	if(rating <= 1399)
		ans =  "Division " + to_string(4);
	else if(rating <=1599)
		ans =  "Division " + to_string(3);
	else if(rating <= 1899)
		ans =  "Division " + to_string(2);
	else 
		ans =  "Division " + to_string(1); 
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int testcases;
	cin >> testcases;

	int rating;

	while(testcases--){
		cin>> rating;
		cout<< findDivision(rating)<<endl;
	}

}