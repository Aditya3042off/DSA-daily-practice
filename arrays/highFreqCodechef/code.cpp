#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int n){
    unordered_map<int,int> ump;
    
    int highestFreq,secondHighestFreq;
    highestFreq = secondHighestFreq = 0;
    
    for(int i : arr) ump[i]++;
    
    for(auto pair : ump){
        if(pair.second > highestFreq){
            secondHighestFreq = highestFreq;
            highestFreq = pair.second;
        }
        else if(pair.second > secondHighestFreq){
            secondHighestFreq = pair.second;
        }
    }

    return max(secondHighestFreq,(highestFreq/2) + (highestFreq % 2));
    
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    // your code goes here
    int t,n;
    cin>>t;
    
    while(t--){
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        
        cout<<solve(arr,n)<<endl;
    }
}

