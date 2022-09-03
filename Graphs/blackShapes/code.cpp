#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int y;
    node(int _x,int _y){
        x = _x;
        y = _y;
    }
};

void attachX(int startx,int starty,int visited[],vector<string> &matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    
    int dx[] = {-1,+1,0,0};
    int dy[] = {0,0,+1,-1};
    
    queue<node> q;
    q.push(node(startx,starty));
    visited[startx*m + starty] = 1;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            
            if(newx >= 0 and newy >=0 and newx < m and newy < n and matrix[newx][newy] == 'X' and visited[newx*m + newy] == 0){
                visited[newx*m + newy] = 1;
                q.push(node(newx,newy));
            }
        }
    }
    
}

int black(vector<string> &matrix) {
    int numShapes = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int visited[m*n] = {0};
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i*m + j] == 1 or matrix[i][j] == 'O') continue;
            numShapes++;
            attachX(i,j,visited,matrix);
        }
    }
    return numShapes;
}


int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	vector<string> matrix = { "XOOOOOXXOX", "OOXXXXOOXX", "XXOXXOOXXO", "OXOXXXXXXO", "XOXXOXOXXX", "OOOOOOOXOO", "XOXXXOOXOX", "XXXOXOXXXO" };

	cout<<black(matrix);

}