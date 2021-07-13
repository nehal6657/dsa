#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
int x = 0;

bool issfe(vector<vector<int> > &placed,int row,int col,int n){
    for(int j = row-1;j>=0;j--){
        if(placed[j][col]==1) return 0;
    }
    for(int i = row-1, j=col-1;i>=0 && j>=0;i--,j--){
        if(placed[i][j]==1) return 0;
        //if(placed[row-j][col+j]==1) return 0;
    }
    for(int i = row-1, j=col+1;i>=0 && j<n;i--,j++){
        if(placed[i][j]==1) return 0;
    }
    return 1;
}
void pnqueens(int n, string ans, int cnt, vector<vector<int> > &placed,int row){
    if(row == n){
        cout<<"x : "<<x<<"\n";
        for(int i=0;i<n;i++){
            {for(int j=0;j<n;j++)
                {cout<<placed[i][j]<<" ";}
            cout<<endl;
            }
        }
        x++;
        cout<<"\n";
        cout<<ans<<"\n";

        return;
    }


    for(int col = 0 ;col<n; col++){
        
          
            if(issfe(placed,row,col,n)==1){
                placed[row][col] = 1;
                string ans1= ans+ to_string(row)+to_string(col) + " ";
                pnqueens(n,ans1,cnt+1,placed,row+1);
                placed[row][col] = 0;
            }

        
    }
}


int main(){
    vector<vector<int>> placed( 4 , vector<int> (4, 0));
    pnqueens(4,"",0,placed,0);
    return 0;
}