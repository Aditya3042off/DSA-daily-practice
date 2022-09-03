#include <bits/stdc++.h>

using namespace std;

int shortPath

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	vector<vector<int>> maze;
	int rows = maze.size();
	int cols = maze[0].size();

	int dx[] = {1,-1,0,0};
	int dy[] = {0,0,1,-1};

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			if(maze[i][j] != 0) continue;

			for(int k = 0;k<4;k++){
				int newx = x + dx[k];
				int newy = y + dy[k];

				if(newx >= 0 and newy >=0 and newx < rows and newy < cols and maze[newx][newy] == 1)
					maze[newx][newy] = -1;
			}
			maze[x][y] = -1;
		}
	}


}