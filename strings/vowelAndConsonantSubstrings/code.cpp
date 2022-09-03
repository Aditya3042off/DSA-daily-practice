#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

//can be optimised by removing vdp,cdp and using 2 variables instaed of them


unordered_map<char,int> makeVowelMap() {
    unordered_map<char,int> vowelSet;
    vowelSet['a']=1;
    vowelSet['e']=1;
    vowelSet['i']=1;
    vowelSet['o']=1;
    vowelSet['u']=1;
    
    return vowelSet;
}

int solve(string str) {
    
    unordered_map<char,int> vowelMap = makeVowelMap();
    int size = str.size();
    
    vector<int> vcount,ccount;
    int vCount = 0,cCount = 0;
    for(int i=0;i<size;i++){
        vCount += vowelMap[str[i]];
        cCount += 1 - vowelMap[str[i]];
        vcount.push_back(vCount);
        ccount.push_back(cCount);
    }
   
    vector<int> vdp(size,0),cdp(size,0);
    
    for(int i=1;i<size;i++){
        vdp[i] = vdp[i-1];
        if(vowelMap[str[i]] == 0) vdp[i] = ((vdp[i] + vcount[i-1]) % mod);
    }
    
    for(int i=1;i<size;i++){
        cdp[i] = cdp[i-1];
        if(vowelMap[str[i]] == 1) cdp[i] = ((cdp[i] + ccount[i-1])%mod) ;
    }
    
    return (vdp[size-1] + cdp[size-1]) % (int)mod;
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string str = "a";
    int ans = solve(str);
    cout<<ans;
}