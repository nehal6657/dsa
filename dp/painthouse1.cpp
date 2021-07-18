#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
int paint(vector<vector<int>> &cost, int n){
    vector<vector<int>> dp(n, vector<int> (3));
    for(int i=0;i<n;i++){
        if(i==0) dp[i] = cost[i];
        else{
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][1],dp[i-1][0]) + cost[i][2];
        }

    }

    return min( min(dp[n-1][0],dp[n-1][1]), dp[n-1][2]);
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int> (3));
    for(int i=0;i<n;i++){
        int r,g,b;
        cin>>r>>g>>b;
        v[i][0] = r, v[i][1] = g, v[i][2] = b;
    } 
    cout<<paint(v,n)<<endl;
    

    return 0;
}