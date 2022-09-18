// https://www.geeksforgeeks.org/fitting-shelves-problem/

#include<bits/stdc++.h>
using namespace std;

pair<int,int> solve(int w,int small,int large) {

    int maxSmall,maxLarge;
    maxSmall = maxLarge = INT_MIN;
    int smallestLeft = INT_MAX;

    int x = w / large;

    for(int i = x;i>=0;i--){
        int left = w - (i * large);
        int leftAfterSmall = left - ((left / small) * small);

        if(leftAfterSmall == 0) 
        {
            if(smallestLeft != 0) {
                maxSmall = left/small;
                maxLarge = i;
            }
            else {
                if(maxLarge > i) continue;
                maxSmall = left/small;
                maxLarge = i;
            }
            smallestLeft = 0;
        } 

        if(leftAfterSmall < smallestLeft) {
            maxSmall = left / small;
            maxLarge = i;
            smallestLeft = leftAfterSmall;
        }
    }

    return {maxSmall,maxLarge};
}

int main(){
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

    int w = 76;
    int small = 1;
    int large = 10;

    pair<int,int> p = solve(w,small,large);

    cout<< p.first << " " << p.second << " " << w - ((small * p.first) + (large * p.second));
}