#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;

void knight(vector<vector<int>> &chess, int row, int col, string ans,int cnt){
    int n = chess.size();
    if(row>=n ||col>=n||row<0||col<0 || chess[row][col]>0){
        return;
    }
    else if(cnt==n*n){
        chess[row][col] = cnt;

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                cout<<chess[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    else if(cnt<n*n && chess[row][col]==0){
        chess[row][col]=cnt;
        knight(chess,row-1,col+2,ans,cnt+1);
        knight(chess,row-2,col+1,ans,cnt+1);
        knight(chess,row-2,col-1,ans,cnt+1);
        knight(chess,row-1,col-2,ans,cnt+1);
        knight(chess,row+1,col-2,ans,cnt+1);
        knight(chess,row+2,col-1,ans,cnt+1);
        knight(chess,row+2,col+1,ans,cnt+1);
        knight(chess,row+1,col+2,ans,cnt+1);
        
        chess[row][col]=0;
    }

}

int main(){
    int n=5;
    vector<vector<int>> chess( n , vector<int> (n, 0));
    knight(chess,2,0,"",1);
    return 0;
}