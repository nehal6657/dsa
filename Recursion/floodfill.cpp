#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

void ppaths(vector<vector<int>> &maze, int row, int col, string path, vector<vector<int>> &visited){
    if(row == maze.size()-1 && col == maze[0].size()-1){
        cout<<path<<endl;
        return;
    }
    if(row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || maze[row][col]==1 || visited[row][col]==1){
        return;
    }
    visited[row][col] =1;
    ppaths(maze,row - 1,col,path + "t",visited);
    ppaths(maze,row,col-1,path + "l",visited);
    ppaths(maze,row + 1,col,path + "d",visited);
    ppaths(maze,row ,col + 1,path + "r",visited);
    visited[row][col] = 0;

}


int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> arr(n, vector < int > (m));
    vector < vector < int >> visited(n, vector < int > (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            visited[i][j]=0;
        }
    }


    ppaths(arr,0,0,"",visited);
    return 0;
}