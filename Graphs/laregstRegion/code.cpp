#include<bits/stdc++.h>
using namespace std;

struct node {
    int x;
    int y;
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
};

int travel(vector<vector<int>>& visited,vector<vector<int> > &matrix,int m,int n, int startx,int starty) {
    int dx[] = {-1,-1,-1, 0, 0,+1,+1,+1};
    int dy[] = { 0,-1,+1,-1,+1, 0,-1,+1};
    
    queue<node> q;
    q.push(node(startx,starty));
    visited[startx][starty] = 1;
    cout<<"parent -> "<<startx<<" "<<starty<<endl;

    int regionSize = 0; 
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        regionSize++;

        cout<<x<<" "<<y<<" "<<regionSize<<endl;
        
        for(int i=0;i<8;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            
            if(newx >=0 and newy >= 0 and newx < m and newy < n and visited[newx][newy] == 0 and matrix[newx][newy] == 1){
                q.push(node(newx,newy));
                visited[newx][newy] = 1;
            }
        }
    }
    return regionSize;   
}

int solve(vector<vector<int> > &matrix) {
    
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> visited(m,vector<int>(n,0));
    int ans = INT_MIN;
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 1 or matrix[i][j] == 0) continue;
            ans = max(ans,travel(visited,matrix,m,n,i,j));
        }
    }
    return ans;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	vector<vector<int>> matrix = {
		{0, 0, 1, 0, 0, 0, 0, 0},
  		{1, 1, 1, 1, 1, 1, 1, 0},
	};

	cout<<solve(matrix);
}
