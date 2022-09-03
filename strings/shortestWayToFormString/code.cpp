// https://www.youtube.com/watch?v=evesA3gr9BE&t=46s

#include<bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

		string source,target;
		cin>>source;
		cin>>target;

		int numSubsequences = 0;

		string remaining = target;
		int i,j;
		while(remaining.length() > 0){
			
			i = j = 0;

			while(i < source.size() and j < remaining.size()){
				if(source[i++] == remaining[j]) j++;
			}
			// even the first character is not found that means this character is not present in source
			// so we return -1;
			if(j == 0){
				numSubsequences = -1;
				break;
			};
			remaining = remaining.substr(j);
			numSubsequences++; 
		}
		cout<<numSubsequences;
}