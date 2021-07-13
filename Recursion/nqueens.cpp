#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
int x = 0;
vector<vector<string>> v1={};  
bool issfe(vector<string> &placed,int row,int col,int n){
    for(int j = row-1;j>=0;j--){
        if(placed[j][col]=='Q') return 0;
    }
    for(int i = row-1, j=col-1;i>=0 && j>=0;i--,j--){
        if(placed[i][j]=='Q') return 0;
        //if(placed[row-j][col+j]==1) return 0;
    }
    for(int i = row-1, j=col+1;i>=0 && j<n;i--,j++){
        if(placed[i][j]=='Q') return 0;
    }
    return 1;
}
void pnqueens(int n, string ans, int cnt, vector<string> &placed,int row){
    if(row == n){
        v1.push_back(placed);
        cout<<ans<<"\n";

        return;
    }


    for(int col = 0 ;col<n; col++){
        
          
            if(issfe(placed,row,col,n)==1){
                placed[row][col] = 'Q';
                string ans1= ans+ to_string(row)+to_string(col) + " ";
                pnqueens(n,ans1,cnt+1,placed,row+1);
                placed[row][col] = '.';
            }

        
    }
}


int main(){
    vector<string> placed;
    string s="....";
    for(int i=0;i<4;i++) placed.push_back(s);
    pnqueens(4,"",0,placed,0);
    return 0;
}