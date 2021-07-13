#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    int n = 9;
    vector<vector<char>> ans;
    bool check(vector<vector<char>> &board, int row, int col, int key){
        char x =  to_string(key)[0];
        //cout<<"reshu : "<<x<<endl;

        //checking in row 
        
        for(int j1=0;j1<n;j1++){
            if(board[row][j1]==x) return 0;
        }
        //checking in col 
        for(int j1=0;j1<n;j1++){
            if(board[j1][col]==x) return 0;
        }
        //checking in small box
        int x0 = (row/3);
        x0 *= 3;
        int x1 = col/3;
        x1 *= 3;
        for(int i1=x0;i1<x0+3;i1++){
            for(int j1=x1;j1<x1+3;j1++){
                if(board[i1][j1]==x) return 0;
            }
        }
        return 1;

    }
    void printt(vector<vector<char>> &board){
    for(int i = 0; i<9;i++){
        for(int j =0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
    void sudoku(vector<vector<char>> &board, int row, int col){
        if(row == 9){
            printt(board);
            ans=board;
            printt(ans);
            return;
        }
        int nr,nc;
        if(col==8){
            nr=row+1;
            nc=0;
        }
        else{
            nr=row; nc = col+1;
        }

        if(board[row][col]!='.'){
            sudoku(board,nr,nc);
        }
        else{
            for(int i = 1;i<=9;i++){
                if(board[row][col]=='.' && check(board,row,col,i)==1){
                    board[row][col] = to_string(i)[0];
                    //cout<<"nehal : "<<to_string(i)[0]<<endl;
                    sudoku(board,nr,nc);
                    board[row][col]='.';
                }
            }

        }




    }

    void solveSudoku(vector<vector<char>>& board) {
        ans.clear();
        sudoku(board,0,0);
        board = ans;
        
        
    }
    int main() {
    int n, m;
    n=9,m=9;
    vector < vector < char >> arr(n, vector < char > (m));
    vector < vector < char >> visited(n, vector < char > (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    sudoku(arr,0,0);

    return 0;
}