#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<char>>& matrix,int rows,int cols){
	for(int i = rows-2;i>=0;i--){
		for(int j=cols-1;j>=0;j--){
			if(matrix[i][j] != '*') continue;

			while(i+1 < rows and matrix[i+1][j] == '.'){
				matrix[i][j] = '.';
				matrix[i+1][j] = '*';
				i++;
			}
		}
	}
	return;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int testcases,temp;
	cin>>testcases;
	int rows,cols;

	while(testcases--){
		cin>>rows>>cols;
		vector<vector<char>> matrix(rows,vector<char>(cols,'.'));

		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cin>> temp;
				matrix[i][j] = temp;
			}
		}
		solve(matrix,rows,cols);

		for(int i=0;i<rows;i++){
			for(int j=0;j<cols;j++){
				cout<<(char)matrix[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}