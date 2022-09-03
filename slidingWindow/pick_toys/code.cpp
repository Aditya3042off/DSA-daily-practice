#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	map<int,int> m;
	m[1]++;
	m[2]++;
	m[1]++;
	cout<<m.size()<<endl;
	m[2]--;
	cout<<m.size()<<endl;

}