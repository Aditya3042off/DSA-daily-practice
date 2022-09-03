#include<bits/stdc++.h>
using namespace std;

bool findPath(vector<vector<int>>& board,int x,int y,int count,int rows,int cols){
	int dx[8] = {-1,-1,1,1,-2,-2,2,2};
	int dy[8] = {2,-2,2,-2,1,-1,1,-1};

	board[x][y] = count;

	if(count == rows*cols-1)
		return true;

	for(int i=0;i<8;i++){
		int newx = x + dx[i];
		int newy = y + dy[i];

		if(newx <0 || newy < 0|| newx > rows-1 || newy > cols-1 || board[newx][newy] != -1) continue;

		if(findPath(board,newx,newy,count+1,rows,cols));
			return true; 
	}

	board[x][y] = -1;
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int rows = 8,cols = 8;

	vector<vector<int>> board(rows,vector<int>(cols,-1));
	findPath(board,0,0,1,rows,cols);

	for(auto row : board){
		for(int num : row) cout<<num<<" ";
		cout<<endl;
	}
	
}